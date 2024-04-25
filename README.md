# TFLite for Aarch64 Linux with Delegate
Deep learning inference SW framework based on TensorFlow Lite with delegates for Aarch64 Linux  

In order to run deep learning application on Aarch64 Linux system (non-Android), I built tensorflow lite for such system.  
It is based on **tensorflow v2.16.1**.  

I included XNNPACK, GPU, hexagon, and NNAPI delegates.  
GPU delegate requires OpenCL library.  
Hexagon delegate requires Qualcomm hexagon NN library.  

I wrote on guide.txt how to build tensorflow lite and deleage for aarch64 Linux. 

I made two versions: onboard and offboard.  
Onboard version contains gcc, make as well as tensorflow lite and delegates in order to build deep learning applications on board.  
Offboard version only contains tensorflow lite and delegates, assuming that use cross compiler toolchain.  

For instruction, read README.md in each directory.  

It was tested on Qualcomm SA8195 platform which works on AGL (Automotive Grade Linux).  

![image](https://github.com/Hozzu/TFLite-aarch64-linux-with-delegate/assets/28533445/53abdc94-ef59-4d20-92de-334f404dd4b9)

