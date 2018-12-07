

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
/* Compiler settings for SampleCOmObject.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SampleCOmObject_i_h__
#define __SampleCOmObject_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISampleComDisplay_FWD_DEFINED__
#define __ISampleComDisplay_FWD_DEFINED__
typedef interface ISampleComDisplay ISampleComDisplay;

#endif 	/* __ISampleComDisplay_FWD_DEFINED__ */


#ifndef __SampleComDisplay_FWD_DEFINED__
#define __SampleComDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class SampleComDisplay SampleComDisplay;
#else
typedef struct SampleComDisplay SampleComDisplay;
#endif /* __cplusplus */

#endif 	/* __SampleComDisplay_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISampleComDisplay_INTERFACE_DEFINED__
#define __ISampleComDisplay_INTERFACE_DEFINED__

/* interface ISampleComDisplay */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISampleComDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81563539-7368-4349-9f3a-e3c643dff71e")
    ISampleComDisplay : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Display( 
            /* [in] */ BSTR filePath,
            /* [in] */ BSTR className) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISampleComDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISampleComDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISampleComDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISampleComDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISampleComDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISampleComDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISampleComDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISampleComDisplay * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Display )( 
            ISampleComDisplay * This,
            /* [in] */ BSTR filePath,
            /* [in] */ BSTR className);
        
        END_INTERFACE
    } ISampleComDisplayVtbl;

    interface ISampleComDisplay
    {
        CONST_VTBL struct ISampleComDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISampleComDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISampleComDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISampleComDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISampleComDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISampleComDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISampleComDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISampleComDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISampleComDisplay_Display(This,filePath,className)	\
    ( (This)->lpVtbl -> Display(This,filePath,className) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISampleComDisplay_INTERFACE_DEFINED__ */



#ifndef __SampleCOmObjectLib_LIBRARY_DEFINED__
#define __SampleCOmObjectLib_LIBRARY_DEFINED__

/* library SampleCOmObjectLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOmObjectLib;

EXTERN_C const CLSID CLSID_SampleComDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("49af0bf1-b0cf-4308-a7bc-4e61a3f6f607")
SampleComDisplay;
#endif
#endif /* __SampleCOmObjectLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


