/*
 * This module implemenet webcam frae capture and mic recording features. 
 */
#define _CRT_SECURE_NO_DEPRECATE 1
#include "../../common/common.h"
#include "espia.h"
#include "audio.h"
#include "video.h"
#include "screen.h"

#include "../../DelayLoadMetSrv/DelayLoadMetSrv.h"
// include the Reflectiveloader() function, we end up linking back to the metsrv.dll's Init function
// but this doesnt matter as we wont ever call DLL_METASPLOIT_ATTACH as that is only used by the 
// second stage reflective dll inject payload and not the metsrv itself when it loads extensions.
#include "../../ReflectiveDLLInjection/dll/src/ReflectiveLoader.c"

// NOTE: _CRT_SECURE_NO_WARNINGS has been added to Configuration->C/C++->Preprocessor->Preprocessor

#define ESPIA_AUDIO_GET_DEV_AUDIO 10000
#define ESPIA_IMAGE_GET_DEV_SCREEN 10001
#define ESPIA_VIDEO_GET_DEV_IMAGE 10002

// this sets the delay load hook function, see DelayLoadMetSrv.h
EnableDelayLoadMetSrv();

Command customCommands[] =
{
	COMMAND_REQ(ESPIA_VIDEO_GET_DEV_IMAGE, request_video_get_dev_image),
	COMMAND_REQ(ESPIA_AUDIO_GET_DEV_AUDIO, request_audio_get_dev_audio),
	COMMAND_REQ(ESPIA_IMAGE_GET_DEV_SCREEN, request_image_get_dev_screen),
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

	command_register_all( customCommands );

	return ERROR_SUCCESS;
}

/*!
 * @brief Deinitialize the server extension.
 * @param remote Pointer to the remote instance.
 * @return Indication of success or failure.
 */
DWORD __declspec(dllexport) DeinitServerExtension(Remote *remote)
{
	command_deregister_all( customCommands );

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
	strncpy_s(buffer, bufferSize, "espia", bufferSize - 1);
	return ERROR_SUCCESS;
}
