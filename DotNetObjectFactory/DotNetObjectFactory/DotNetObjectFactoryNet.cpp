#include "DotNetObjectFactoryNet.h"
#include "DotNetObjectFactoryMixed.h"

[assembly:AssemblyKeyFileAttribute("DotNetObjectFactory.snk")];

namespace NetworkTool
{
    namespace DotNetObjectFactory
	{
		DotNetObjectFactoryNet::DotNetObjectFactoryNet(void)
        {
			m_cachedObjects = gcnew List<NetObject^>();
        }
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
		DotNetObjectFactoryNet::~DotNetObjectFactoryNet()
        {

        }

		System::String^ DotNetObjectFactoryNet::ResolvePath(System::String^ fileName)
		{
			System::String^ retVal = System::String::Empty;
			if (String::IsNullOrEmpty(fileName))
			{
				return retVal;
			}

			String^ expandedFilePath = Environment::ExpandEnvironmentVariables(fileName);
			if (File::Exists(expandedFilePath))
			{
				retVal = expandedFilePath;
			}
			else
			{
				String^ tempPath = Path::GetFullPath(expandedFilePath);
				if (File::Exists(tempPath))
				{
					retVal = tempPath;
				}
			}

			if (File::Exists(retVal))
			{
				return retVal;
			}
			else
			{
				return System::String::Empty;
			}
		}
        IntPtr DotNetObjectFactoryNet::GetNetObject(System::String^ fileName, System::String^ className)
        {
            IntPtr retVal = IntPtr::Zero;

            if (String::IsNullOrEmpty(className))
            {
                return retVal;
            }

			if (String::IsNullOrEmpty(fileName))
			{
				return retVal;
			}

			String^ expandedFilePath = Environment::ExpandEnvironmentVariables(fileName);

			String^ fullPath = "";

			if (File::Exists(expandedFilePath))
			{
				fullPath = expandedFilePath;
			}
			else
			{
				String^ tempPath = Path::GetFullPath(expandedFilePath);

				if (File::Exists(tempPath))
				{
					fullPath = tempPath;
				}
			}
			if (!File::Exists(fullPath))
			{
				return retVal;
			}

			Assembly^ netAssembly;
			netAssembly = Assembly::LoadFrom(fullPath);

			for each (Type^ item in netAssembly->GetTypes())
			{
				if (item->Name == className)
				{
					Object^ tempObj = Activator::CreateInstance(item);
					IntPtr tempDispatch = Marshal::GetIDispatchForObject(tempObj);
					NetObject^ tempObjEntry = gcnew NetObject;
					tempObjEntry->DispatchPtr = tempDispatch;
					tempObjEntry->NetObj = tempObj;
					m_cachedObjects->Add(tempObjEntry);
					retVal = tempDispatch;
					break;
				}
			}
			return retVal;
        }

		void DotNetObjectFactoryNet::Quit()
		{
			for each (NetObject^ item in m_cachedObjects)
			{
				Marshal::Release(item->DispatchPtr);
			}
			m_cachedObjects->Clear();
		}
    }
}

IDispatch* DotNetObjectFactoryMixed::GetNetObject(BSTR filePath, BSTR className)
{
    System::String^ clrFilePath = msclr::interop::marshal_as<System::String ^>(filePath);
    System::String^ clrclassName = msclr::interop::marshal_as<System::String ^>(className);
    void* retVal = (void*)NetworkTool::DotNetObjectFactory::DotNetObjectFactoryNet::Inst->GetNetObject(clrFilePath, clrclassName);
    return reinterpret_cast<IDispatch*>(retVal);
}
void DotNetObjectFactoryMixed::Quit()
{
	NetworkTool::DotNetObjectFactory::DotNetObjectFactoryNet::Inst->Quit();
}