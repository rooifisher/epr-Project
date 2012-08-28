#include <cv.h>
#include <highgui.h>
#include <math.h>




int main( int argc, char** argv )
{
IplImage *Igray=0, *Iat,*Iat2;
/*
==============================================================
==============================================================
		Adaptive Threshold Testing

Output Image Iat is the adaptive threshold output of the input
image. Selected when the code is run.
==============================================================
==============================================================
*/
/*
int x =180,y =200;
ptr2.val[0] = 255;
ptr2.val[1] = 0;
ptr2.val[2] = 0; */
if((Igray = cvLoadImage("bob.jpg",1))==0)
{
	return -1;
}
Iat = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
//Iat2 = cvCloneImage(Iat);

cvAdaptiveThreshold(Igray,Iat,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY_INV,100,21);

//cvSet2D(Igray,x,y,ptr2);





/*
==============================================================
==============================================================
		Clean Memory and alles
==============================================================
==============================================================
*/
 cvWaitKey(0);
cvNamedWindow("Adaptive Threshold",1);
cvShowImage("Adaptive Threshold", Igray);

cvSaveImage("testAdaptive.jpg",Iat);

/*
==============================================================
==============================================================
==============================================================
==============================================================
*/


cvDestroyWindow("Adaptive Threshold");
return(0);
}

