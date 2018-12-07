#pragma once

#include "stdafx.h"

#include <string>
#include <atlbase.h>


// CDotNetObjectFactory
#define MaxBuffSize 32768

typedef HRESULT(*DllGetClassObjectPtr)(REFCLSID rclsid, REFIID   riid, LPVOID   *ppv);

class CCreateComObject
{
public:
	CCreateComObject();
	~CCreateComObject();
	HRESULT CreateComObject(std::string& filePath, std::string& className, IDispatch** pRetVal);
private:
	//HRESULT CreateDispatch(ATL::CComPtr<ITypeLib>& typeLib, ATL::CComBSTR& interfaceName, IUnknown* pIn, IUnknown** pOut);
	std::string ResolvePath(std::string& filePath);
};
