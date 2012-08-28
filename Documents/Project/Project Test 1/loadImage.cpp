#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <fstream>

using namespace std;
IplImage *Igray=0, *Iat,*Iat2,*Igray2;
CvScalar ptr,ptr2;
int ImgResize = 0;
int xChange = 0;






int main( int argc, char** argv )
{
int imageCount = 0;
/*
==============================================================
==============================================================
		Adaptive Threshold Testing

Output Image Iat is the adaptive threshold output of the input
image. Selected when the code is run.
==============================================================
==============================================================
*/

if((Igray = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE))==0)
{
	return -1;
}
Igray2 = cvCreateImage(cvSize(800,600),IPL_DEPTH_8U,1);

if(Igray->height !=600 || Igray->width !=800)
{
	Igray2 = cvCreateImage(cvSize(800,600),IPL_DEPTH_8U,1);
	cvResize(Igray,Igray2);
	xChange = (Igray2->width - Igray->width)/2; 
	Igray = Igray2;
	ImgResize = 1;
} 

Iat = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
Iat2 = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
cvAdaptiveThreshold(Igray,Iat,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,7,3);
cvNamedWindow("Adaptive Threshold",1);


//Make it grey so can see the areas that it is currently detecting
ptr2.val[0] = 220;
ptr2.val[1] = 4;
ptr2.val[2] = 6;

  if( remove( "Output.txt" ) != 0 )
   perror( "Error deleting file" );
 else
  puts( "File successfully deleted" );

/*============================================================
		Finding the Numberplate
==============================================================*/
for(int x = 0;x<630;x = x+50)
{
	//printf("x = %d\n\n",x);

	for(int y = 0;y<550;y = y+10)
	{

		int count = 0;
		for(int i =x;i<x+170;i++)
		{
			for(int j =y;j<y+50;j++)
			{
			  ptr = cvGet2D(Iat,j,i);
			 // printf("x = %d y = %d %d %d %d %d\n",i,j,ptr[0],ptr[1],ptr[2],ptr[3]);
			  
			  if(ptr.val[0]  <10)//Value I just changed 08/07/2012
				{
					count++;
										
				}
				double countDouble = (double)(count);
				double z = countDouble/7500.00;
				//printf("RESULT = %lf \n",z);


			}
		}
					  if(count/7500.00 > 0.32)
				{
					//printf("Possible Letter Found\n");
					for(int p = x;p<x+170;p++)
					{
						for(int m = y;m<y+50;m++)
						{
							cvSet2D(Iat,m,p,ptr2);
						}
					}



	
					ofstream fout;
 
 

					imageCount++;
					string s;
					stringstream out;
					out << imageCount;
					s = out.str();
					const char * num = s.c_str();

					char file[255];
					char temp[255];
					strcpy(file,"Area");
					strcat(file,num);
					strcat(file,".jpg");
					strcpy(temp,file);
					int xLength = 183;
					int yLength = 63;
					xLength = xLength + xChange;
					cvSetImageROI(Igray, cvRect(x-3, y-3, xLength, yLength));
					cvSaveImage(file,Igray);
					strcat(file,".txt");
					fout.open ("Output.txt",fstream::app);
  					fout << temp<<"\n";
					cvResetImageROI(Igray);
					fout.close();

				}



	}
}
/*============================================================
		Found the numberplate
ptr2.val[0] = 220;		size 170 by 50
ptr2.val[1] = 4;
ptr2.val[2] = 6;
==============================================================*/



cvSaveImage("testAdaptive.jpg",Iat);
cvShowImage("Adaptive Threshold", Iat);
cvWaitKey(0);
cvDestroyWindow("Adaptive Threshold");
system("wait");
return(0);
}

