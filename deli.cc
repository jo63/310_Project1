#include <stdio.h> 	
#include <unistd.h> 
#include <assert.h> 


char* input_files;
int cork_board_max, cashier_count;



void main (int argc, char *argv[]){
	// Checks that there are enough inputs
	if (argc <= 2) {
		printf('More Inputs Required');
		return; 
	}
	
	// Initializes Standard Global Variables
	cork_board_max = argv[1]; 
	cashier_count = argc - 2;
	input_files = (char*) argv[2];
	
	
	
	
	
	
	
	return; 
}