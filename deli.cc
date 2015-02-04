#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Class for each Cashier thread
class Cashier {

	public:

		vector<int> orderList;

		int cur_order;

		bool isEmpty(){
			if (orderList.size() == 0) return true;
			return false;
		}

		int getNextOrder(){
			int temp = orderList.at(cur_order);
			cur_order++;
			return temp;
		}

};


char** input_files;
int cork_board_max, cashier_count;

void readFile(vector<Cashier> cashiers){

	vector<double> Main;
    int count;
    string lineData;
    double tmp;

    for(int i=0;i<cashier_count;i++)
    {
    	//store this into a vector ifstream myfile (input_files[i], ios::in);
    	vector<int> orders;
    	ifstream infile;

    	char* t = input_files[i+2];
		cout << t; 
    	ifstream read(t);
    	int temp;
    	while(read>>temp)
    	{
    		orders.push_back(temp);
    	}

    	Cashier c = new Cashier(orders);
    	cashiers.push_back(c);
    }

}


void main (int argc, char** argv[]){
	// Checks that there are enough inputs
	if (argc <= 2) {
		cout << 'More Inputs Required';
		return;
	}

	// Initializes Standard Global Variables
	cork_board_max = argv[1];
	cashier_count = argc - 2;
//	input_files = (char*) (argv + 2);
	input_files = argv;


	std::vector<Cashier> cashiers;
	readFile(cashiers);





	return;


}
