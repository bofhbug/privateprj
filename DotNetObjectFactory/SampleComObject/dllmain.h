// dllmain.h : Declaration of module class.

class CSampleCOmObjectModule : public ATL::CAtlDllModuleT< CSampleCOmObjectModule >
{
public :
	DECLARE_LIBID(LIBID_SampleCOmObjectLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SAMPLECOMOBJECT, "{0fdff80d-fbe0-45d3-aa86-25858ac17c0d}")
};

extern class CSampleCOmObjectModule _AtlModule;
