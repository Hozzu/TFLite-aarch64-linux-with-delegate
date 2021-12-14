# How to Use

## 1. Install the toolchain on aarch64 linux board

./install.sh


## 2. Restart shell


## 3. Write your app with tensorflow-lite and delegate API

Link of tensorflow-lite API:  
https://www.tensorflow.org/lite/api_docs/cc  

GPU delegate API:  
  
#include <tensorflow/lite/delegates/gpu/delegate.h>  
  
// Prepare GPU delegate.  
auto* delegate = TfLiteGpuDelegateV2Create(nullptr);  
interpreter->ModifyGraphWithDelegate(delegate);  

// Clean up.  
TfLiteGpuDelegateV2Delete(delegate);  

Hexagon delegate API:  
  
#include <tensorflow/lite/delegates/hexagon/hexagon_delegate.h>  
  
// Assuming shared libraries are under "/usr/lib"  
const char[] library_directory_path = "/usr/lib";  
TfLiteHexagonInitWithPath(library_directory_path);  // Needed once at startup.  
TfLiteHexagonDelegateOptions params = {0};  
  
// 'delegate_ptr' Need to outlive the interpreter. For example,  
// If use case will need to resize input or anything that can trigger  
// re-applying delegates then 'delegate_ptr' need to outlive the interpreter.  
auto* delegate_ptr = TfLiteHexagonDelegateCreate(&params);  
TfLiteDelegatePtr delegate(delegate_ptr, [](TfLiteDelegate* delegate) { TfLiteHexagonDelegateDelete(delegate); });  
interpreter->ModifyGraphWithDelegate(delegate.get());  
  
// After usage of delegate.  
TfLiteHexagonTearDown();  // Needed once at end of app/DSP usage.  


## 4. Build your app using toolchain with following compiler option  
For tensorflow-lite: -ltensorflowlite  
For GPU delegate: -ltensorflowlite_gpu_delegate  
For Hexagon delegate: -ltensorflowlite_hexagon_delegate  

ex) In order to make with tensorflow-lite, GPU delegate and Hexagon delegate, the compiler option should be "-ltensorflowlite -ltensorflowlite_hexagon_delegate -ltensorflowlite_gpu_delegate"  


## 5. Run your app

