case-study1
===========

Code taken from Lorenzo's tutorial on head control with the iCub.

This code demonstrates usage of RFModule, in particular to catch termination signals 
and properly unblock threads waiting on Port.read() so that the process has the chance
to stop the head, park it and unitialize the device for controlling the head.

Compiling
=======

    git clone url
    cd case-study
    mkdir build
    cmake ../
    make

Running
=======

Make sure you are running yarpserver.

In two separate terminals run:

    ./target/target
    ./headTracker/headTracker

Now connect:

     yarp connect /detector/target /headTracker/target

Now you can try the following:

Send ctrl-c to headTracker, then send ctrl-c to target.

This is fine.

Send ctrl-c to target and then send ctrl-c headTracker.

This is not fine. headTracker hangs.

Now un-comment the call to tracker.interrupt();

```C++
    bool TrackerModule:: interruptModule()
    {
       // tracker.interrupt();

        return true;
    }
```

Send ctrl-c to target and then send ctrl-c headTracker.

Now this is also fine, because the signal handler calls tracker.interrupt() which in turns
calls targetPort.interrupt(). This has the effect to unblock all pending read on the port.





