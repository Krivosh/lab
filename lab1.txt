#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

// Структрура, хранящая данные о студентах

struct students
{
	char address[256]; // домашний адрес
	char last_name[256], name[256], dadname[256]; // фамилия, имя, отчество
	int num; //количество студентов
	int student_number;
	int group_number;

};
enum num {
	EMPTY = 1,
	ALMOST_EMPTY,
	HALF,
	ALMOST_COMPLETE,
	COMPLETE
};

// выведение сведений о данном студенте (1)

void output_pac(students pac)
{
	cout << "Пациент №" << pac.num << endl << endl;
	cout << "Фамилия: " << pac.last_name << endl;
	cout << "Имя: " << pac.name << endl;
	cout << "Отчество: " << pac.dadname << endl;
	cout << "Домашний адрес: " << pac.address << endl;
	cout << "Номер  студента: " << pac.student_number << endl;
	cout << "Номер группы : " << pac.group_number << endl << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	students* pac = new students[5]; // указатель для массива структур
	int pac_num; // количество студентов
	double ispac = false; // показывает, существует ли студент
	while (1)
	{
		system("cls");

		// меню 

		int input_menu;
		cout << " 1. Ввод массива студентов\n";
		cout << " 2. Вывод массива студентов\n";
		cout << " 3. Сортировка массива студентов\n";
		cout << " 4. Поиск в массиве студентов по заданному параметру\n";
		cout << " 5. Изменение заданного студента\n";
		cout << " 6. Удаление студентов из массива\n";
		cout << " 7. Выход\n";
		cout << "Ввод: "; cin >> input_menu;
		system("cls");

		// если нужно ввести массив структур

		if (input_menu == 1)
		{
			ispac = true;

			// создание массива с заданным количеством студентов

			cout << "Введите количество студентов: "; cin >> pac_num;
			pac = new students[pac_num];

			// заполнение структуры каждого студента

			for (int i = 0; i < pac_num; i++)
			{
				system("cls");
				pac[i].num = i + 1;
				cout << "Студент №" << pac[i].num << endl << endl;

				// фамилия, имя, отчество

				cout << "Введите фамилию: "; cin >> pac[i].last_name; cout << endl;
				cout << "Введите имя: "; cin >> pac[i].name; cout << endl;
				cout << "Введите отчество: "; cin >> pac[i].dadname; cout << endl;

				// домашний адрес


				cout << "Введите домашний адрес: "; cin >> pac[i].address; cout << endl;

				// номер студента

				cout << "Введите номер студента: ";
				cin >> pac[i].student_number;
				cout << endl;


				// номер группы

				cout << "Введите номер группы: ";
				cin >> pac[i].group_number;
				cout << endl;
				system("cls");
			}
			system("cls");
		}

		// если нужно вывести массив структур (2)

		else if (input_menu == 2)
		{

			// если студентов нет, то можно выполнить только 1-й пункт

			if (!ispac) { cout << "Error!"; Sleep(1000); continue; }

			// вывод массива структур

			for (int i = 0; i < pac_num; i++)
			{
				output_pac(pac[i]);
			}
			system("pause");
		}

		// если нужно сортировать массив структур (3)

		else if (input_menu == 3)
		{

			// если студентов нет

			if (!ispac || (pac_num < 2)) { cout << "Error!"; Sleep(1000); continue; }

			// сортировкаа по фамилии

			cout << " Сортировка по фамилии \n Ввод: ";
			students pac_copy; //копия студента
			for (int i = 0; i < (pac_num - 1); i++)
			{
				if (pac[i].last_name[0] > pac[i + 1].last_name[0])
				{
					int pac_i_num = pac[i].num;
					pac[i].num = pac[i + 1].num;
					pac[i + 1].num = pac_i_num;
					pac_copy = pac[i];
					pac[i] = pac[i + 1];
					pac[i + 1] = pac_copy;
				}
				else
				{
					cout << "Error sorting!"; continue;
				}
			}
			system("cls");
			cout << "Good!";
			Sleep(1000);
		}

		// если нужно производить поиск в массиве по заданному параметру (4)

		else if (input_menu == 4)
		{
			if (!ispac) { cout << "Error!"; Sleep(1000); continue; } // если студента нет
			int type_search; // параметр поиска
			cout << " 1. По фамилии\n 2. По имени\n 3. По отчеству\n 4. По адресу\n 5. По номеру студента\n 6. По номеру группы\nВвод: ";
			cin >> type_search;
			system("cls");

	                                  	// поиск по фамилии
			if (type_search == 1)
			{
				char last_name[100] = ""; cout << "Ввод: "; cin >> last_name;
				system("cls");
				for (int i = 0; i < pac_num; i++) {
					if (!strcmp(last_name, pac[i].last_name)) 
					{                                              //(strcmp - сравнение двух строк)
						output_pac(pac[i]);
					}
					system("pause");
				}
			}

			// поиск по имени

			else if (type_search == 2)
			{
				char name[100] = ""; cout << "Ввод: "; cin >> name;
				system("cls");
				for (int i = 0; i < pac_num; i++) {
					if (!strcmp(name, pac[i].name)) 
					{
						output_pac(pac[i]);
					}
					system("pause");
				}
			}

			// поиск по отчеству

			else if (type_search == 3)
			{
				char dadname[100] = ""; cout << "Ввод: "; cin >> dadname;
				system("cls");
				for (int i = 0; i < pac_num; i++)
				{
					if (!strcmp(dadname, pac[i].dadname))
					{
						output_pac(pac[i]);
					}
					system("pause");
				}
			}

			// поиск по адресу

			else if (type_search == 4)
			{
				char address[100] = ""; cout << "Ввод: "; cin >> address;
				system("cls");
				for (int i = 0; i < pac_num; i++) {
					if (!strcmp(address, pac[i].address))
					{
						output_pac(pac[i]);
					}
					system("pause");
				}
			
			}

			// поиск по номеру студента

			else if (type_search == 5)
			{
				long long student_number; cout << "Ввод: "; cin >> student_number;
				system("cls");
				for (int i = 0; i < pac_num; i++) 
				{
					if (student_number == pac[i].student_number)
					{
						output_pac(pac[i]);
					}
					system("pause");
				}
			}

			// поиск по номеру группы

			else if (type_search == 6)
			{
				int group_number; cout << "Ввод: "; cin >> group_number;
				system("cls");
				for (int i = 0; i < pac_num; i++)
				{
					if (group_number == pac[i].group_number)
					{
						output_pac(pac[i]);
					}
					system("pause");
				}
			}
			else
			{
				cout << "Error searching!"; continue;
			}
			system("cls");
			cout << "Good!";
			Sleep(1000);
		}

		// если нужно изменить заданную структуру (5)

		else if (input_menu == 5)
		{
			if (!ispac)
			{
				cout << "Error!"; Sleep(1000); // если студентов нет
				continue;
			}
			int num; // номер студента
			cout << "Номер студента: "; cin >> num;
			int i = num - 1; // номер студента - 1 (для работы с массивом)
		
			if (num > pac_num || num == 0)// если неправильно введен номер студента
			{
				cout << "Error!";
				continue;
			}
			system("cls");
			cout << "Студент №" << pac[i].num << endl << endl;

			// фамилия, имя, отчество

			cout << "Введите фамилию: "; cin >> pac[i].last_name; cout << endl;
			cout << "Введите имя: "; cin >> pac[i].name; cout << endl;
			cout << "Введите отчество: "; cin >> pac[i].dadname; cout << endl;
	
			// домашний адрес
			cout << "Введите домашний адрес: "; cin >> pac[i].address; cout << endl;
	
			// номер студента
			int student_number; cout << "Введите номер студента: "; cin >> student_number; cout << endl;

			// номер группы

			int group_number; cout << "Введите номер группы: "; cin >> group_number; cout << endl;

			system("cls");
			cout << "Good!";
			Sleep(1000);
		}

		// если нужно удалить структурту из массива (6)

		else if (input_menu == 6)
		{
			if (!ispac)// студентов нет
			{
				cout << "Error!";
				Sleep(1000);
				continue;
			} 
			int num; // номер студента
			cout << "Номер студента: "; cin >> num;

			// если неправильно введен номер студента

			if (num > pac_num || num == 0)
			{
				cout << "Error!";
				continue;
			}

			// если в массиве всего один элемент

			if (pac_num == 1)
			{
				delete[] pac;
				pac = new students[1];
				ispac = false;
				system("cls");
				cout << "Good!";
				Sleep(1000);
				continue;
			}

			pac_num = pac_num - 1;

			// сдвиг

			for (int i = num - 1; i < pac_num; i++)
			{
				int pac_i_num = pac[i].num;
				pac[i].num = pac[i + 1].num;
				pac[i + 1].num = pac_i_num;
				pac[i] = pac[i + 1];
			}

			// создем копию, в которую размещаем нужный массив

			students* pac_copy = new students[pac_num];
			for (int i = 0; i < pac_num; i++)
			{
				pac_copy[i] = pac[i];
			}

			// изменяем существующий массив студентов

			delete[] pac;
			pac = new students[pac_num];
			for (int i = 0; i < pac_num; i++)
			{
				pac[i] = pac_copy[i];
			}
			system("cls");
			cout << "Good!";
			Sleep(1000);
		}

		// выход (7)

		else if (input_menu == 7)

			break;
		// если не выбран ни один пункт меню
		else
		{
			cout << " Error! ";
			Sleep(500);
			system("cls");
		}
	}
	system("pause");
	return 0;
}
