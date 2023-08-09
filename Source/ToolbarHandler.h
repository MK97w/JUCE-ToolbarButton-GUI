/*
  ==============================================================================

    ToolbarHandler.h
    Created: 1 Aug 2023 10:33:59pm
    Author:  kabuk

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "DemoUtilities.h"
using namespace juce;

class ToolbarHandler : public Component
{
public:
    ToolbarHandler();
    void resized() override;
private:
    juce::Toolbar m_toolbar;

    class DemoToolbarItemFactory : public ToolbarItemFactory
    {
    public:
        DemoToolbarItemFactory() {}

        enum DemoToolbarItemIds
        {
            doc_new = 1,
        };

        void getAllToolbarItemIds(Array<int>& ids) override
        {
            // This returns the complete list of all item IDs that are allowed to
            // go in our toolbar. Any items you might want to add must be listed here. The
            // order in which they are listed will be used by the toolbar customisation panel.

            ids.add(doc_new);


            // If you're going to use separators, then they must also be added explicitly
            // to the list.
            ids.add(separatorBarId);
            ids.add(spacerId);
            ids.add(flexibleSpacerId);
        }

        void getDefaultItemSet(Array<int>& ids) override
        {
            // This returns an ordered list of the set of items that make up a
            // toolbar's default set. Not all items need to be on this list, and
            // items can appear multiple times (e.g. the separators used here).
            ids.add(doc_new);
        }
            ToolbarItemComponent* createItem(int itemId) override
            {
                switch (itemId)
                {
                    auto drawable = std::make_unique<DrawableImage>();
                    drawable->setImage(getImageFromAssets("juce_icon.png"));
                    return new ToolbarButton(itemId, "juce!", std::move(drawable), {});
                }
                return nullptr;
            }

        private:           
        };

        DemoToolbarItemFactory factory;
};