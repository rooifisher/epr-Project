#include <stdio.h>
#include "fann.h"
///Class used to create the neural network used for classifying the number plate characters (OCR)
int main( int argc, char** argv )
{
	const unsigned int num_input =900;
	const unsigned int num_output =36;
	const unsigned int num_layers = 3;
	unsigned int num_neurons_hidden = 100;
	const float desired_error= (const float) 0.01;
	const float desired_error_2= (const float) 0.009;
	const float desired_error_3= (const float) 0.001;
	const float desired_error_4= (const float) 0.0008;
	const float desired_error_5= (const float) 0.0003;
	const unsigned int max_epochs = 500000;
	const unsigned int epochs_between_reports = 10;


    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
     fann_set_activation_function_hidden(ann, FANN_ELLIOT);
     fann_set_activation_function_output(ann, FANN_ELLIOT);

	fann_train_on_file(ann,"train.dat",max_epochs,epochs_between_reports,desired_error);
	fann_save(ann, "number_plate_1.net");
	fann_train_on_file(ann,"train.dat",max_epochs,epochs_between_reports,desired_error_2);
	fann_save(ann, "number_plate_2.net");
	fann_train_on_file(ann,"train.dat",max_epochs,epochs_between_reports,desired_error_3);
	fann_save(ann, "number_plate_3.net");
	fann_train_on_file(ann,"train.dat",max_epochs,epochs_between_reports,desired_error_4);
	fann_save(ann, "number_plate_4.net");
	fann_train_on_file(ann,"train.dat",max_epochs,epochs_between_reports,desired_error_5);
	fann_save(ann, "number_plate_5.net");

    fann_destroy(ann);
	return 0;
}
