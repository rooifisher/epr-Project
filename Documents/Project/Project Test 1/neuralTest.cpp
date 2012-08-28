#include "fann.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	float max = 0;
	int numCount = 0;
	char characters[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
	fann_type *calc_out;
	fann_type input[900];
	ifstream fin("test.dat");
	int count = 0;
	string str;
	while(fin >> str)
	{
		if(count<900)
		input[count] = ::atof(str.c_str());
		else;		
	
		count++; 
	}

    struct fann *ann = fann_create_from_file("number_plate_5.net");
	
	calc_out = fann_run(ann,input);


	for(int i =0; i<35;i++)
	{
		printf("%f ",calc_out[i]);

	}



	for(int i = 0; i<35;i++)
	{
		if(calc_out[i] > max)
		{
			
			max = calc_out[i];
			numCount = i;
			
		
		}
		
	}

	printf("\nThe character is a %c \n",characters[numCount]);
	return 0;
}
