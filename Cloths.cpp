#include "Cloths.h"
#include <iostream>
#include <fstream>
using namespace std;

//implementst he methods of Cloth.h
//default constructor
Cloths::Cloths()
{
	clothName = "";
	clothBrand = "";
	clothPrice = "";
	clothColor = "";
}
 
void Cloths::AddCloths()
{
	Cloths c[10];
	ofstream fout;
	fout.open("Cloths.txt",ios::app);
	int recordNow, counter = 1;
	cout << "Enter the number of records you want to add NOW: "; cin >> recordNow;
	for (int i = 0; i < recordNow; i++)
	{
		//string clothName, clothBrand, clothPrice, clothColor;
		cout << "Enter Cloth " << counter << " Name: "; cin >> c[i].clothName;
		fout << c[i].clothName<<endl;
		cout << "Enter Cloth " << counter << " Brand: "; cin >> c[i].clothBrand;
		fout << c[i].clothBrand<<endl;
		cout << "Enter Cloth " << counter << " Price: "; cin >> c[i].clothPrice;
		fout << c[i].clothPrice << endl;
		cout << "Enter Cloth " << counter << " Color: "; cin >> c[i].clothColor;
		fout << c[i].clothColor << endl;
		
		counter++;
		system("cls");
	}

	fout.close();
	if (counter > 1)
	{
		cout << "Records Added Successfully"<<endl;
	}
	else {
		cout << "No Records are Added";
	}
}
void Cloths::SearchCloths(string name)
{
	Cloths c;
	ifstream fin;
	bool flag = false;

	fin.open("Cloths.txt");

	//string clothName, clothBrand, clothPrice, clothColor;
	fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;
	while (!fin)
	{
		cout << "No Such "<<name<< " available!";
		break;
	}

	int holder = 0;
	while (fin)
	{
		if (c.clothName == name)
		{
			cout << "Name: " << c.clothName << endl;
			cout << "Brand: " << c.clothBrand << endl;
			cout << "Price: " << c.clothPrice << endl;
			cout << "Color: " << c.clothColor << endl;
			cout << "=======================================" << endl;
			flag = true;
		}
	fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;
	}


	if (flag == false)
	{
		cout<<"Sorry, No such " << name << " Found!" << endl;
	}
	fin.close();
}
void Cloths::ShowInventory()
{
	Cloths c;
	ifstream fin;
	fin.open("Cloths.txt");
	//string clothName, clothBrand, clothPrice, clothColor;
	fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;

	//bool flag = false; can be used in future.

	while (!fin)
	{
		cout << "Inventory is empty" << endl;
		break;
	}

	while (fin)
	{
		cout << "Name: " << c.clothName << endl;
		cout << "Brand: " << c.clothBrand << endl;
		cout << "Price: " << c.clothPrice << endl;
		cout << "Color: " << c.clothColor << endl;
		cout << "=======================================" << endl;
		fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;
	}

	fin.close();
}
void Cloths::UpdateExistingClothRecord(string name)
{

	Cloths c;
	ifstream fin;
	ofstream fout;

	bool flag = false;

	fin.open("Cloths.txt");
	fout.open("temp.txt", ios::app);

	//string clothName, clothBrand, clothPrice, clothColor;
	fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;

	while (!fin)
	{
		cout << "Inventory is empty";
	}

	while (fin)
	{
		if (c.clothName == name)
		{
			system("cls");
			cout << "Record Found !"<<endl;
			cout << "Enter New Name: "; cin >> c.clothName;
			cout << "Enter Brand: "; cin >> c.clothBrand;
			cout << "Enter Price: "; cin >> c.clothPrice;
			cout << "Enter Color: "; cin >> c.clothColor;

			//sending to temp.txt
			fout << c.clothName << endl;
			fout << c.clothBrand << endl;
			fout << c.clothPrice << endl;
			fout << c.clothColor << endl;
			flag = true;
			break;
		}
		else if (c.clothName != name)
		{
			fout << c.clothName << endl;
			fout << c.clothBrand << endl;
			fout << c.clothPrice << endl;
			fout << c.clothColor << endl;

		}

		fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;
	}

	if (flag == false)
	{
		cout << "No Such Book Found, Please review the name and try again !";
		return;
		cout << endl;
	}
	else {
		cout << "Record Updated Successfully"<<endl;
	}

	fin.close();
	fout.close();
	remove("Cloths.txt");
	rename("temp.txt","Cloths.txt");

}
void Cloths::DeleteExistingClothRecord(string name)
{
	Cloths c;
	ifstream fin;
	ofstream fout;

	bool flag = false;

	fin.open("Cloths.txt");
	fout.open("temp1.txt",ios::app);

	//string clothName, clothBrand, clothPrice, clothColor;
	fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;

	while (fin)
	{
		if (c.clothName != name)
		{
		fout << c.clothName << endl;
		fout << c.clothBrand << endl;
		fout << c.clothPrice << endl;
		fout << c.clothColor << endl;
		}
		else
		{
			flag = true;
		}
		fin >> c.clothName >> c.clothBrand >> c.clothPrice >> c.clothColor;
	}

	if (flag == true)
	{
		cout << "The Cloth Record has been deleted successfully !"<<endl;
	}
	else
	{
		cout << "No Such Record Found"<<endl;
	}
	

	fin.close();
	fout.close();

	remove("Cloths.txt");
	rename("temp1.txt","Cloths.txt");
}
void Cloths::AddToCart()
{
	quantity = quantity++;
	cout << "Added 1 Item Successfully to cart "<<endl;
}
void Cloths::UndoFromCart()
{
	quantity--;
}
void Cloths::GenerateBill(string name)
{
	if (quantity == 0)
	{
		int ch = 0;
		cout << "Cart is empty!, Add items to Cart? Enter Quantity Press 0 to go back to Main Menu: "; cin >> ch;
		if (ch == 0)
		{
			return;
		}
		quantity += ch;
	}
	int q, tot = 0, amount = 0;
	cout << "Hello dear " << name<<endl;
	cout << "Enter Number of Elements For Which the Bill is suppossed to be generated: "; cin >> q;

	for (int i = 0; i < q; i++)
	{
		cout << "Enter Amount for Item " << i + 1<<": "; cin >> amount;
		tot += amount;
	}
	
	cout << "Total Amount to be paid: " << tot<<endl;
}
void Cloths::payBill()
{
	cout << "Bill Payed Successfully!" << endl;
}
