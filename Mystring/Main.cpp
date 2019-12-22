#include"MyString.h"

int main()
{
	Mystring nhap;
	cout << "Nhap chuoi bat ky: ";
	getline(cin, nhap);
	cout << "Chuoi vua nhap la: " << nhap << endl << endl;


	Mystring chuoi = "Nguyen Duc Truc - 18CTT5 - 18120621 ";
	cout << chuoi << endl;

	chuoi = "Nguyen Duc Truc";
	for (Iterator it = chuoi.begin(); it != chuoi.end(); ++it)
		cout <<"  "<<*it << endl;

	chuoi = "OOP tren 7. 2019 - 2020.";
	cout << chuoi << endl;


	system("pause");
	return 0;
}