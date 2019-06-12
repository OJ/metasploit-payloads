package com.metasploit.meterpreter.stdapi;

import java.io.File;

import com.metasploit.meterpreter.PacketMethod;
import com.metasploit.meterpreter.CommandManager;
import com.metasploit.meterpreter.ExtensionLoader;

/**
 * Loader class to register all the stdapi commands.
 *
 * @author mihi
 */
public class Loader implements ExtensionLoader {

    private static final extName = "stdapi";

    public static File cwd;

    public static File expand(String path) {
        File result = new File(path);
        if (!result.isAbsolute())
            result = new File(cwd, path);
        return result;
    }

    public PacketMethod[] load(CommandManager mgr) throws Exception {
        cwd = new File(".").getCanonicalFile();
        mgr.registerCommand(extName, PacketMethod.CHANNEL_CREATE_STDAPI_FS_FILE, channel_create_stdapi_fs_file.class);
        mgr.registerCommand(extName, PacketMethod.CHANNEL_CREATE_STDAPI_NET_TCP_CLIENT, channel_create_stdapi_net_tcp_client.class);
        mgr.registerCommand(extName, PacketMethod.CHANNEL_CREATE_STDAPI_NET_TCP_SERVER, channel_create_stdapi_net_tcp_server.class);
        mgr.registerCommand(extName, PacketMethod.CHANNEL_CREATE_STDAPI_NET_UDP_CLIENT, channel_create_stdapi_net_udp_client.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_CHDIR, stdapi_fs_chdir.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_DELETE_DIR, stdapi_fs_delete_dir.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_DELETE_FILE, stdapi_fs_delete_file.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_FILE_EXPAND_PATH, stdapi_fs_file_expand_path.class, V1_2, V1_5); // %COMSPEC% only
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_FILE_MOVE, stdapi_fs_file_move.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_FILE_COPY, stdapi_fs_file_copy.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_GETWD, stdapi_fs_getwd.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_LS, stdapi_fs_ls.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_MKDIR, stdapi_fs_mkdir.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_MD5, stdapi_fs_md5.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_SEARCH, stdapi_fs_search.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_SEPARATOR, stdapi_fs_separator.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_STAT, stdapi_fs_stat.class, V1_2, V1_6);
        mgr.registerCommand(extName, PacketMethod.STDAPI_FS_SHA1, stdapi_fs_sha1.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_NET_CONFIG_GET_INTERFACES, stdapi_net_config_get_interfaces.class, V1_4, V1_6);
        mgr.registerCommand(extName, PacketMethod.STDAPI_NET_CONFIG_GET_ROUTES, stdapi_net_config_get_routes.class, V1_4);
        mgr.registerCommand(extName, PacketMethod.STDAPI_NET_SOCKET_TCP_SHUTDOWN, stdapi_net_socket_tcp_shutdown.class, V1_2, V1_3);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_CONFIG_GETUID, stdapi_sys_config_getuid.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_CONFIG_GETENV, stdapi_sys_config_getenv.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_CONFIG_SYSINFO, stdapi_sys_config_sysinfo.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_CONFIG_LOCALTIME, stdapi_sys_config_localtime.class);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_PROCESS_EXECUTE, stdapi_sys_process_execute.class, V1_2, V1_3);
        mgr.registerCommand(extName, PacketMethod.STDAPI_SYS_PROCESS_GET_PROCESSES, stdapi_sys_process_get_processes.class, V1_2);
        mgr.registerCommand(extName, PacketMethod.STDAPI_UI_DESKTOP_SCREENSHOT, stdapi_ui_desktop_screenshot.class, V1_4);
        mgr.registerCommand(extName, PacketMethod.STDAPI_WEBCAM_AUDIO_RECORD, webcam_audio_record.class, V1_4);
        return mgr.getCommands(extName);
    }
}
