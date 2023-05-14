#include <iostream>
#include<fstream>

using namespace std;

int main()
{
ifstream fin;
string name, pass;
fin.open("AdminLogin.txt");
fin >> name >> pass;

while(fin)
{
	if(name == "wasid" && pass == "pak@123")
	{
		cout<<true;
		break;
	}
	
	
fin >> name >> pass;	
}


return 0;
}

