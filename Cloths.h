#pragma once
#include <iostream>

using namespace std;
//the main class that contains the implmentation of the application.
class Cloths
{
private:
	string clothName, clothBrand, clothPrice, clothColor;
	int quantity = 0;
public:
	Cloths();
	void AddCloths(void);
	void SearchCloths(string name);
	void ShowInventory(void);
	void UpdateExistingClothRecord(string name);
	void DeleteExistingClothRecord(string name);
	void GenerateBill(string name);
	void AddToCart();
	void UndoFromCart();
	void payBill();
	//setters
	void setName(string name);
	void setBrand(string brand);
	void setPrice(string price);
	void setColor(string color);

	//getter
	string getName();
	string getBrand();
	string getPrice();
	string getColor();

};

