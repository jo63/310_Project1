#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
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
		
		stringstream ss;
		char* t = (char*) input_files[i+2];
		int counter = 0;
		while(t[counter] ~= ' ')
		{
			ss << t[counter];
		}
		
    	cout << ss;
    	ifstream read(ss);
    	int temp;
    	while(read>>temp)
    	{
    		orders.push_back(temp);
    	}

//    	Cashier c = new Cashier(orders);
//    	cashiers.push_back(c);
    }

}


int main (int argc, char** argv){
	// Checks that there are enough inputs
	if (argc <= 2) {
		cout << "More Inputs Required";
		return 0;
	}

	// Initializes Standard Global Variables
	cork_board_max = atoi(argv[1]);
	cashier_count = argc - 2;
//	input_files = (char*) (argv + 2);
	input_files = argv;


	std::vector<Cashier> cashiers;
	readFile(cashiers);



	return 0;


}
