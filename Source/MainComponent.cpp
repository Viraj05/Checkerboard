#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(): cb(8, 8, 20, 20, 0)
{
    addChildComponent(cb);
    cb.setScaleFactor(0.75f);
    cb.setVisible(true);
    setSize (640, 640);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colours::cornflowerblue);
    g.setFont(juce::Font(16.0f));

    g.fillCheckerBoard(juce::Rectangle<float>(20, 200, 160, 160), 20, 20, juce::Colours::white, juce::Colours::black);
        //comment! this is fun!
    // g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    cb.setBounds(20, 20, 300, 300);
}
