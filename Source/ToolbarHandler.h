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
    void resized() override;
private:
    juce::Toolbar m_toolbar;
    /*class DemoToolbarItemFactory : public juce::ToolbarItemFactory
    {
    public:
        DemoToolbarItemFactory() {}

        //==============================================================================
        // Each type of item a toolbar can contain must be given a unique ID. These
        // are the ones we'll use in this demo.
        enum DemoToolbarItemIds
        {
            doc_new = 1,
            doc_open = 2,
            doc_save = 3,
            doc_saveAs = 4,
            edit_copy = 5,
            edit_cut = 6,
            edit_paste = 7,
            juceLogoButton = 8,
            customComboBox = 9
        };

        void getAllToolbarItemIds(juce::Array<int>& ids) override
        {
            // This returns the complete list of all item IDs that are allowed to
            // go in our toolbar. Any items you might want to add must be listed here. The
            // order in which they are listed will be used by the toolbar customisation panel.

            ids.add(doc_new);
            ids.add(doc_open);
            ids.add(doc_save);
            ids.add(doc_saveAs);
            ids.add(edit_copy);
            ids.add(edit_cut);
            ids.add(edit_paste);
            ids.add(juceLogoButton);
            ids.add(customComboBox);

            // If you're going to use separators, then they must also be added explicitly
            // to the list.
            ids.add(separatorBarId);
            ids.add(spacerId);
            ids.add(flexibleSpacerId);
        }

        void getDefaultItemSet(juce::Array<int>& ids) override
        {
            // This returns an ordered list of the set of items that make up a
            // toolbar's default set. Not all items need to be on this list, and
            // items can appear multiple times (e.g. the separators used here).
            ids.add(doc_new);
            ids.add(doc_open);
            ids.add(doc_save);
            ids.add(doc_saveAs);
            ids.add(spacerId);
            ids.add(separatorBarId);
            ids.add(edit_copy);
            ids.add(edit_cut);
            ids.add(edit_paste);
            ids.add(separatorBarId);
            ids.add(flexibleSpacerId);
            ids.add(customComboBox);
            ids.add(flexibleSpacerId);
            ids.add(separatorBarId);
            ids.add(juceLogoButton);
        }

        juce::ToolbarItemComponent* createItem(int itemId) override
        {
            switch (itemId)
            {
                case doc_new:           return createButtonFromZipFileSVG(itemId, "new",     "document-new.svg");
                case doc_open:          return createButtonFromZipFileSVG(itemId, "open",    "document-open.svg");
                case doc_save:          return createButtonFromZipFileSVG(itemId, "save",    "document-save.svg");
                case doc_saveAs:        return createButtonFromZipFileSVG(itemId, "save as", "document-save-as.svg");
                case edit_copy:         return createButtonFromZipFileSVG(itemId, "copy",    "edit-copy.svg");
                case edit_cut:          return createButtonFromZipFileSVG(itemId, "cut",     "edit-cut.svg");
                case edit_paste:        return createButtonFromZipFileSVG(itemId, "paste",   "edit-paste.svg");

                case juceLogoButton:
                {
                    auto drawable = std::make_unique<DrawableImage>();
                    //drawable->setImage(getImageFromAssets("juce_icon.png")); -> must implement my own
                    return new juce::ToolbarButton(itemId, "juce!", std::move(drawable), {});
                }

                //case customComboBox:    return new CustomToolbarComboBox(itemId);
                default:                break;
            }

            return nullptr;
        }

    private:
        StringArray iconNames;
        OwnedArray<Drawable> iconsFromZipFile;

        // This is a little utility to create a button with one of the SVG images in
        // our embedded ZIP file "icons.zip"
        ToolbarButton* createButtonFromZipFileSVG(const int itemId, const juce::String& text, const juce::String& filename)
        {
            if (iconsFromZipFile.size() == 0)
            {
                // If we've not already done so, load all the images from the zip file..
               // ZipFile icons(createAssetInputStream("icons.zip").release(), true); -> must implement my own

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
        }
        
    };

    DemoToolbarItemFactory factory;*/
};