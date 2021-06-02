/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class SimpleEQAudioProcessor : public juce::AudioProcessor
{
public:
  //==============================================================================
  SimpleEQAudioProcessor();
  ~SimpleEQAudioProcessor() override;

  //==============================================================================
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout &layouts) const override;
#endif

  void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

  //==============================================================================
  juce::AudioProcessorEditor *createEditor() override;
  bool hasEditor() const override;

  //==============================================================================
  const juce::String getName() const override;

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override;

  //==============================================================================
  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const juce::String getProgramName(int index) override;
  void changeProgramName(int index, const juce::String &newName) override;

  //==============================================================================
  void getStateInformation(juce::MemoryBlock &destData) override;
  void setStateInformation(const void *data, int sizeInBytes) override;

  static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

  juce::AudioProcessorValueTreeState apvts{
      *this,
      nullptr,
      "Parameters",
      createParameterLayout()};

private:
  //==============================================================================
  inline static const juce::String LOW_CUT_FREQ = "LowCut Freq";
  inline static const juce::String LOW_CUT_SLOPE = "LowCut Slope";
  inline static const juce::String HIGH_CUT_FREQ = "HighCut Freq";
  inline static const juce::String HIGH_CUT_SLOPE = "HighCut Slope";
  inline static const juce::String PEAK_FREQ = "Peak Freq";
  inline static const juce::String PEAK_GAIN = "Peak Gain";
  inline static const juce::String PEAK_QUALITY = "Peak Quality";
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleEQAudioProcessor)
};
