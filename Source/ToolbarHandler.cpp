/*
  ==============================================================================

    ToolbarHandler.cpp
    Created: 1 Aug 2023 10:33:59pm
    Author:  kabuk

  ==============================================================================
*/

#include "ToolbarHandler.h"
ToolbarHandler::ToolbarHandler()
{
    addAndMakeVisible(m_toolbar);
    m_toolbar.addDefaultItems(factory);
}

void ToolbarHandler::resized()
{
    auto toolbarThickness = 50;

    if (m_toolbar.isVertical())
        m_toolbar.setBounds(getLocalBounds().removeFromLeft(toolbarThickness));
    else
        m_toolbar.setBounds(getLocalBounds().removeFromTop(toolbarThickness));
}