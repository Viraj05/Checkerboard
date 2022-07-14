#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class CheckerBoard : public juce::Component 
{
    int numRows;
    int numCols;
    int length;
    int width;
    float curve;
    float scaleFactor = 1.0f;

    public : 
        CheckerBoard (int newNumRows, int newNumCols, int newLength, int newWidth, float newCurve)
        {
            numRows = newNumRows;
            numCols = newNumCols;
            length = newLength;
            width = newWidth;
            curve = newCurve;
            

        }

    void paint(juce::Graphics& g) override
    {
        
        int squareIndex = 0;
        juce::Colour currentColour;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                currentColour = (squareIndex % 2) ? juce::Colours::black : juce::Colours::white;
                g.setColour(currentColour);
                g.fillRoundedRectangle(juce::Rectangle< float >( length*i, width*j, length, width), curve);
                if (j != numCols -1) {
                    squareIndex++;
                }
            }
        }
    }
    void setScaleFactor(float newScaleFactor)
    {
        scaleFactor = newScaleFactor;

    }
    void resized() override
    {

    }
};

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    CheckerBoard cb;


    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
