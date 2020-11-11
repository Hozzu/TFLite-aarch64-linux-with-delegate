# How to Use

## 1. Install the toolchain on aarch64 linux board

./install.sh


## 2. Restart shell


## 3. Write your app with tensorflow-lite and delegate API

Link of tensorflow-lite API:  
https://www.tensorflow.org/lite/api_docs/cc

GPU delegate API:  
// Set up interpreter.  
auto model = FlatBufferModel::BuildFromFile(model_path);  
if (!model) return false;  
ops::builtin::BuiltinOpResolver op_resolver;  
std::unique_ptr<Interpreter> interpreter;  
InterpreterBuilder(*model, op_resolver)(&interpreter);  

// NEW: Prepare GPU delegate.  
auto* delegate = TfLiteGpuDelegateV2Create(/*default options=*/nullptr);  
if (interpreter->ModifyGraphWithDelegate(delegate) != kTfLiteOk) return false;  

// Run inference.  
WriteToInputTensor(interpreter->typed_input_tensor<float>(0));  
if (interpreter->Invoke() != kTfLiteOk) return false;  
ReadFromOutputTensor(interpreter->typed_output_tensor<float>(0));  

// NEW: Clean up.  
TfLiteGpuDelegateV2Delete(delegate);  

Hexagon delegate API:  
struct TfLiteHexagonDelegateOptions {  
  // This corresponds to the debug level in the Hexagon SDK. 0 (default)  
  // means no debug.  
  int debug_level;  
  // This corresponds to powersave_level in the Hexagon SDK.  
  // where 0 (default) means high performance which means more power  
  // consumption.  
  int powersave_level;  
  // If set to true, performance information about the graph will be dumped  
  // to Standard output, this includes cpu cycles.  
  // WARNING: Experimental and subject to change anytime.  
  bool print_graph_profile;  
  // If set to true, graph structure will be dumped to Standard output.  
  // This is usually beneficial to see what actual nodes executed on  
  // the DSP. Combining with 'debug_level' more information will be printed.  
  // WARNING: Experimental and subject to change anytime.  
  bool print_graph_debug;  
};  

// Return a delegate that uses Hexagon SDK for ops execution.  
// Must outlive the interpreter.  
TfLiteDelegate*  
TfLiteHexagonDelegateCreate(const TfLiteHexagonDelegateOptions* options);  

// Do any needed cleanup and delete 'delegate'.  
void TfLiteHexagonDelegateDelete(TfLiteDelegate* delegate);  

// Initializes the DSP connection.  
// This should be called before doing any usage of the delegate.  
// "lib_directory_path": Path to the directory which holds the  
// shared libraries for the Hexagon NN libraries on the device.  
// "/usr/lib/" is recommended.  
void TfLiteHexagonInitWithPath(const char* lib_directory_path);  

// Clean up and switch off the DSP connection.  
// This should be called after all processing is done and delegate is deleted.  
Void TfLiteHexagonTearDown();  


## 4. Build your app using toolchain with following compiler option
For tensorflow-lite: -ltensorflowlite  
For GPU delegate: -ltensorflowlite_gpu_delegate  
For Hexagon delegate: -ltensorflowlite_hexagon_delegate  

ex) In order to make with tensorflow-lite and GPU delegate, the compiler option should be "-ltensorflowlite -ltensorflowlite_gpu_delegate"  


## 5. Run your app

