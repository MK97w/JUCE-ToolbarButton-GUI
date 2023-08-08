/*
  ==============================================================================

    ToolbarHandler.h
    Created: 1 Aug 2023 10:33:59pm
    Author:  kabuk

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
using namespace juce;

class ToolbarHandler : public juce::Component
{
public:
    ToolbarHandler();
    //void resized() override;
private:
    juce::Toolbar m_toolbar;
    
};