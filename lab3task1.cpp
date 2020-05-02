#include<iostream>
using namespace std;
void f1(int ) {
	cout << "1. просмотр  задания\n";
}
void f2(int ) {
	cout << "2. просмотр  задания\n";
}
void f3(int ) {
	cout << "3. просмотр  задания\n";
}
void f4(int ) {
	cout << "4. просмотр  задания\n";
}
int prompt_menu_item()
{
                     
    setlocale(0, "ru");
    

    int variant;
    cout << "Выберите вариант\n" << endl;
	cout << "1. просмотреть первое задание\n"
		<< "2. просмотреть второе задание\n"
		<< "3. просмотреть третье задание\n"
		<< "4. просмотреть четвертое задание\n" << endl;
    cout << ">>> ";
    cin >> variant;
    return variant;
}

int main()
{
	setlocale(0, "ru");

	void (*p[4])(int) = { f1,f2,f3,f4 }; // declare point on funtions		
	        // for menu
    int variant = prompt_menu_item();
	variant--;
	 (*p[variant])(variant);
	 
	switch (variant)
	{
	case 0:
		cout << "Упражнение 1: смотреть в книге на стр.56"<<endl;

		break;

	case 1:

		cout << "Упражнение 2: смотреть в книге на стр.57" << endl;

		break;
	case 2:

		cout << "Упражнение 3: смотреть в книге на стр.58" << endl;

		break;

	case 3:

		cout << "Упражнение 4: смотреть в книге на стр.59" << endl;

		break;
	}
	
	
	system("pause");
	return 0;
}

