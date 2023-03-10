#ifndef __LEADER_AGENT__H
#define __LEADER_AGENT__H 

#include "enviro.h"

using namespace enviro;

/* LeaderController Class used as a Process including the necessary methods, and agent functions*/
class LeaderController : public Process, public AgentInterface {

    public:
    LeaderController() : Process(), AgentInterface() {}

    /**********************************Code for Leader Robot****************************************************/
    void init() {}
    void start() {}
    void update() {
        goal_x = position().x; // Using position() method to obtain the
        goal_y = position().y; // required x & y positions for goal setting
        emit(Event("goal_change", { // Emitting the goal change event for continuously updating the position 
                { "x", goal_x },
                { "y", goal_y }
        }));

        if(sensor_value(0) < 70){ // Limiting the proximity of Leader robot to the objects 
            track_velocity(0,20); // Rotate
        } else {
            track_velocity(30,0); // Go Forward
        }

        Agent& other_robot = find_agent(1); // To find the initial robot to connect
        attach_to(other_robot); // To stay connected after finding the robot
    }
    void stop() {}

    double goal_x, goal_y;
};

/* Leader Class, which inherits from Agent class and helps in using all the agent functions*/
class Leader : public Agent {
    public:
    Leader(json spec, World& world) : Agent(spec, world) {
        add_process(bc);
    }
    private:
    LeaderController bc;
};

DECLARE_INTERFACE(Leader)

#endif