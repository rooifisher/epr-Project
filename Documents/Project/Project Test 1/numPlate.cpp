#include <cv.h>
#include <highgui.h>

IplImage *Igray=0, *It = 0, *Iat;
int main( int argc, char** argv )
{


	if((Igray = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE))==0)
	{
		return -1;
	}

	Iat = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
	It= cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
	cvAdaptiveThreshold(Igray,Iat,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,25,11);



	

	cvNamedWindow("Adaptive Threshold",1);

	cvShowImage("Adaptive Threshold", Iat);
	cvSaveImage("numberplate_Threshold.jpg",Iat);
	cvWaitKey(0);
	cvDestroyWindow("Adaptive Threshold");

	return 0;
}
