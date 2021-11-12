# TFLite for Aarch64 Linux with Delegate
Deep learning inference SW framework based on TensorFlow Lite with delegates for Aarch64 Linux  

In order to run deep learning application on Aarch64 Linux system (non-Android), I built tensorflow lite for such system. It is based on **tensorflow r2.7**.  

I included XNNPACK, GPU, hexagon, and NNAPI delegate.  
GPU delegate requires OpenCL library.  
Hexagon delegate requires Qualcomm hexagon NN library.  
NNAPI requires NNAPI library and is not tested yet.  

I wrote on guide.txt how to build tensorflow lite and deleage for aarch64 Linux. 

I made two versions: onboard and offboard.  
Onboard version contains gcc, g++ as well as tensorflow lite and delegate in order to build deep learning applications on board.  
Offboard version only contains tensorflow lite and delegate, assuming that use cross compiler toolchain.  

For instruction, read README.md in each directory.  

It was tested on Qualcomm SA8195 platform which works on AGL (Automotive Grade Linux).  

![image](https://user-images.githubusercontent.com/28533445/141428765-0113020a-b45f-4076-ba02-c75a23fc48b7.png)
