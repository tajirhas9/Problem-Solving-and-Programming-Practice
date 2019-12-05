#include <iostream>
#include <vector>
using namespace std;
class customer
{
	int totalCost,totalItem;
	public: 
	static int custmr;
	vector <int> item[10000];
	int getCustomer();
	void increaseCustomer();
	void initialize();
	void addItem();
	void deleteItem();
	void display();
};
int customer::custmr=0;
void customer::initialize()
{
	totalCost=0;
	totalItem=0;
}
int customer::getCustomer()
{
	return custmr;
}
void customer::increaseCustomer()
{
	custmr++;
}
void customer:: addItem()
{
	int code,cost;
	cout << "Item Code: ";
	cin >> code;
	cout << "Item Cost: ";
	cin >> cost;
	totalCost += cost;
	item[code].push_back(cost);
	totalItem++;
}
void customer::deleteItem()
{
	int code;
	cout << "Item Code: ";
	cin >> code;
	totalCost -= item[code][0];
	totalItem--;
	item[code].clear();
}
void customer::display()
{
	cout << "Number of Items: " << totalItem << endl;
	cout << "Item Cost: " << totalCost <<endl;
}
int main()
{
	cout << "Welcome to The C Mart" << endl;
	customer person;
	while(1)
	{
		char choice;
		bool running = true;
		cout << "Enter 'N' for new customer and 'C' to close the counter: ";
		cin >> choice;
		if(choice == 'C' || choice == 'c')	break;
		person.increaseCustomer();
		person.initialize();
		while(running)
		{
			int c;
			cout << "To add new item enter 1" << endl;
			cout << "To delete item enter 2" << endl;
			cout << "To display total number of Item and cost enter 3" << endl;
			cout << "To exit enter 4" << endl;
			cout << "Enter your choice: ";
			cin >> c;
			switch(c)
			{
				case 1:
						person.addItem();
						break;
				case 2:
						person.deleteItem();
						break;
				case 3:
						person.display();
						break;
				case 4:
						running=false;
						break;
				default:
						cout << "Wrong Input" << endl;
						break;
			}
		}
	}
	cout << "Number of Customers Served today: " << person.getCustomer() << endl;
	return 0;
}
