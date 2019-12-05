#include <bits/stdc++.h>
using namespace std;
void welcome(void);
void showOptions(void);
int check(int n);
bool func_login(void);
bool func_sign_up(void);
bool check_exist_user(string name);
bool verify_user(string name,string pass);
class member
{
	protected:
		string name,username,institution;
		string password;
		int age;
	public:
		string getUsername(void);
		bool check_pass(string pass);
		void set(string n,string u,string i,int a,string pass);
};
string member::getUsername(void)
{
	return username;
}
bool member::check_pass(string pass)
{
	if(pass == password)	return true;
	else 					return false;
}
void member::set(string n,string u,string i,int a,string pass)
{
	name = n;
	username = u;
	institution = i;
	age = a;
	password = pass;
}
set <string> name_list;
vector<member> users;
int user_index;
int main()
{
	int choice;
	welcome();
	while(1)
	{
		cout << endl << endl;
		showOptions();
		cin >> choice;
		cout << endl;
		if(choice==1)
		{
			if(func_login()==true)	break;
		}
		else if(choice==2)
		{
			if(func_sign_up()==true)	break;
		}
		else if(choice==3)	return 0;
		else
		{
			cout << "Wrong Input.Try Again." << endl;
		}
	}
	cout << "Welocome " << users[user_index].getUsername() << endl;
	return 0;
}
void welcome(void)
{
	cout << "-----------" << endl;
	cout << "Welcome!!!" << endl;
	cout << "-----------" << endl;
	cout << endl;
	cout << endl;
}
void showOptions(void)
{
	cout << "1.Login" << endl;
	cout << "2.Sign Up" << endl;
	cout << "3.Exit" << endl;
}
int check(int choice)
{
	switch(choice)
	{
		case 1:
			if(func_login()==false)	return 2;
			else 					return 1;
			break;
		case 2:
			func_sign_up();
			break;
		case 3:
			return 3;
	}
	return 1;
}
bool func_login(void)
{
	string name,pass;
	while(1)
	{
		cout << "Enter Username : ";
		cin >> name;
		cout << "Enter Password : ";
		cin >> pass;
		if(check_exist_user(name)==false)
		{
			cout << "Wrong username...Try again." << endl;
			return false;
		}
		else
		{
			if(verify_user(name,pass))
			{
				cout << endl;
				cout << "User Verified..." << endl;
				return true;
			}
			else
			{
				cout << endl;
				cout << "Wrong Password.Please sign up if you don't have an account or login with correct password." << endl;
				return false;
			}
		}
	}
}
bool check_exist_user(string name)
{
	set<string>::iterator it;
	for(it = name_list.begin(); it != name_list.end();it++)
	{
		if(*it==name)	return true;
	}
	return false;
}
bool func_sign_up(void)
{
	string name,username,password,institution;
	int age;
	getchar();
	cout << "Enter Name : ";
	getline(cin,name);
again:	cout << "Enter Username : ";
		cin >> username;
	if(check_exist_user(username))
	{
		cout << "Sorry..Username already exists.Try something else. :( " << endl;
		goto again;
	}
	cout << "How old are you? : ";
	cin >> age;
	cout << "Where do you study? : ";
	cin >> institution;
	cout << "Give a password to protect your account : ";
	cin >> password;
	name_list.insert(username);
	member user;
	user.set(name,username,institution,age,password);
	users.push_back(user);
	cout << endl;
	cout << "Sign Up Complete.Please login now...Welcome aboard! :) " << endl;
	return func_login();
}
bool verify_user(string name,string pass)
{
	for(int i=0;i<users.size();i++)
	{
		if(users[i].getUsername() == name)
		{
			if(users[i].check_pass(pass))
			{
				user_index = i;
				return true;
			}
		}
	}
	return false;
}
