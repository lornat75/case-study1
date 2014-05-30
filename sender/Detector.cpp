
#include "Detector.h"

using namespace yarp::sig;
using namespace yarp::os;

void Detector::loop()
{
    ImageOf<PixelRgb> *image = imagePort.read();  // read an image

    if (image!=NULL) { 

        // check we actually got something

        ImageOf<PixelRgb> &outImage = outPort.prepare(); //get an output image
        outImage=*image;

        //printf("We got an image of size %dx%d\n", image->width(), image->height());
        double xMean = 0;
        double yMean = 0;
        int ct = 0;
        for (int x=0; x<image->width(); x++) {
            for (int y=0; y<image->height(); y++) {
                PixelRgb& pixel = image->pixel(x,y);
                // very simple test for blueishness
                // make sure red level exceeds blue and green by a factor of 2
                // plus some threshold
                if (pixel.r>pixel.b*1.2+10 && pixel.r>pixel.g*1.2+10) {
                    // there's a red pixel at (x,y)!
                    // let's find the average location of these pixels

                    // accumulate x
                    // accumulate y
                    // count total number of points
                    xMean += x;
                    yMean += y;
                    ct++;

                    outImage(x,y)=pixel;
                }
                else
                {
                    outImage(x,y)=PixelRgb(0,0,0);
                }
            }
        }
        if (ct>0) {
            xMean /= ct;
            yMean /= ct;
        }

        Bottle &target=targetPort.prepare();
        target.clear();
        target.addDouble(xMean);
        target.addDouble(yMean);
		
        //threshold on the size of the object we found
        if (ct>(image->width()/20)*(image->height()/20))
        {
            target.addInt(1);
        }
        else
            target.addInt(0);    

		target.addInt(image->width());
		target.addInt(image->height());
		
        targetPort.write();

        outPort.write();
    }
}