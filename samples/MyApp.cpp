#include <iostream>
#include <fstream>
#include <string.h>
#include "Leap.h"

using namespace Leap;

class SampleListener : public Listener
{
public:
    std::ofstream out;
    virtual void onConnect(const Controller &);
    virtual void onFrame(const Controller &);
    virtual void onExit(const Controller &);
};

void SampleListener::onConnect(const Controller &controller)
{
    std::cout << "Connected" << std::endl;
    this->out.open("output.txt"); // We define the file to write to 
}


void SampleListener::onExit(const Controller &controller)
{
    this->out.close();
    std::cout << "Exited" << std::endl;
}

void SampleListener::onFrame(const Controller &controller)
{
    const Frame frame = controller.frame();
    Leap::Hand handFurthestRight = frame.hands().rightmost();
    float pinch = handFurthestRight.pinchStrength();
    // A float value in the [0..1] range representing the holding strength of the pinch pose.
    // The strength is zero for an open hand, and blends to 1.0 when a pinching hand pose is recognized. Pinching can be done between the thumb and any other finger of the same hand.
    this->out << "Frame id: " << frame.id()
              << ", timestamp: " << frame.timestamp()
              << ", hands: " << frame.hands().count()
              << ", fingers: " << frame.fingers().count()
              << ", palm position: " << handFurthestRight.palmPosition()
              << ", pinch strength: " << pinch
              << std::endl;
}

int main(int argc, char **argv)
{
    // Create a sample listener and controller
    SampleListener listener;
    Controller controller;

    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    /*
    if (argc > 1 && strcmp(argv[1], "--bg") == 0)
        controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);
    */
   
    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}