#pragma once

#include <msclr/marshal.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Reflection;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace NetworkTool{
    namespace DotNetObjectFactory{

        /// <summary>
        /// Summary for DotNetObjectFactoryNet
        /// </summary>
		private ref class DotNetObjectFactoryNet
        {
		private:
			ref struct NetObject
			{
				IntPtr DispatchPtr;
				Object^ NetObj;
			};
        private:
            static DotNetObjectFactoryNet^ m_inst = nullptr;
			List<NetObject^>^ m_cachedObjects;
        public:
			DotNetObjectFactoryNet(void);
            ~DotNetObjectFactoryNet();

            static property DotNetObjectFactoryNet^ Inst{
				DotNetObjectFactoryNet^ get(){
                    if (m_inst == nullptr)
                    {
                        m_inst = gcnew DotNetObjectFactoryNet ();
                    }

                    return m_inst;
                }
            }
            IntPtr GetNetObject(System::String^ fileName, System::String^ className);
			System::String^ ResolvePath(System::String^ fileName);
			void Quit();
        };
    }
}