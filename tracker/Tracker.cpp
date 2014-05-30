
#include "Tracker.h"

#include <yarp/sig/Vector.h>

using namespace yarp::sig;
using namespace yarp::os;

void Tracker::loop()
{
    // we read from a port
    // Notice: this call is blocking
    Bottle *target = targetPort.read();  // read a target
    if (target!=NULL) 
    { 
        double x=target->get(0).asDouble();
        double y=target->get(1).asDouble();
        int frame=target->get(2).asInt();

        printf("[%d] Got %lf %lf\n", frame, x, y);

        // based on target position prepare motor command 
        // to control the robot

        // iVelocity->velocityMove(setpoints.data());
    }
}

bool Tracker::open()
{
    //create input port
    targetPort.open("/headTracker/target");

    // omitted: initialize head controller

    printf("Initializing head motors\n");

    return true;
}

bool Tracker::close()
{

   // omitted: send zero velocity to motors
   // omitted: park head
   // omitted: close head device

    printf("Stopping head motors\n");
    printf("Uninitialize head device\n");

    return true;
}

void Tracker::interrupt()
{
        printf("Calling interrupt\n");
        targetPort.interrupt();
}



