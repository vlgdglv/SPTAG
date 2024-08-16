//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class AnnClient : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  private bool swigCMemOwnBase;

  internal AnnClient(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwnBase = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(AnnClient obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~AnnClient() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwnBase) {
          swigCMemOwnBase = false;
          CSHARPSPTAGClientPINVOKE.delete_AnnClient(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public AnnClient(string p_serverAddr, string p_serverPort) : this(CSHARPSPTAGClientPINVOKE.new_AnnClient(p_serverAddr, p_serverPort), true) {
  }

  public void SetTimeoutMilliseconds(int p_timeout) {
    CSHARPSPTAGClientPINVOKE.AnnClient_SetTimeoutMilliseconds(swigCPtr, p_timeout);
    if (CSHARPSPTAGClientPINVOKE.SWIGPendingException.Pending) throw CSHARPSPTAGClientPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetSearchParam(string p_name, string p_value) {
    CSHARPSPTAGClientPINVOKE.AnnClient_SetSearchParam(swigCPtr, p_name, p_value);
    if (CSHARPSPTAGClientPINVOKE.SWIGPendingException.Pending) throw CSHARPSPTAGClientPINVOKE.SWIGPendingException.Retrieve();
  }

  public void ClearSearchParam() {
    CSHARPSPTAGClientPINVOKE.AnnClient_ClearSearchParam(swigCPtr);
    if (CSHARPSPTAGClientPINVOKE.SWIGPendingException.Pending) throw CSHARPSPTAGClientPINVOKE.SWIGPendingException.Retrieve();
  }

  public BasicResult[] Search(byte[] p_data, int p_resultNum, string p_valueType, bool p_withMetaData) {
unsafe { fixed(byte* ptrp_data = p_data) { CSHARPSPTAGClientPINVOKE.WrapperArray tempp_data = new CSHARPSPTAGClientPINVOKE.WrapperArray( (System.IntPtr)ptrp_data, (ulong)p_data.LongLength );
    {
      CSHARPSPTAGClientPINVOKE.WrapperArray data = CSHARPSPTAGClientPINVOKE.AnnClient_Search(swigCPtr,  tempp_data , p_resultNum, p_valueType, p_withMetaData);
      BasicResult[] ret = new BasicResult[data._size];
      System.IntPtr ptr = data._data;
      for (ulong i = 0; i < data._size; i++) {
          CSHARPSPTAGClientPINVOKE.WrapperArray arr = (CSHARPSPTAGClientPINVOKE.WrapperArray)System.Runtime.InteropServices.Marshal.PtrToStructure(ptr, typeof(CSHARPSPTAGClientPINVOKE.WrapperArray));
          ret[i] = new BasicResult(arr._data, true);
          ptr += sizeof(CSHARPSPTAGClientPINVOKE.WrapperArray);
      }
      CSHARPSPTAGClientPINVOKE.deleteArrayOfWrapperArray(data._data);
      
      if (CSHARPSPTAGClientPINVOKE.SWIGPendingException.Pending) throw CSHARPSPTAGClientPINVOKE.SWIGPendingException.Retrieve();
      return ret;
}
} }
  }

  public bool IsConnected() {
    bool ret = CSHARPSPTAGClientPINVOKE.AnnClient_IsConnected(swigCPtr);
    if (CSHARPSPTAGClientPINVOKE.SWIGPendingException.Pending) throw CSHARPSPTAGClientPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}
