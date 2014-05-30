
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Image.h>

class Detector
{
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > imagePort;  // make a port for reading images
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > outPort;
    yarp::os::BufferedPort<yarp::os::Bottle> targetPort;

public:

    Detector()
    {

    }

    bool open()
    {
          imagePort.open("/objectDetector/image/in");  // give the port a name
          outPort.open("/objectDetector/image/out");
          targetPort.open("/objectDetector/target");

          return true;
    }

    void loop(); 

};

   
   



   