// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include <stdio.h>
#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>


#include "Tracker.h"

using namespace yarp::os;

class TrackerModule: public RFModule
{
    Tracker tracker;
public:

    bool configure(ResourceFinder &rf)
    {
        return tracker.open();
    }

    double getPeriod()
    {
        return 0.0;
    }
    
    bool updateModule()
    {
        tracker.loop();
        
        return true; 
    }

    bool close()
    {
	    return tracker.close();
    }

    bool interruptModule()
    {
        tracker.interrupt();

        return true;
    }

};

int main(int argc, char *argv[]) 
{
    Network yarp;

	TrackerModule trackerModule;
	ResourceFinder rf;

	if (!trackerModule.configure(rf))
    {
        fprintf(stderr, "Error opening tracker\n");
        return -1;
    }
        
	trackerModule.runModule();
    
    return 0;
}
