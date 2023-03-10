#ifndef __CHASER_AGENT__H
#define __CHASER_AGENT__H 

#include "enviro.h"

using namespace enviro;

/* ChaserController Class used as a Process including the necessary methods, and agent functions*/
class ChaserController : public Process, public AgentInterface {

    public:
    ChaserController() : Process(), AgentInterface() {}

    /**********************************Code for Follower Robot****************************************************/
    // Initial configurations
    void init() { 
        goal_x = 0; // Initializing the goal_x for x position
        goal_y = 0; // Initializing the goal_y for y position
        watch("goal_change", [this](Event e) { // Watching for the goal change event for continuously updating the position 
            goal_x = e.value()["x"];
            goal_y = e.value()["y"];
            std::cout << "New goal: " << goal_x << ", " << goal_y << "\n"; // Printing the current updated positions
        });
    }
    void start() {}
    // Updating configurations
    void update() { 
        Agent& other_robot = find_agent(1); // To find the initial robot to connect
        attach_to(other_robot); // To stay connected after finding the robot
        watch("goal_change", [this](Event e) { // Watching for the goal change event for continuously updating the position 
            goal_x = e.value()["x"];
            goal_y = e.value()["y"];
            move_toward(goal_x, goal_y);
            std::cout << "New goal: " << goal_x << ", " << goal_y << "\n"; // Printing the current updated positions
        });
    }
    void stop() {}

    double goal_x, goal_y;
};

/* Chaser Class, which inherits from Agent class and helps in using all the agent functions*/
class Chaser : public Agent {
    public:
    Chaser(json spec, World& world) : Agent(spec, world) {
        add_process(bc);
    }
    private:
    ChaserController bc;
};

DECLARE_INTERFACE(Chaser)

#endif