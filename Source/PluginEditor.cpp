/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleDistortionAudioProcessorEditor::SimpleDistortionAudioProcessorEditor (SimpleDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);
    
    addAndMakeVisible(&threshold);
    threshold.setRange(0.0f, 1.0f, .01f);
    threshold.setTitle("Threshold");
    threshold.addListener(this);
    threshold.setTextValueSuffix(" Amplitude");
    thresholdLabel.setText("Threshold", juce::dontSendNotification);
    thresholdLabel.attachToComponent(&threshold, true);
    
    addAndMakeVisible(&mix);
    mix.setRange(0.0f, 100.0f, .1f);
    mix.setSliderStyle(juce::Slider::LinearHorizontal);
    mix.setTitle("Mix");
    mix.addListener(this);
    mix.setTextValueSuffix("% Wet");
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.attachToComponent(&mix, true);
    
    addAndMakeVisible(&distChoice);
    distChoice.addItem("Hard Clip", 1);
    distChoice.addItem("Soft Clip", 2);
    
    distChoice.setSelectedId(1);
    distChoice.addListener(this);
}

SimpleDistortionAudioProcessorEditor::~SimpleDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SimpleDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void SimpleDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    distChoice.setBounds(100, 50, 200, 50);
    threshold.setBounds(100, 100, 400, 50);
    mix.setBounds(100, 150, 400, 50);
}

void SimpleDistortionAudioProcessorEditor::comboBoxChanged(ComboBox *comboBoxThatHasChanged) {
    audioProcessor.menuChoice = comboBoxThatHasChanged->getSelectedId();
}

void SimpleDistortionAudioProcessorEditor::sliderValueChanged(Slider *sliderThatHasChanged) {
    if (sliderThatHasChanged == &mix)
        audioProcessor.mix = sliderThatHasChanged->getValue();
    
    if (sliderThatHasChanged == &threshold)
        audioProcessor.threshold = sliderThatHasChanged->getValue();
}
