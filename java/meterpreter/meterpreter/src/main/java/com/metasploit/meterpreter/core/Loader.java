package com.metasploit.meterpreter.core;

import com.metasploit.meterpreter.PacketMethod;
import com.metasploit.meterpreter.CommandManager;
import com.metasploit.meterpreter.ExtensionLoader;

/**
 * Loader class to register all the core commands.
 *
 * @author mihi
 */
public class Loader implements ExtensionLoader {
    private static final String extName = "";

    public PacketMethod[] load(CommandManager mgr) throws Exception {
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_CLOSE, core_channel_close.class);
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_EOF, core_channel_eof.class);
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_INTERACT, core_channel_interact.class);
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_OPEN, core_channel_open.class);
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_READ, core_channel_read.class);
        mgr.registerCommand(extName, PacketMethod.CORE_CHANNEL_WRITE, core_channel_write.class);
        mgr.registerCommand(extName, PacketMethod.CORE_ENUMEXTCMD, core_enumextcmd.class);
        mgr.registerCommand(extName, PacketMethod.CORE_LOADLIB, core_loadlib.class);
        mgr.registerCommand(extName, PacketMethod.CORE_SET_UUID, core_set_uuid.class);
        mgr.registerCommand(extName, PacketMethod.CORE_MACHINE_ID, core_machine_id.class);
        mgr.registerCommand(extName, PacketMethod.CORE_GET_SESSION_GUID, core_get_session_guid.class);
        mgr.registerCommand(extName, PacketMethod.CORE_SET_SESSION_GUID, core_set_session_guid.class);
        mgr.registerCommand(extName, PacketMethod.CORE_PATCH_URL, core_patch_url.class);
        mgr.registerCommand(extName, PacketMethod.CORE_SHUTDOWN, core_shutdown.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_SET_TIMEOUTS, core_transport_set_timeouts.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_LIST, core_transport_list.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_ADD, core_transport_add.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_CHANGE, core_transport_change.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_SLEEP, core_transport_sleep.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_NEXT, core_transport_next.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_PREV, core_transport_prev.class);
        mgr.registerCommand(extName, PacketMethod.CORE_TRANSPORT_REMOVE, core_transport_remove.class);

        return mgr.getCommands(extName);
    }
}
