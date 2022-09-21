This project is an in-progress DAW plug-in that will both filter and distort a signal. Three distortion options will be available:
  -Custom Clip
    Soft clipping with a customizable gain reduction function.
  -Soft Clip
    Soft clipping with fixed gain reduction function. 
  -Hard Clip
    All samples above threshold level will be crushed.
    
Currently, both AU and VST3 plug-ins are located in:
  Bandpass-Distortion/Builds/MacOSX/build/Debug/
  
I will figure out a better way to compile and store the plug-ins, but this is where they are for now.

To work on this plug-in, you will need: 
  -Projucer (https://juce.com/get-juce/download)
  -Xcode or Visual Studio

