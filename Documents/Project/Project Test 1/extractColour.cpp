#include <cv.h>
#include <highgui.h>
#include <cvaux.h>
#include <iostream>
#include <string>
#include <fstream.h>
IplImage *Img1;

using namespace std;

int main(int argc,char** argv)
{
  if((Img1 = cvLoadImage(argv[1]))==0)
  {
    printf("Error Image failed to load!!\n");
    return -1;
  }

  int position[2][2];
  
  //This will be where we get the value using the haar Classifier
  //===============================================================================
  //===============================================================================
	position[0][0] = 200;
	position[0][1] = 150;
	position[1][0] = 500;
	position[1][1] = 400;
  //===============================================================================
  //===============================================================================  
  //Take ten random places between those values and determine the colour
cvRectangle(Img1,cvPoint(position[0][0],position[0][1]),cvPoint(position[1][0],position[1][1]),cvScalar(0, 255, 0, 0),1, 8, 0);

  int roiWidth = position[1][0]  - position[0][0];
  int roiHeight = position[1][1] - position[0][1];
  //
cvSetImageROI(Img1,cvRect(position[0][0],position[0][1],roiWidth,roiHeight));
  

  int numSteps = roiWidth/10;
  int numJumps = roiHeight/10;
  
  CvScalar colour[10];
  cvResetImageROI(Img1);  

  CvScalar ptr1,ptr2;

  ptr1.val[0] = 0;
  ptr1.val[1] = 0;
  ptr1.val[2] = 255;

  for(int i =0;i<10;i++)
  {
  
      colour[i] = cvGet2D(Img1,position[0][1] + i*numJumps,position[0][0] + i*numSteps);
      cvSet2D(Img1,position[0][1] + i*numJumps,position[0][0] + i*numSteps,ptr1);
  }
  
  cout << "The colour values are: \n";
  
  for(int i = 0;i<10;i++)
  {
      cout << "(" << colour[i].val[0] << "," << colour[i].val[1] << "," << colour[i].val[2] << ")\n";
  }
  
  cout << "The colour of the road is: \n";
  int height = Img1->height-1;
  int midWidth = Img1->width;
  midWidth = midWidth/2;
  ptr2 = cvGet2D(Img1,height,midWidth);
  cout << "(" << ptr2.val[0] << "," << ptr2.val[1] << "," << ptr2.val[2] << ")\n";

  
  //The created Matrix is used to determine the colour it is a 3-dimensional matrix. Of size 256 by 256 by 256
  
  string colours[256][256][256];
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  cvShowImage("Picture:",Img1);
  cvWaitKey(0);
  return 0;
}