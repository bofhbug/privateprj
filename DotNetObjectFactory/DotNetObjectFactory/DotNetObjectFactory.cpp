// DotNetObjectFactory.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <atlbase.h>
#include <comutil.h>

#include "DotNetObjectFactoryMixed.h"

#include "CreateComObject.h"

#include <memory>

std::unique_ptr<DotNetObjectFactoryMixed> g_netFactory;

STDAPI CreateComObject(/* [in] */ BSTR filePath,/* [in] */ BSTR className,/* [retval][out] */ IDispatch **pVal)
{
	CCreateComObject newObj;

	_bstr_t tempFilePath = filePath;
	_bstr_t tempClassName = className;

	std::string tempFilePathStr = (LPCTSTR)tempFilePath;
	std::string tempClassNameStr = (LPCTSTR)tempClassName;

	HRESULT hr = newObj.CreateComObject(tempFilePathStr, tempClassNameStr, (IDispatch**)pVal);
	return hr;
}

STDAPI CreateDotNetObject(/* [in] */ BSTR filePath,/* [in] */ BSTR className,/* [retval][out] */ IDispatch **pVal)
{
	if (g_netFactory == NULL)
	{
		g_netFactory.reset(new DotNetObjectFactoryMixed());
	}
	*pVal = g_netFactory->GetNetObject(filePath, className);
	return S_OK;
}