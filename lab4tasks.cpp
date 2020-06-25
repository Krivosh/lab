#include <iostream>

#include <Windows.h>

#include <fstream>

using namespace std;

struct solder {

	char surname[15];
	char name[15];
	char patronymic[15];
	char adress[20];
	char nationality[20];
	char Position[40];
	char Rank[30];
};

void BSort(solder* a, int n, int p);

int menu(char* path);

int counter(char* path);

void Create(char* path);

void Addition(char* path);

void Output(char* path);

void Delete(char* path);

int SK(char* path);

void Sort(char* path);

int main(int argc, char** argv) {

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	char path[] = "С:\\Data.txt";

	void (*masf[])(char*) = { Create,Addition,Output,Delete,Sort };

	while (1)

		(*masf[menu(path)])(path);

	system("pause");

	return 0;

}

void BSort(solder* a, int n, int p) {

	int j;

	solder t;

	switch (p)

	{

	case 1:

		while (n--)

			for (j = 0; j < n; j++) {

				if ((int)a[j].surname >= (int)a[j + 1].surname) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;

	case 2:

		while (n--)

			for (j = 0; j < n; j++) {

				if ((int)a[j].name >= (int)a[j + 1].name) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;

	case 3:

		while (n--)

			for (j = 0; j < n; j++) {

				if (a[j].patronymic >= a[j + 1].patronymic) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;

	case 4:

		while (n--)

			for (j = 0; j < n; j++) {

				if (a[j].adress <= a[j + 1].adress) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;

	case 5:

		while (n--)

			for (j = 0; j < n; j++) {

				if (a[j].nationality < a[j + 1].nationality) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;

	case 6:

		while (n--)

			for (j = 0; j < n; j++)

			{

				if (a[j].Position < a[j + 1].Position) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;
	case 7:

		while (n--)

			for (j = 0; j < n; j++)

			{

				if (a[j].Rank < a[j + 1].Rank) continue;

				t = a[j];

				a[j] = a[j + 1];

				a[j + 1] = t;

			}

		break;
	}

}

int menu(char* path) {

	char k;

	do {
		system("cls");
		cout << "Меню:" << endl;

		cout << "1) Создание файла;" << endl;

		cout << "2) Добавление элемента в конец файла;" << endl;

		cout << "3) Вывод содержимого файла на экран;" << endl;

		cout << "4) Удаление элемента из файла;" << endl;

		cout << "5) Упорядочивание элементов в файле по выбранному признаку;" << endl;

		cout << "6) Выход." << endl;

		cout << "Выберите пункт меню: " << endl;



		cin >> k;

		system("cls");

	} while (strchr("123456", k) == NULL);

	if (k == '6') exit(0);

	return k - 49;

}

int counter(char* path) {

	ifstream fin;

	int n = 0;

	char buff[20];

	fin.open(path, ios_base::binary);

	while (!fin.eof()) {

		fin.getline(buff, 20, '\n');

		n++;

	}

	n /= 6;

	fin.close();

	return n;

}

void Create(char* path) {

	cout << "Текущий файл: " << path << endl;

	int n;

	cout << "Введите количество структур: ";

	cin >> n;

	solder* a = new solder[n];

	for (int i = 0; i < n; i++) {			
		cout << "Введите имя" << endl;
		cin >> a[i].name;
		cout << "Введите фамилию" << endl;
		cin >> a[i].surname;
		cout << "Введите отчество" << endl;
		cin >> a[i].patronymic;
		cout << "Введите адресс проживания" << endl;
		cin >> a[i].adress;
		cout << "Введите национальность" << endl;
		cin >> a[i].nationality;
		cout << "Введите должность" << endl;
		cin >> a[i].Position;
		cout << "Введите звание" << endl;
		cin >> a[i].Rank;

	}

	ofstream fout(path, ios_base::binary | ios_base::trunc);

	for (int i = 0; i < n; i++) {

		fout << i + 1 << endl;

		fout << a[i].name << endl;

		fout << a[i].surname << endl;

		fout << a[i].patronymic << endl;

		fout << a[i].adress << endl;

		fout << a[i].nationality << endl;

		fout << a[i].Position << endl;
		fout << a[i].Rank << endl;

	}

	fout.close();

	delete[] a;

	system("pause");

}

void Addition(char* path) {

	int n = counter(path);

	ofstream fout(path, ios_base::binary | ios_base::app);

	solder* a = new solder[1];

	if (fout.is_open()) {

		cout << "Имя: ";

		cin >> a[0].name;

		cout << "Фамилия : ";

		cin >> a[0].surname;

		cout << "Отчество: ";

		cin >> a[0].patronymic;

		cout << "Адресс: ";

		cin >> a[0].adress;

		cout << "Национальность: ";

		cin >> a[0].nationality;
		cout << "Должность ";
		cin >> a[0].Position;
		cout << "Звание: ";
		cin >> a[0].Rank;

		fout << n + 1 << endl;

		fout << a[0].name << endl;

		fout << a[0].surname << endl;

		fout << a[0].patronymic << endl;

		fout << a[0].adress << endl;

		fout << a[0].nationality << endl;

		fout << a[0].Position << endl;
		fout << a[0].Rank << endl;

		fout.close();

		delete[] a;

	}

	else cout << "Файл не открыт." << endl;

	system("pause");

}

void Output(char* path) {

	int n = counter(path);

	ifstream fin;

	int order;

	fin.open(path, ios_base::binary);

	if (fin.is_open()) {

		solder* a = new solder[n];

		for (int i = 0; i < n; i++) {

			fin >> order;

			cout << "№" << order << endl;

			fin >> a[i].name;

			cout << "Имя: " << a[i].name << endl;

			fin >> a[i].surname;

			cout << "Фамилия: " << a[i].surname << endl;

			fin >> a[i].patronymic;

			cout << "Отчество: " << a[i].patronymic << endl;

			fin >> a[i].adress;

			cout << "Адресс: " << a[i].adress << endl;

			fin >> a[i].nationality;

			cout << "Национальность: " << a[i].nationality << endl;

			fin >> a[i].Position;

			cout << "Должность: " << a[i].Position << endl;
			fin >> a[i].Rank;
			cout << "Звание: " << a[i].Rank << endl;

		}

		fin.close();

		system("pause");

	}

	else cout << "Файл не открыт." << endl;

}

void Delete(char* path) {

	int k, choice;

	char temp[20];

	cout << "Выберете способ удаления структуры:" << endl;

	cout << "\t0. По ключу" << endl;

	cout << "\t1. По номеру" << endl;

	cin >> choice;

	do {

		if (choice) {

			cout << "Введите номер структуры: ";

			cin >> k;

			k--;

		}

		else k = SK(path);

	} while (k < 0);

	ifstream fin;

	ofstream fout;

	fin.open(path, ios::binary);

	fout.open("buff.bin", ios::binary);

	for (int i = 0; !fin.eof(); i++) {

		for (int num = 0; num < 9 && !fin.eof(); num++) {

			fin >> temp;

			if (i != k) {

				fout << temp << endl;

			}

		}

	}

	fin.close();

	fout.close();

	remove(path);

	rename("buff.bin", path);

}

int SK(char* path) {

	char tmp[20], k[20];

	cout << "Введите ключ для поиска: ";

	cin >> k;

	ifstream fin;

	fin.open(path, ios::binary);

	for (int i = 0; !fin.eof(); i++) {

		for (int j = 0; j < 9; j++) {

			fin >> tmp;

			if (!strcmp(tmp, k)) {

				fin.close();

				return i;

			}

		}

	}

	fin.close();

	return -1;

}

void Sort(char* path) {

	int p, n;

	n = counter(path);

	solder* a = new solder[n];

	ifstream fin;

	int order;

	fin.open(path, ios_base::binary);

	if (fin.is_open()) {

		solder* a = new solder[n];

		for (int i = 0; i < n; i++) {

			fin >> order;

			fin >> a[i].name;

			fin >> a[i].surname;

			fin >> a[i].patronymic;

			fin >> a[i].adress;

			fin >> a[i].nationality;

			fin >> a[i].Position;

			fin >> a[i].Rank;

		}

		fin.close();

		cout << "\t1. Имя;" << endl;

		cout << "\t2. Фамилия;" << endl;

		cout << "\t3. Отчество;" << endl;

		cout << "\t4. Адресс;" << endl;

		cout << "\t5. Национальность;" << endl;

		cout << "\t6. Должность;" << endl;

		cout << "\t7. Звание;" << endl;

		cout << "Выберете по какому параметру сортировать: ";

		cin >> p;

		BSort(a, n, p);

		ofstream fout(path, ios_base::binary | ios_base::trunc);

		if (fout.is_open()) {

			for (int i = 0; i < n; i++) {

				fout << i + 1 << endl;

				fout << a[i].name << endl;

				fout << a[i].surname << endl;

				fout << a[i].patronymic << endl;

				fout << a[i].adress << endl;

				fout << a[i].nationality << endl;

				fout << a[i].Position << endl;

				fout << a[i].Rank << endl;

			}

		}

	}

	else cout << "Файл не открыт." << endl;

}
