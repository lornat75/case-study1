
#include "Detector.h"

#include <yarp/os/Time.h>

using namespace yarp::sig;
using namespace yarp::os;

void Detector::loop()
{
        // Omitteed code: read from port an image, find target
        // we sleep for 200ms instead
        Time::delay(0.2); 

        // extract target position
        double xMean=0.0;
        double yMean=0.0;
        static int frame=0;
        frame++;

        // write to port
        Bottle &target=targetPort.prepare();
        target.clear();
        target.addDouble(xMean);
        target.addDouble(yMean);
        target.addInt(frame);

        targetPort.write();
}
