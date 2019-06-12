package com.metasploit.meterpreter;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import com.metasploit.meterpreter.command.Command;
import com.metasploit.meterpreter.command.NotYetImplementedCommand;
import com.metasploit.meterpreter.command.UnsupportedJavaVersionCommand;

/**
 * A registry for supported commands. Extensions will register their commands here.
 *
 * @author mihi
 */
public class CommandManager {

    private final int javaVersion;
    private Map<String, Vector<PacketMethod>> registeredCommands = new HashMap<String, Vector<PacketMethod>>();
    private Map<PacketMethod, Command> commandMap = new HashMap<PacketMethod, Command>();

    protected CommandManager() throws Exception {
        // get the API version, which might be different from the
        // VM version, especially on some application servers
        // (adapted from org.apache.tools.ant.util.JavaEnvUtils).
        Class.forName("java.lang.Void");
        Class.forName("java.lang.ThreadLocal");
        int apiVersion = ExtensionLoader.V1_2;
        try {
            Class.forName("java.lang.StrictMath");
            apiVersion = ExtensionLoader.V1_3;
            Class.forName("java.lang.CharSequence");
            apiVersion = ExtensionLoader.V1_4;
            Class.forName("java.net.Proxy");
            apiVersion = ExtensionLoader.V1_5;
            Class.forName("java.util.ServiceLoader");
            apiVersion = ExtensionLoader.V1_6;
        } catch (Throwable t) {
        }
        String javaversion = System.getProperty("java.version");
        if (javaversion != null && javaversion.length() > 2) {
            int vmVersion = javaversion.charAt(2) - '2' + ExtensionLoader.V1_2;
            if (vmVersion >= ExtensionLoader.V1_2 && vmVersion < apiVersion) {
                apiVersion = vmVersion;
            }
        }
        this.javaVersion = apiVersion;

        // load core commands
        new com.metasploit.meterpreter.core.Loader().load(this);
    }

    /**
     * Register a command that can be executed on all Java versions (from 1.2 onward)
     *
     * @param extName      Name of the extension containing the command.
     * @param command      ID of the command
     * @param commandClass Class that implements the command
     */
    public void registerCommand(String extName, PacketMethod command, Class commandClass) throws Exception {
        registerCommand(extName, command, commandClass, ExtensionLoader.V1_2);
    }

    /**
     * Register a command that can be executed only on some Java versions
     *
     * @param extName      Name of the extension containing the command.
     * @param command      ID of the command
     * @param commandClass Stub class for generating the class name that implements the command
     * @param version      Minimum Java version
     */
    public void registerCommand(String extName, PacketMethod command, Class commandClass, int version) throws Exception {
        registerCommand(extName, command, commandClass, version, version);
    }

    /**
     * Register a command that can be executed only on some Java versions, and has two different implementations for different Java versions.
     *
     * @param extName      Name of the extension containing the command.
     * @param command      ID of the command
     * @param commandClass  Stub class for generating the class name that implements the command
     * @param version       Minimum Java version
     * @param secondVersion Minimum Java version for the second implementation
     */
    public void registerCommand(String extName, PacketMethod command, Class commandClass, int version, int secondVersion) throws Exception {
        if (secondVersion < version) {
            throw new IllegalArgumentException("secondVersion must be larger than version");
        }

        if (registeredCommands.get(extName) == null) {
            registeredCommands.put(extName, new Vector<PacketMethod>());
        }
        registeredCommands.get(extName).add(command);

        if (javaVersion < version) {
            commandMap.put(command, new UnsupportedJavaVersionCommand(command, version));
            return;
        }

        if (javaVersion >= secondVersion) {
            version = secondVersion;
        }

        if (version != ExtensionLoader.V1_2) {
            commandClass = commandClass.getClassLoader().loadClass(commandClass.getName() + "_V1_" + (version - 10));
        }

        Command cmd = (Command) commandClass.newInstance();
        commandMap.put(command, cmd);
    }

    /**
     * Get a command for the given name.
     */
    public Command getCommand(PacketMethod method) {
        Command cmd = (Command) commandMap.get(method);
        if (cmd == null) {
            cmd = NotYetImplementedCommand.INSTANCE;
        }
        return cmd;
    }

    public int executeCommand(Meterpreter met, TLVPacket request, TLVPacket response) throws IOException {
        PacketMethod method = PacketMethod.fromId(request.getIntValue(TLVType.TLV_TYPE_METHOD_ID));
        Command cmd = this.getCommand(method);

        int result;
        try {
            result = cmd.execute(met, request, response);
        } catch (Throwable t) {
            t.printStackTrace(met.getErrorStream());
            result = Command.ERROR_FAILURE;
        }

        if (result == Command.EXIT_DISPATCH) {
            response.add(TLVType.TLV_TYPE_RESULT, Command.ERROR_SUCCESS);
        } else {
            response.add(TLVType.TLV_TYPE_RESULT, result);
        }

        return result;
    }

    ///**
    // * Retrieves the list of commands loaded by the last core_loadlib call
    // */
    //public PacketMethod[] getNewCommands() {
    //    return (PacketMethod[]) newCommands.toArray(new PacketMethod[newCommands.size()]);
    //}

    ///**
    // * Retrieves the list of commands for a given extension
    // */
    public PacketMethod[] getCommands(String extName) {
        return (PacketMethod[]) registeredCommands.get(extName).toArray();
    }
}
