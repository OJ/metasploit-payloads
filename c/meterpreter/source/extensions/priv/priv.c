/*!
 * @brief This module implements privilege escalation features.
 */
#include "precomp.h"
#include "common_metapi.h" 

// Required so that use of the API works.
MetApi* met_api = NULL;

#define RDIDLL_NOEXPORT
#include "../../ReflectiveDLLInjection/dll/src/ReflectiveLoader.c"

/*!
 * @brief `priv` extension dispatch table.
 */
Command customCommands[] =
{
	COMMAND_REQ( "priv_elevate_getsystem", elevate_getsystem ),
	COMMAND_REQ( "priv_passwd_get_sam_hashes", request_passwd_get_sam_hashes ),
	COMMAND_REQ( "priv_fs_get_file_mace", request_fs_get_file_mace ),
	COMMAND_REQ( "priv_fs_set_file_mace", request_fs_set_file_mace ),
	COMMAND_REQ( "priv_fs_set_file_mace_from_file", request_fs_set_file_mace_from_file ),
	COMMAND_REQ( "priv_fs_blank_file_mace", request_fs_blank_file_mace ),
	COMMAND_REQ( "priv_fs_blank_directory_mace", request_fs_blank_directory_mace ),
	COMMAND_TERMINATOR
};

/*!
 * @brief Initialize the server extension.
 * @param api Pointer to the Meterpreter API structure.
 * @param remote Pointer to the remote instance.
 * @return Indication of success or failure.
 */
DWORD InitServerExtension(MetApi* api, Remote* remote)
{
    met_api = api;

    met_api->command.register_all(customCommands);

    return ERROR_SUCCESS;
}

/*!
 * @brief Deinitialize the server extension.
 * @param remote Pointer to the remote instance.
 * @return Indication of success or failure.
 */
DWORD DeinitServerExtension(Remote* remote)
{
    met_api->command.deregister_all(customCommands);

    return ERROR_SUCCESS;
}


/*!
 * @brief Get the name of the extension.
 * @param buffer Pointer to the buffer to write the name to.
 * @param bufferSize Size of the \c buffer parameter.
 * @return Indication of success or failure.
 */
DWORD GetExtensionName(char* buffer, int bufferSize)
{
	strncpy_s(buffer, bufferSize, "priv", bufferSize - 1);
	return ERROR_SUCCESS;
}

/*!
 * @brief Do a stageless initialisation of the extension.
 * @param buffer Pointer to the buffer that contains the init data.
 * @param bufferSize Size of the \c buffer parameter.
 * @return Indication of success or failure.
 */
DWORD StagelessInit(const LPBYTE buffer, DWORD bufferSize)
{
    return ERROR_SUCCESS;
}

/*!
 * @brief Callback for when a command has been added to the meterpreter instance.
 * @param commandName The name of the command that has been added.
 */
VOID CommandAdded(const char* commandName)
{
}
