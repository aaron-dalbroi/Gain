#pragma once

#include "GainProcessor.h"


class GainProcessorEditor : public juce::AudioProcessorEditor
{
    public:
        GainProcessorEditor(GainProcessor&);
        ~GainProcessorEditor() override;

        //==============================================================================
        void paint(juce::Graphics&) override;
        void resized() override;

    private:
        // This reference is provided as a quick way for your editor to
        // access the processor object that created it.
        GainProcessor& audioProcessor;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainProcessorEditor)
};


