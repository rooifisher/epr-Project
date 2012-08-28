#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <fstream>
using namespace std;
IplImage *Igray=0, *Iat,*Iat2;
CvScalar ptr,ptr2,ptr3;
int letterXSize = 18;
int letterYSize = 35;
bool isCharacter = false; 


int main( int argc, char** argv )
{
int imagePasses = 1;
/*
==============================================================
==============================================================
		Adaptive Threshold Implementation

Output Image Iat is the adaptive threshold output of the input
image. Selected when the code is run.
==============================================================
==============================================================
*/
if(argv[1] == NULL)
{
	printf("\nError!! \n Usage ./letterExtraction Number_plate_Image_name\n");
	return -1;
}

if((Igray = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE))==0)
{
	printf("Image Not Found");
	return -1;
}

Iat = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
Iat2 = cvCreateImage(cvSize(Igray->width,Igray->height),IPL_DEPTH_8U,1);
cvAdaptiveThreshold(Igray,Iat,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,25,11);
cvNamedWindow("Adaptive Threshold",1);


//Make it grey so can see the areas that it is currently detecting
/*
	PRINTS THE DETECTED AREA GREY
*/
ptr2.val[0] = 200;
ptr2.val[1] = 4;
ptr2.val[2] = 20;



/*============================================================
		Finding the character 

CURRENT ALGORITHM 
Search for the first occurence of a black pixel. 

Move along the pixel lines determining if the set of pixels falls 
within acceptable assumptions for a character. 
==============================================================*/
//Does not find Character at the moment merely makes the image a bit clearer.
 // for(int x = 0;x<Iat->width;x++)
 // {

	//  int countX = 0;
// 	  for(int y = 0;y<Iat->height;y++)
// 	  {
// 		  int flag = 0;
// 		  int countY = 0;
// 		  ptr = cvGet2D(Iat,y,x);
// 		  
// 		  if(ptr.val[0] < 10)
		  {
// 			    /*====================================================
// 			    *	Checking for black pixels and delting as necessary 	
// 			    *====================================================*/
// 			    if(x == 0 && y==0) 
// 			    {
// 				printf("Inside 0 and 0 x = %d y = %d\n",x,y);
// 				ptr3 = cvGet2D(Iat,y+1,x);
// 				if(ptr3.val[0] < 10)
// 				{
// 				    flag = 1;
// 				}
// 				
// 				ptr3 = cvGet2D(Iat,y+1,x+1);
// 				if(ptr3.val[0] < 10)
// 				{
// 				    flag = 1;
// 				}
// 				
// 				ptr3 = cvGet2D(Iat,y,x+1);
// 				if(ptr3.val[0] < 10)
// 				{
// 				    flag = 1;
// 				}
// 				
// 			    }
// 			    else 
// 			    {
// 				if(x == (Iat->width)-1 && y == 0)
// 			      {
// 				  printf("We got here");
// 				    ptr3 = cvGet2D(Iat,y+1,x);
// 						    if(ptr3.val[0] < 10)
// 						    {
// 							flag = 1;
// 						    }
// 				    
// 
// 						    ptr3 = cvGet2D(Iat,y+1,x-1);
// 						    if(ptr3.val[0] < 10)
// 						    {
// 							flag = 1;
// 						    }
// 
// 						    ptr3 = cvGet2D(Iat,y,x-1);
// 						    if(ptr3.val[0] < 10)
// 						    {
// 							flag = 1;
// 						    }
// 
// 			      }
// 				else 
// 				{
// 				    if(x == 0 && y == (Iat->height)-1)
// 				    {
// 					printf(" We got here x = %d y = %d\n",x,y);	
// 				      
// 					  ptr3 = cvGet2D(Iat,y,x+1);
// 					  if(ptr3.val[0] < 10)
// 					  {
// 					      flag = 1;
// 					  }
// 					  ptr3 = cvGet2D(Iat,y-1,x);
// 					  if(ptr3.val[0] < 10)
// 					  {
// 					      flag = 1;
// 					  }
// 					  ptr3 = cvGet2D(Iat,y-1,x+1);
// 					  if(ptr3.val[0] < 10)
// 					  {
// 					      flag = 1;
// 					  }
// 				    }
// 				    else
// 				    {
// 					if(x == (Iat->width)-1 && y == (Iat->height)-1)
// 					{
// 					    ptr3 = cvGet2D(Iat,y,x-1);
// 					    if(ptr3.val[0] < 10)
// 					    {
// 						flag = 1;
// 					    }
// 					    ptr3 = cvGet2D(Iat,y-1,x);
// 					    if(ptr3.val[0] < 10)
// 					    {
// 						flag = 1;
// 					    }
// 					    ptr3 = cvGet2D(Iat,y-1,x-1);
// 					    if(ptr3.val[0] < 10)
// 					      {
// 						  flag = 1;
// 					      }
// 					}
// 					
// 					else
// 					{
// 					  if(x == 0)
// 					  {
// 					  
// 								ptr3 = cvGet2D(Iat,y+1,x);
// 								if(ptr3.val[0] < 10)
// 								{
// 								    flag = 1;
// 								}
// 
// 								ptr3 = cvGet2D(Iat,y+1,x+1);
// 								if(ptr3.val[0] < 10)
// 								{
// 								    flag = 1;
// 								}
// 							
// 								ptr3 = cvGet2D(Iat,y,x+1);
// 								if(ptr3.val[0] < 10)
// 								{
// 								    flag = 1;
// 								}
// 								ptr3 = cvGet2D(Iat,y-1,x+1);
// 								if(ptr3.val[0] < 10)
// 								{
// 								    flag = 1;
// 								}
// 						
// 								
// 								ptr3 = cvGet2D(Iat,y-1,x);
// 								if(ptr3.val[0] < 10)
// 								{
// 								    flag = 1;
// 								}
// 								
// 					  }
// 					  else
// 					  {
// 							      if(y == 0)
// 							      {
// 								
// 
// 								      ptr3 = cvGet2D(Iat,y+1,x);
// 								      if(ptr3.val[0] < 10)
// 								      {
// 									  flag = 1;
// 								      }
// 								      
// 								      ptr3 = cvGet2D(Iat,y+1,x+1);
// 								      if(ptr3.val[0] < 10)
// 								      {
// 									  flag = 1;
// 								      }
// 								      
// 								      ptr3 = cvGet2D(Iat,y,x+1);
// 								      if(ptr3.val[0] < 10)
// 								      {
// 									  flag = 1;
// 								      }
// 								      ptr3 = cvGet2D(Iat,y,x-1);
// 								      if(ptr3.val[0] < 10)
// 								      {
// 									  flag = 1;
// 								      }
// 								      ptr3 = cvGet2D(Iat,y+1,x-1);
// 								      if(ptr3.val[0] < 10)
// 								      {
// 									  flag = 1;
// 								      }
// 							    }
// 							      else
// 							      {
// 								  if(x == (Iat->width)-1)
// 								  {
// 								      
// 								    ptr3 = cvGet2D(Iat,y+1,x);
// 								    if(ptr3.val[0] < 10)
// 								    {
// 									flag = 1;
// 								    }
// 										
// 								    ptr3 = cvGet2D(Iat,y,x-1);
// 								    if(ptr3.val[0] < 10)
// 								    {
// 									flag = 1;
// 								    }
// 								    ptr3 = cvGet2D(Iat,y+1,x-1);
// 								    if(ptr3.val[0] < 10)
// 								    {
// 									flag = 1;
// 								    }
// 
// 								    ptr3 = cvGet2D(Iat,y-1,x);
// 								    if(ptr3.val[0] < 10)
// 								    {
// 									flag = 1;
// 								    }
// 								    ptr3 = cvGet2D(Iat,y-1,x-1);
// 								    if(ptr3.val[0] < 10)
// 								    {
// 									flag = 1;
// 								    }
// 								  }
// 								else
// 								{
// 									  if(y == (Iat->height)-1)
// 									    {
// 									      ptr3 = cvGet2D(Iat,y-1,x);
// 									      if(ptr3.val[0] < 10)
// 									      {
// 										  flag = 1;
// 									      }
// 									      ptr3 = cvGet2D(Iat,y-1,x-1);
// 									      if(ptr3.val[0] < 10)
// 									      {
// 										  flag = 1;
// 									      }
// 
// 									      
// 									      ptr3 = cvGet2D(Iat,y,x+1);
// 									      if(ptr3.val[0] < 10)
// 									      {
// 										  flag = 1;
// 									      }
// 									      ptr3 = cvGet2D(Iat,y-1,x+1);
// 									      if(ptr3.val[0] < 10)
// 									      {
// 										  flag = 1;
// 									      }
// 									      ptr3 = cvGet2D(Iat,y,x-1);
// 									      if(ptr3.val[0] < 10)
// 									      {
// 										  flag = 1;
// 									      }
// 									    }
// 									      else
// 									      {
// 										ptr3 = cvGet2D(Iat,y+1,x);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 										  ptr3 = cvGet2D(Iat,y+1,x+1);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}		      		  
// 
// 										ptr3 = cvGet2D(Iat,y+1,x-1);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 
// 										ptr3 = cvGet2D(Iat,y-1,x);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 										ptr3 = cvGet2D(Iat,y-1,x-1);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 
// 									  
// 										ptr3 = cvGet2D(Iat,y,x+1);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 										ptr3 = cvGet2D(Iat,y-1,x+1);
// 										if(ptr3.val[0] < 10)
// 										{
// 										    flag = 1;
// 										}
// 										ptr3 = cvGet2D(Iat,y,x-1);
// 										if(ptr3.val[0] < 10)
// 										{
// 									      flag = 1;
// 									  }
// 									  }
// 								}
// 								  
// 								}
// 					  }
// 					
// 					}
// 				    }
// 				}
// 			    }
// 			    
// 
// 		    }
// 	    
// 		  if(flag!=1)
// 		  {
// 		    cvSet2D(Iat,y,x,ptr2);
// 		  } 
	  }
  //}
 
//   for(int x = 16;x<(Iat->width)-20;x++)
  {
//     
//       for(int y = 12;y<(Iat->height-8)-31;y++)
//       {
// 	double count = 0;
// 	for(int j = x;j<x+20;j++)
// 	{
// 	  
// 	    for(int i =y;i<y+31;i++)
// 	    {
// 		ptr = cvGet2D(Iat,i,j);
// 		
// 		if(ptr.val[0] <10.00)
// 		{
// 		  count++;
// 		  flag++;
// 		}
// 	    }
// 	      if(count/(20*31) > 0.32)
// 	      {
// 		  		for(int p = x;p<x+20;p++)
// 					{
// 						for(int m = y;m<y+31;m++)
// 						{
// 							cvSet2D(Iat,m,p,ptr2);
// 							
// 						}
// 					}
// 	      }
// 	}
// 	if(flag > 1)
// 	{
// 	 // x =x + 5;
// 	}
//       }
   }
  
  ptr2.val[0] = 250;
  ptr2.val[1] = 0;
  ptr2.val[2] = 0;
  for(int p = 0;p<5;p++)
  {
  for(int x = 0;x<Iat->width;x++)
  {
      for(int y = 0;y<Iat->height-1;y++)
      {
	ptr = cvGet2D(Iat,y,x);
	if(ptr.val[0] < 10)
	{
		int counter= 0;
		for(int z = x;z<Iat->width-1;z++)
		{
		    ptr = cvGet2D(Iat,y,z);
		    ptr3 = cvGet2D(Iat,y+1,z+1);
		    if(ptr.val[0] <10||ptr3.val[0] <10)
		    {
		      counter++;
		    }
		    else
		    {
			break;
		    }
		}
		      printf("Counter = %d\n",counter);		    
		
		if(counter>5)
		{
		    for(int z = x;z<counter;z++)
		    {
			cvSet2D(Iat,y,z,ptr2);
		    }
		}
	    
	}
      }
  }
  }
   bool isFlag = false;
  int xPos = 0;
  int yPos = 0;
  ptr3.val[0] = 200;
for(int x = 0;(x<Iat->width-16);x++)
{
  if(isFlag)
    break;
    for(int y = 0;(y<Iat->height-31);y++)
    {
      if(isFlag)
	break;
	  //  printf("%d",y);
	double count =0;
	for(int p = x;p<x+16;p++)
	{
	  for(int m = y;m<y+31;m++)
	  {
	      ptr = cvGet2D(Iat,m,p);
	      if(ptr.val[0] < 10)
	      {
		  count++;
	      }
	  }
	}
	
	if(count/(16*31) > 0.47)
	{
// 	    for(int p = x;p<x+16;p++)
// 	      for(int m = y; m<y+31;m++)
// 	      {
// 		  cvSet2D(Iat,m,p,ptr3);
// 	      }
	      printf("Value Found: \n");
	      
	      xPos = x;
	      yPos = y;
	     
	     isFlag = true;
	    
	}
    }
}


//xPos and yPos have the value of the initial character in the licence plate. 
 int xMiddle = 0;
 int yMiddle = 0;
 
 xMiddle = (xPos + 10);
 yMiddle = (yPos + 35/2);
 
 
int currPos = xPos + 20;
ptr = cvGet2D(Iat,yPos,currPos);

while(ptr.val[0] >10)
{
    currPos = currPos +1;
    ptr = cvGet2D(Iat,yPos,currPos);
  
}

 xPos = currPos;
 
 
 for(int d = xPos;d<xPos+20;d++)
   for(int f = yPos;f<yPos+35;f++)
   {
      cvSet2D(Iat,f,d,ptr3);
   }
  
 printf("Xpos = %d yPos = %d\n",xPos,yPos);
  
/*============================================================
	DESTROY ALL WINDOWS AND FREE MEMORY
==============================================================*/
cvSaveImage("testAdaptive.jpg",Iat);
cvShowImage("Adaptive Threshold", Iat);
cvWaitKey(0);
cvDestroyWindow("Adaptive Threshold");
system("wait");



return(0);
}

int nextCharacter(int xPos)
{
  
}