/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BandpassDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor, private ComboBox::Listener, Slider::Listener
{
public:
    BandpassDistortionAudioProcessorEditor (BandpassDistortionAudioProcessor&);
    ~BandpassDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BandpassDistortionAudioProcessor& audioProcessor;
    
    ComboBox distChoice;
    Slider threshold;
    Slider mix;
    Label thresholdLabel;
    Label mixLabel;
    
    
    void sliderValueChanged(Slider * sliderThatHasChanged) override;
    void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BandpassDistortionAudioProcessorEditor)
};
