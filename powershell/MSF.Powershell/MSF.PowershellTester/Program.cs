﻿using MSF.Powershell;
using MSF.Powershell.Meterpreter;
using System;
using System.Collections.Generic;
using System.Text;

namespace MSF.PowershellTester
{
    class Program
    {
        static void Main(string[] args)
        {
            //var x = MSF.Powershell.Runner.Get("Default");
            //System.Console.Write(x.Execute("$x = $(whoami)"));
            //System.Console.Write(x.Execute("$x"));
            //MSF.Powershell.Runner.Remove("Default");

            Tlv t = new Tlv();
            var x = t.ToRequest(PacketMethod.StdapiSysConfigGetuid);
        }
    }
}
