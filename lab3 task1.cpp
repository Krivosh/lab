#include <iostream>
#include <Windows.h>

using namespace std;

void f1(double)
{
	cout << "1. просмотреть  задание\n";	
	cout << "2x+7y=64 " ;
}
void f2(double)
{
	cout << "2. просмотреть задание\n";	
	cout << "17x+18y=256 " ;
}
void f3(double)
{
	cout << "3. просмотреть  задание\n";	
	cout << "3x+18y=25 " ;
}
void f4(double)
{
	cout << "4. просмотреть  задание\n";	
		cout << "7x+y=56 " ;
}
void f5(double)
{
	cout << "5. просмотреть  задание\n";
	cout << "7x+7=x ";
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	void (*P[5])(double) = { f1,f2,f3,f4,f5 };
	cout << " Выбор задания!!!\n ";
	cout << "1.просмотреть  задание\n";
	cout << "2.просмотреть задание\n";
	cout << "3.просмотреть задание\n";
	cout << "4.просмотреть задание\n";
	cout << "5.просмотреть задание\n";
	int a;
	cin >> a;
	a--;
	(*P[a])(a);
	system("pause");
	return 0;
