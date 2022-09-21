<p>This project is an in-progress DAW plug-in that will both filter and distort a signal. Three distortion options will be available:</p>
<p>  -Custom Clip</p>
<p>    Soft clipping with a customizable gain reduction function.</p>
<p>  -Soft Clip</p>
<p>    Soft clipping with fixed gain reduction function.</p> 
<p>  -Hard Clip</p>
    All samples above threshold level will be crushed.
    
Currently, both AU and VST3 plug-ins are located in:
  Bandpass-Distortion/Builds/MacOSX/build/Debug/
  
I will figure out a better way to compile and store the plug-ins, but this is where they are for now.

To work on this plug-in, you will need: 
  -Projucer (https://juce.com/get-juce/download)
  -Xcode or Visual Studio

