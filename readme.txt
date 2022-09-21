This project is an in-progress DAW plug-in that will both filter and distort a signal. Three distortion options will be available:
  -Custom Clip
    Soft clipping with a customizable gain reduction function.
  -Soft Clip
    Soft clipping with fixed gain reduction function.
  -Hard Clip
    All samples above threshold level will be crushed.
    
To get started working on this:
  1) Download Projucer if you don't have it already (https://juce.com/get-juce/download)
  2) Open the .jucer file.
  3) If your IDE is not already listed under "Exporters," click the plus button at the bottom of the column and add your IDE.
  4) Select your IDE in the "Selected exporter" drop-down menu.
  5) Click the icon next to the "Selected exporter" menu.
  
  This should generate the project files and libraries that you need to edit the source code, build, and test.

Planned signal flow:
  Bandpass filter -> Clip -> Bandpass filter -> Blend w/Dry signal
  


