# TFLite for Aarch64 Linux with Delegate
Deep learning inference SW framework based on TensorFlow Lite with GPU and hexagon delegate for Aarch64 Linux

In order to run Deep learning application on Aarch64 Linux system (non-Android), I built tensorflow lite for such system.
It is based on \*\*tensorflow r2.5\*\*.

I also included GPU and hexagon delegate.
GPU delegate requires OpenCL and OpenGL ES 2.0 libraries.
Hexagon Delegate works only on Qualcomm DSP.

I wrote on guide.txt how to build tensorflow lite and deleage for aarch64 Linux.

I made two versions: onboard and offboard.
Onboard version contains gcc, g++ as well as tensorflow lite and delegate in order to build deep learning applications on board.
Offboard version only contains tensorflow lite and delegate, assuming that use cross compiler toolchain.

For instruction, read README.md in each directory.

It was tested on Qualcomm SA8195 platform which works on AGL (Automotive Grade Linux).

