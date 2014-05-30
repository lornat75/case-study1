// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-


#include <stdio.h>
#include <yarp/os/Network.h>

#include "Detector.h"

using namespace yarp::os;

int main(int argc, char *argv[]) 
{
    Network yarp;

    Detector detector;

    if (!detector.open())
    {
        fprintf(stderr, "Error opening detector\n");
        return -1;
    }

    while(true)
    {
        detector.loop();
    }

    return 0;
}