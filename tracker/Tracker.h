
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Image.h>

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/ControlBoardInterfaces.h>

// A tracker class
class Tracker
{
   yarp::os::BufferedPort<yarp::os::Bottle> targetPort;
   
  
public:

    Tracker() {}

    bool open();

    bool close();

    void loop(); 

    void interrupt();
};

   
   



   
