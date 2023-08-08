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
                    //case doc_new:           return new ToolbarButton(itemId, text, image->createCopy(), {}); -> ADD BUTTON WITH IMAGES HERE

                    default:                break;
                }

                return nullptr;
            }

        private:
            StringArray iconNames;
            OwnedArray<Drawable> iconsFromZipFile;

            // This is a little utility to create a button with one of the SVG images in
            // our embedded ZIP file "icons.zip"
            /*ToolbarButton* createButtonFromZipFileSVG(const int itemId, const String& text, const String& filename)
            {
                if (iconsFromZipFile.size() == 0)
                {
                    // If we've not already done so, load all the images from the zip file..
                    ZipFile icons(createAssetInputStream("icons.zip").release(), true);

                    for (int i = 0; i < icons.getNumEntries(); ++i)
                    {
                        std::unique_ptr<InputStream> svgFileStream(icons.createStreamForEntry(i));

                        if (svgFileStream.get() != nullptr)
                        {
                            iconNames.add(icons.getEntry(i)->filename);
                            iconsFromZipFile.add(Drawable::createFromImageDataStream(*svgFileStream));
                        }
                    }
                }

                auto* image = iconsFromZipFile[iconNames.indexOf(filename)];
                return new ToolbarButton(itemId, text, image->createCopy(), {});
            }*/

            // Demonstrates how to put a custom component into a toolbar - this one contains
            // a ComboBox.
            
        };

        DemoToolbarItemFactory factory;
};