#include "stdafx.h"
#include "CreateComObject.h"
#include <comutil.h>

#include <memory>
using namespace std;

CCreateComObject::CCreateComObject()
{
}

CCreateComObject::~CCreateComObject()
{
}

//HRESULT CCreateComObject::CreateDispatch(CComPtr<ITypeLib>& typeLib, CComBSTR& interfaceName, IUnknown* pIn, IUnknown** pOut)
//{
//	HRESULT hr = S_OK;
//	MEMBERID memId = 0;
//	USHORT pcFound = 1;
//	CComPtr<ITypeInfo> typeInfoHdw;
//	TYPEATTR* pTypeAttr;
//
//	hr = typeLib->FindName(interfaceName, 0, &typeInfoHdw, &memId, &pcFound);
//	if (hr != S_OK)
//	{
//		return hr;
//	}
//
//	hr = typeInfoHdw->GetTypeAttr(&pTypeAttr);
//	if (hr != S_OK)
//	{
//		return hr;
//	}
//	TYPEKIND typeKind = pTypeAttr->typekind;
//
//	typeInfoHdw->ReleaseTypeAttr(pTypeAttr);
//	if (typeKind != TKIND_INTERFACE && typeKind != TKIND_DISPATCH)
//	{
//		return hr;
//	}
//
//	CComPtr<IUnknown> pRet;
//	hr = CreateStdDispatch(NULL, pIn, typeInfoHdw, &pRet);
//	if (hr != S_OK)
//	{
//		return hr;
//	}
//
//	*pOut = pRet.Detach();
//	return hr;
//}


HRESULT CCreateComObject::CreateComObject(std::string& filePath, std::string& className, IDispatch** pRetVal)
{
	HRESULT hr = S_OK;
	{
		string fullPath = ResolvePath(filePath);
		CComBSTR fullPathBSTR = fullPath.c_str();
		CComPtr<ITypeLib> loadLib;
		hr = LoadTypeLib(fullPathBSTR, &loadLib);
		if (FAILED(hr))
		{
			return hr;
		}

		CComBSTR classNameBSTR = className.c_str();
		CComPtr<ITypeInfo> typeInfo;
		MEMBERID memberRID = 0;
		USHORT cFound = 1;

		hr = loadLib->FindName(classNameBSTR, 0, &typeInfo, &memberRID, &cFound);
		if (FAILED(hr))
		{
			return hr;
		}
		TYPEATTR *pTypeAttr;
		hr = typeInfo->GetTypeAttr(&pTypeAttr);
		if (FAILED(hr))
		{
			return hr;
		}
		if (pTypeAttr->typekind != TKIND_COCLASS)
		{
			typeInfo->ReleaseTypeAttr(pTypeAttr);
			return hr;
		}
		GUID clsid = pTypeAttr->guid;
		typeInfo->ReleaseTypeAttr(pTypeAttr);
		HMODULE hModule = LoadLibrary(fullPath.c_str());
		if (hModule == INVALID_HANDLE_VALUE)
		{
			return hr;
		}

		DllGetClassObjectPtr lpGetClassObject = (DllGetClassObjectPtr)GetProcAddress(hModule, "DllGetClassObject");
		if (lpGetClassObject == NULL)
		{
			return hr;
		}
		CComPtr<IClassFactory> pClassFactory;
		hr = lpGetClassObject(clsid, IID_IClassFactory, (LPVOID*)&pClassFactory);
		if (FAILED(hr))
		{
			return hr;
		}
		hr = pClassFactory->CreateInstance(NULL, IID_IDispatch, (LPVOID*)pRetVal);
		if (FAILED(hr))
		{
			return hr;
		}
	}
	return hr;
}
std::string CCreateComObject::ResolvePath(std::string& filePath)
{
	string retVal = "";
	if (filePath.empty())
	{
		return retVal;
	}

	TCHAR tempBuff[MaxBuffSize];
	ExpandEnvironmentStrings(filePath.c_str(), tempBuff, MaxBuffSize);
	string  expandedFilePath = tempBuff;
	GetFullPathName(expandedFilePath.c_str(), MaxBuffSize, tempBuff, NULL);
	if (INVALID_FILE_ATTRIBUTES == GetFileAttributes(tempBuff) && GetLastError() == ERROR_FILE_NOT_FOUND)
	{
		return retVal;
	}
	else
	{
		retVal = tempBuff;
		return retVal;
	}
}