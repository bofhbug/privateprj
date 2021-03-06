// SampleComDisplay.cpp : Implementation of CSampleComDisplay

#include "stdafx.h"
#include "SampleComDisplay.h"
#include <stdio.h>

// CSampleComDisplay

STDMETHODIMP CSampleComDisplay::Display(/* [in] */ BSTR filePath,/* [in] */ BSTR className)
{

	TCHAR tempBuff[4096];
	sprintf_s(tempBuff, "Sample COM Printing Value : %S => %S", filePath, className);

	OutputDebugString(tempBuff);

	return S_OK;
}