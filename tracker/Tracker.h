
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Image.h>

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/ControlBoardInterfaces.h>

class Tracker
{
   yarp::os::BufferedPort<yarp::os::Bottle> targetPort;
   
   yarp::dev::PolyDriver robotHead;
   yarp::dev::IVelocityControl *iVelocity;
   yarp::dev::IEncoders *iEncoders;

   yarp::dev::IPositionControl *iPosition;
   
public:

    Tracker()
    {
        // constructor
        iVelocity=0;
        iEncoders=0;
        iPosition=0;
    }

    bool open();

    bool close();

    void loop(); 

    void interrupt()
    {
        targetPort.interrupt();
        
    }

};

   
   



   