
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Image.h>

class Detector
{
    yarp::os::BufferedPort<yarp::os::Bottle> targetPort;

public:

    Detector()
    {

    }

    bool open()
    {
          //omitted: create ports for reading images

          targetPort.open("/detector/target");

          return true;
    }

    void loop(); 

};

   
   



   
