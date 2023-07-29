#include "MainComponent.h"
using namespace juce;

//==============================================================================
MainComponent::MainComponent()
{
    setSize(originalWidth, originalHeight);
    constrainer.setFixedAspectRatio(static_cast<double>(originalWidth) / static_cast<double>(originalHeight));
    constrainer.setSizeLimits(originalWidth / 4, originalHeight / 4,
        originalWidth, originalHeight);
   
    
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
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    g.drawImage(juce::ImageCache::getFromMemory(BinaryData::summer_jpg, BinaryData::summer_jpgSize),getLocalBounds().toFloat());
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    const auto scaleFactor = static_cast<float> (getWidth()) / originalWidth;
    setTransform(AffineTransform::scale(scaleFactor));
    setBounds(0, 0, originalWidth, originalHeight);
}
