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

//encapsulation of order number as well as the cashier the order came from.
struct Order {
    int order_num;
    int cashier_num;
};

// Class for each Cashier thread
class Cashier {

	public:

		vector<Order> orderList; // BE SURE TO INDEX INTO THE ORDERLIST TO ACCESS SEPARATE ORDER

		int cur_order;

		bool isEmpty(){						// THIS WORKS
			if (orderList.size() == cur_order) return true;
			return false;
		}

		int getNextOrder(){ //THIS WORKS
			int temp = orderList.at(cur_order);
			cur_order++;
			return temp;
		}

};

class Corkboard {
    private:
        int max_size;
	public:
    veector<Order> orders; //this needs to be a vector because you dont know how many orders are already in the corkboard when you add a new order...or do you? :S
    Corkboard(int max_size)
    {
        max_size = max_size;
    }
    void addOrder(Order new_order) {
        if(orders.size() == max_size)
            cout << "Cork board at max capacity";
        orders.push_back(new_order);
        sortBoard();
    }
    
    //below is sorting the board everytime a new order is added; defined own comparator to compare order number only.
    bool compare(Order i, Order j) (return (i.order_num<j.order_num);)
    void sortBoard()
    {
        orders.sort(orders.begin(), orders.end(), compare);
        //TODO: sort the corkboard
    }


};



char** input_files;
int cork_board_max, cashier_count;

vector<Cashier*> readFile(){	//THIS WORKS

	vector<Cashier*> cashiers;

    for(int i=0;i<cashier_count;i++)
    {
    	//store this into a vector ifstream myfile (input_files[i], ios::in);
    	vector<int> orders;
    	ifstream infile;

		char* t = (char*) input_files[i+2];

		ifstream read(t);

    	int temp;
    	while(read>>temp)
    	{
    		orders.push_back(temp);

    	}

    	Cashier* c = new Cashier;
    	c->orderList = orders;

    	cashiers.push_back(c);
    }
//		UNCOMMENT FOR DEBUGGING
//    for (int i =0; i < cashier_count; i++){
//    	cout << cashiers[i]->orderList[0];
//    }

    return cashiers;

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
	input_files = argv;

	std::vector<Cashier*> cashiers;
	cashiers = readFile();


//	UNCOMMENT FOR DEBUGGING
//	for (int i = 0; i < cashier_count; i++){
//		cout << cashiers[i]->getNextOrder() << endl;
//		cout << cashiers[i]->getNextOrder() << endl;
//		if (cashiers[i]->isEmpty()){
//			cout << "IS EMPTY!" << endl;
//		}
//		cout << "end of" << i << "loop" << endl;
//	}

	return 0;


}
