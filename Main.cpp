#include<iostream>
#include "LoginAdmin.h"
#include "LoginCustomer.h"
#include "Cloths.h"
using namespace std;

//that is the main starting point for the application.
int main()
{
	int choiceAdminCustomer;
	LoginAdmin l;
	LoginCustomer c;
	Cloths cloth;
	cout << "\t\tWelcome to Vira Clothings! Choose Any of the following to proceed" << endl;
	string name, password;
	
	cout << "\n\t1 - Admin" << endl;
	cout << "\n\t2 - Customer"<<endl;
	cout << "\n\t3- Exit" << endl;
	cin >> choiceAdminCustomer;

	switch(choiceAdminCustomer)
	{
	case 1:
	{
		int choiceAdmin;
		cout << "Hello dear Admin, Please select one from the following"<<endl;

		cout << "1- Login"<<endl;
		cout << "2- Sign - Up"<<endl;
		
		cin >> choiceAdmin;
		switch (choiceAdmin)
		{
		case 1:
		{

			cout << "Please Enter Name:"; cin >> name;
			cout << "Please Enter Password:"; cin >> password;

			if (l.validate(name, password) == true)
			{
				int adminInventoryChoice;
				system("cls");
				cout << "\t\tHello dear, " << name <<" Select from the following !" << endl;
				cout << "1- Add Cloth record"<<endl;
				cout << "2- Search Cloth record"<<endl;
				cout << "3- Update Cloth record"<<endl;
				cout << "4- Display Inventory"<<endl;
				cout << "5- Delete Cloth record" << endl;
				cout << "6- Generate Bill" << endl;
				cout << "7- Add to cart"<< endl;
				cout << "8- Main menu" << endl;
				cin >> adminInventoryChoice;

				switch (adminInventoryChoice)
				{
				case 1:
				{
					cloth.AddCloths();
					system("PAUSE");
					system("cls");
					break;
				}
				case 2:
				{
					string name;
					cout << "Enter The Cloth Name you want to search: "; cin >> name;
					cloth.SearchCloths(name);
					system("PAUSE");
					system("cls");
					break;
				}
				case 3:
				{
					string name;
					cout << "Enter The Cloth Name you want to update: "; cin >> name;
					cloth.UpdateExistingClothRecord(name);
					system("PAUSE");
					system("cls");
					break;

				}
				case 4:
				{
					cloth.ShowInventory();
					system("PAUSE");
					system("cls");
					break;
				}
				case 5:
				{
					string name;
					cout << "Enter The Cloth Name you want to delete: "; cin >> name;
					cloth.DeleteExistingClothRecord(name);
					system("PAUSE");
					system("cls");
					break;
				}
				case 6:
				{
					cloth.GenerateBill(name);
					system("PAUSE");
					system("cls");
					break;
				}
				case 7:
				{
					cloth.AddToCart();
					system("PAUSE");
					system("cls");
					break;
				}
				case 8:
				{
					main();
				}
				default:
				{
					cout << "Invalid Choice.., Press any key for Main Menu"<<endl;
					system("PAUSE");
					system("cls");
					break;
				}
					break;
				}

			}
			else
			{
				cout << "No such user exists!"<<endl;
				system("PAUSE");
				system("cls");
				main();
			}
			break;
		}
		case 2:
		{
			l.enroll();
			system("cls");
			main();
		}
		
	default:
		{
			cout << "Invalid Choice";
			main();
		}
		}

		break;
	}
	case 2:
	{
		int choiceCustomer=0; 
		string name;
		cout << "Please Enter Your Name: "; cin >> name;
		cout << "\n\nHello dear "<<name<<" Please select one from the following" << endl;

		cout << "\t1- Become a Permanent User and receive Notifications" << endl;
		cout << "\t2- Guest User" << endl;
		
		cin >> choiceCustomer;
		switch (choiceCustomer)
		{
		case 1:
		{
			char check = 'y';
			int choice;
			c.enrollCustomer();
			cout << "\nWould You like to continue Shopping(y/n): "; cin >> check;
			if (check == 'y')
			{
				cout << "Select Any of the following !"; 
				cout << "1- View Shop Items" << endl;
				cout << "2- Pay Bill Amount" << endl;
				cout << "3- Add to Cart" << endl;
				cout << "4- Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cloth.ShowInventory();
					system("PAUSE");
					system("cls");
					main();
				}
				case 2:
				{
					cloth.payBill();
					system("PAUSE");
					system("cls");
					main();
				}
				case 3:
				{
					cloth.AddToCart();
					system("PAUSE");
					system("cls");
					main();
				}
				case 4:
				{
					return 0;
				}
				default:
				{
					cout << "Invalid Choice ! " << endl;
					system("PAUSE");
					system("cls");
					main();
				}
				
				}
			}
			else
			{
				main();
			}
			
		}
		case 2:
		{
			int choice2;
			cout << "Select Any of the following !"<<endl; 
			cout << "1- View Shop Items" << endl;
			cout << "2- Pay Bill Amount" << endl;
			cout << "3- Add to Cart" << endl;
			cout << "4- Exit" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
			{
				cloth.ShowInventory();
				system("PAUSE");
				system("cls");
				main();
			}
			case 2:
			{
				cloth.payBill();
				system("PAUSE");
				system("cls");
				main();
			}
			case 3:
			{
				cloth.AddToCart();
				system("PAUSE");
				system("cls");
				main();
			}
			case 4:
			{
				system("cls");
				main();

			}
			default:
			{
				cout << "Invalid Choice ! " << endl;
				system("PAUSE");
				system("cls");
				main(); 
			}
			}
			


		}
		}
	}
	case 3:
	{
		cout << "thank you for visiting...Hope to see you soon."<<endl;
		system("PAUSE");
		exit(0);
	}
defualt:
	{

	}
	}

	
	return 0;
}
