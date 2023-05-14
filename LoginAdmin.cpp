#include"LoginAdmin.h"
#include <fstream>
#include <stdlib.h>

bool LoginAdmin::validate(string name, string password)
{
	string name_, password_;
	bool flag = false;
	ifstream fin;
	fin.open("AdminLogin.txt",ios::app);
	fin >> name_ >> password_;

	while (!fin)
	{
		cout << "No such File exists !";
		break;
	}
	while (fin)
	{
		if (name == name_ && password == password_)
		{
			flag = true;
			break;
		}

		fin >> name_ >> password_;
	}
	fin.close();
	if (flag == true)
	{
		return true;
	}
	else
	{
		return false;
	}

	//sign-up
}

void LoginAdmin::enroll()
{
	string name_, pass_; bool flag = false;
	ofstream fout;
	fout.open("AdminLogin.txt",ios::app);

	cout << "Enter Name: "; cin >> name_;
	cout << "Enter Password: "; cin >> pass_;

	while (fout)
	{
		fout << name_<<endl;
		fout << pass_ << endl;
		flag = true;
		break;
	}

	fout.close();

	if (flag == true)
	{
		cout << "Registered Successfully as an Admin";

	}
	else {
		cout << "Unknown error ! Not Registered yet." << endl;
	}


}