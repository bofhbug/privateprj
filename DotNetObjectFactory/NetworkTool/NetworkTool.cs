using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace NetworkTool
{
    [ComVisible(true)]
    [ClassInterface(ClassInterfaceType.AutoDispatch)]
    public class NetworkTool
    {
        public void WriteTo(string message)
        {
            Debug.Print(string.Format("Message From Sample Dot NET Object : {0}", message));
        }
    }
}
