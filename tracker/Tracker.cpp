
#include "Tracker.h"

#include <yarp/sig/Vector.h>

using namespace yarp::sig;
using namespace yarp::os;

void Tracker::loop()
{
	if (!iVelocity)
		return;

    int jnts = 0;
    iVelocity->getAxes(&jnts);
    Vector setpoints;
    setpoints.resize(jnts);

    Vector encoders;
    encoders.resize(jnts);

    Bottle *target = targetPort.read();  // read a target
    if (target!=NULL) 
    { 
        double x=target->get(0).asDouble();
        double y=target->get(1).asDouble();
        int conf=target->get(2).asInt();

        int width=target->get(3).asInt();
        int height=target->get(4).asInt();

        x-=width/2;
        y-=height/2;

        double vx= 0.3 * x;
        double vy= -0.3 * y;

        setpoints=0;
		
        iEncoders->getEncoders(encoders.data());

        if (conf)
        {
            setpoints[3]=vy;
            setpoints[4]=vx;

            setpoints[0]= 0.3*encoders[3];
            setpoints[2]= -0.3*encoders[4];
        }

        iVelocity->velocityMove(setpoints.data());
    }
}

bool Tracker::open()
{
    targetPort.open("/headTracker/target");
    
    Property options;

    options.put("device", "remote_controlboard");
    options.put("local", "/tracker/motor/client");
    options.put("remote", "/icubSim/head");

    robotHead.open(options);

    if (!robotHead.isValid())
        return false;

    robotHead.view(iVelocity);
    robotHead.view(iEncoders);
    robotHead.view(iPosition);

    if (iVelocity==0 || iEncoders==0 || iPosition==0)
    {
        robotHead.close();
        return false;
    }

    int njoints=0;
    iPosition->getAxes(&njoints);
    Vector tmp(njoints);
    tmp=0.0;

    iPosition->positionMove(tmp.data());

    return true;
}

bool Tracker::close()
{

    iVelocity->stop();

    int njoints=0;
    iPosition->getAxes(&njoints);
    Vector tmp(njoints);
    tmp=0.0;

    iPosition->positionMove(tmp.data());
	
	iVelocity=NULL;
	iPosition=NULL;
	iEncoders=NULL;

    return true;
}



