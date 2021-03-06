// SampleComDisplay.h : Declaration of the CSampleComDisplay

#pragma once
#include "resource.h"       // main symbols



#include "SampleCOmObject_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSampleComDisplay

class ATL_NO_VTABLE CSampleComDisplay :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSampleComDisplay, &CLSID_SampleComDisplay>,
	public IDispatchImpl<ISampleComDisplay, &IID_ISampleComDisplay, &LIBID_SampleCOmObjectLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSampleComDisplay()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CSampleComDisplay)
	COM_INTERFACE_ENTRY(ISampleComDisplay)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		OutputDebugString("CSampleComDisplay::FinalConstruct");
		return S_OK;
	}

	void FinalRelease()
	{
		OutputDebugString("CSampleComDisplay::FinalRelease");
	}

public:

	STDMETHOD(Display)(/* [in] */ BSTR filePath,/* [in] */ BSTR className);

};

OBJECT_ENTRY_AUTO(__uuidof(SampleComDisplay), CSampleComDisplay)
