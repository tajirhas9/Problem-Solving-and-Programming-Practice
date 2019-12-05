#include <bits/stdc++.h>
using namespace std;
#define MIN_BALANCE 500
#define SERVICE_CHARGE 50
typedef long long ll;
class account
{
	protected:
		string name,acc_type;
		ll acc_number;
		double balance;
	public:
	void get_data(void)
	{
		getchar();
		cout << "Enter Client Name: ";
		getline(cin,account::name);
		cout << "Enter A/C No.: ";
		cin >> account::acc_number;
		cout << "A/C type: ";
		cin >> account::acc_type;
		again: cout << "Opening Balance: ";
		cin >> account::balance;
		if(balance<500)
		{
			cout << "Opening Balance should be minimum 500 taka.Please try again." << endl;
			goto again;
		}
	}
	void deposit(void)
	{
		ll money;
		cout << "    " << "Enter the amount to deposit: ";
		cin >> money;
		cout << endl << endl;
		account::balance += money;
	}
	void info_display(void)
	{
		cout << "Displaying Client Details" << endl;
		cout << "    " << "Client Name: " << account::name << endl;
		cout << "    " << "A/C No.: " << account::acc_number << endl;
		cout << "    " << "A/C Type: " << account::acc_type << endl;
		cout << "    " << "A/C Balance: " << account::balance << endl;
		cout << endl << endl;
	}
};
class savings:public account
{
	public: 
	ll menu_display(void)
	{
		ll c;
		cout << "Press" << endl;
		cout << "    " << "1 to display information" << endl;
		cout << "    " << "2 to diposit an amount" << endl;
		cout << "    " << "3 to withdraw an amount" << endl;
		cout << "    " << "4 to add interest" <<endl;
		cout << "    " << "5 to exit" << endl;
		cout << "     " << "Your Choice: ";
		cin >> c;
		return c;
	}
	void withdraw(void)
	{
		ll money;
		cout << "    " << "Enter the amount to withdraw: ";
		cin >> money;
		if((account::balance - money)<500)
		{
			cout << "    " << "The amount cannot be withdrawn" << endl;
		}
		else
		{
			account::balance -= money;
		}
		cout << endl << endl;
	}
	void add_interest(void)
	{
		ll time;
		double extra;
		cout << "Adding Interest" << endl;
		cout << "    " << "Enter time(in Years): ";
		cin >> time;
		extra = 1;
		for(ll i=1;i<=time;i++)	extra *= 1.1;
		balance = (account::balance*extra);
	}
};
class current:public account
{
	public:
	ll menu_display(void)
	{
		ll c;
		cout << "Press" << endl;
		cout << "    " << "1 to display information" << endl;
		cout << "    " << "2 to diposit an amount" << endl;
		cout << "    " << "3 to withdraw an amount" << endl;
		cout << "    " << "4 to exit" << endl;
		cout << "     " << "Your Choice: ";
		cin >> c;
		return c;
	}
	void withdraw(void)
	{
		ll money;
		cout << "    " << "Enter the amount to withdraw: ";
		cin >> money;
		if((account::balance - money)<0 || ((account::balance-money-SERVICE_CHARGE)<0))
		{
			cout << "    " << "No penalty imposed" << endl;
			cout << "    " << "The amount cannot be withdrawn" << endl;
		}
		else if((account::balance-money)<MIN_BALANCE && (account::balance-money)>=50)
		{
			account::balance -= money;
			account::balance -= SERVICE_CHARGE;
			cout << "    " << "Penalty imposed" << endl;
		}
		else
		{
			account::balance -= money;
		}
		cout << endl << endl;
	}
};
int main()
{
	int choice;
	while(1)
	{
		cout << "Opening an A/C" << endl;
		cout << "Press" << endl;
		cout << "    " << "1 for opening a Curent A/C" << endl;
		cout << "    " << "2 for opening a Savings A/C" << endl;
		cout << "    " << "Your Choice: ";
		cin >> choice;
		if(choice==1)
		{
			current client;
			client.get_data();
			while(1)
			{
				ll op;
				op = client.menu_display();
				if(op==4)	return 0;
				else if(op==1)
					client.info_display();
				else if(op==2)
					client.deposit();
				else if(op==3)
					client.withdraw();
			}
		}
		else if(choice==2)
		{
			savings client;
			client.get_data();
			while(1)
			{
				ll op;
				op = client.menu_display();
				if(op==5)	return 0;
				else if(op==1)
					client.info_display();
				else if(op==2)
					client.deposit();
				else if(op==3)
					client.withdraw();
				else if(op==4)
					client.add_interest();
			}
		}
	}
	return 0;
}
