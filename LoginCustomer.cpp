#include "LoginCustomer.h"
#include <fstream>
#include <stdlib.h>
using namespace std;
//implementes the loginCustomer.h
void LoginCustomer::enrollCustomer()
{
	string name_, mail_;
	bool flag = false;

	//opening file to save the data
	ofstream fout;
	fout.open("CustomerLogin.txt",ios::app);

	cout << "Enter Name: "; cin >> name_;
	cout << "Enter Email: "; cin >> mail_;


	while (fout)
	{
		fout << name_ << endl;
		fout << mail_ << endl;
		flag = true;
		break;
	}

	fout.close();

	if (flag == true)
	{
		cout << "Registered Successfully as a Customer";
	}
	else {
		cout << "Unknown error ! Not Registered yet." << endl;
	}

}
