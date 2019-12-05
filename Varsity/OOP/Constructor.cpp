#include <bits/stdc++.h>
using namespace std;
class student
{
	string stdName,stdNo,dateOfBirth;
	int tariff;
	public :
	static int totalStd;
	student(void)
	{
		stdName = "Not Known";
		stdNo = "Not Known";
		dateOfBirth = "1st January 1995";
		tariff = 20;
		totalStd++;
	}
	student(string no,string name,string dOb,int t)
	{
		stdNo = no;
		stdName = name;
		dateOfBirth = dOb;
		tariff = t;
		totalStd++;
	}
	void display(void)
	{
		cout << stdNo << "        " << stdName << "\t" << dateOfBirth << "\t" << tariff << endl<< endl;
	}
	int getTotal()
	{
		return totalStd;
	}
};
int student::totalStd = -1000;
int main()
{
	int i=0;
	student std[1000];
	while(1)
	{
		int choice;
		cout << "Press" << endl;
		cout << "\t1 for creating student instance with unknown value." << endl;
		cout << "\t2 for creating student instance with known value." << endl;
		cout << "\t3 to display." << endl;
		cout << "\t4 to exit." << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		getchar();
		if(choice == 4)	break;
		else if(choice == 1)
		{
			i++;
			std[i] = student();
		}
		else if(choice == 2)
		{
			i++;
			string name,no,dOb;
			int tariff;
			cout << "Enter Student Details:" << endl;
			cout << "\tStudent No: ";
			cin >> no;
			getchar();
			cout << "\tName: ";
			getline(cin,name);
			cout << "\tDate of Birth: ";
			getline(cin,dOb);
			cout << "\tTariff Points: ";
			cin >> tariff;
			getchar();
			if(tariff < 20 || tariff > 280)
			{
				cout << "Invalid Tariff Point." << endl;
				cout << "Please enter the correcct Tariff Point: ";
				cin >> tariff;
				getchar();
			}
			std[i] = student(no,name,dOb,tariff);
		}
		else if(choice == 3)
		{
			int j;
			cout << "Student No\t\tName\t\t\tDate of Birth\t\tTariff Points\n";
			for(j=1;j<=i;j++)
			{
				std[j].display();
			}
			cout << "Number of Instance Created: " << std[0].getTotal() << endl;
		}
		else
		{
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}
