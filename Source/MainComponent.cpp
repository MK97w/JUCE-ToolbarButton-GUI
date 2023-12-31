#include "MainComponent.h"
#include "ToolbarHandler.h"
using namespace juce;

//==============================================================================
MainComponent::MainComponent()
{
  
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawImage(juce::ImageCache::getFromMemory(BinaryData::winter_jpg, BinaryData::winter_jpgSize),getLocalBounds().toFloat());
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
