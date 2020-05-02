#include<string>
#include<fstream>
#include<vector>
#include <iostream>
using namespace std;

int main()
{


	setlocale(LC_ALL, "ru");
	string gif = "myFile.txt";
	ofstream file;
	file.open(gif);//создание файла . сохранение предыдущих данных ofstream::app
	const int a = 10;
	int nice[a];
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!!!\n";

	}
	else
	{
		cout << "Данные записаные в файл : " ;
		
		for (int n = 0; n < a; n++) //создание рандомных чисел
		{
			nice[n] = rand() % 10;
			file << nice[n] << "";
			cout << nice[n] << "";
		}
	}
	cout << "" << endl;
	file.close();//открытие файла
	ifstream nif;
	nif.open(gif);
	if (!nif.is_open())
	{
		cout << "Ошибка открытия файла !!!" << endl;
	}
	else
	{
		cout << "Файл открыт !" << endl;
		char kir;
			vector<char> mVector;
			cout << "Данные из файла : " ;
			while (nif.get(kir))//вывод данных из файла
				if (kir != ' ')
					mVector.push_back(kir);

			for (int i = 0; i < mVector.size(); i++)
			{
				cout << mVector[i] << " ";
			}
			cout << endl;
			cout << "Данные после сортировки пузырьком: ";

			for (int i = 0; i < mVector.size(); i++) 
			{
				for (int j = 0; j < mVector.size() - 1; j++)
				{
					if (mVector[j] > mVector[j + 1])
					{
						int t = mVector[j];
						mVector[j] = mVector[j + 1];
						mVector[j + 1] = t;
					}
				}
			}
			for (int i = 0; i < mVector.size(); i++)
			{
				cout << mVector[i] << " ";
			}
			file.open(gif, ofstream::app);
			file << endl;
			if (!file.is_open()) cout << "Error\n";
			for (int i = 0; i < mVector.size(); i++) {
				file << mVector[i] << " ";
			}
			file.close();
		}

	nif.close();
	cout << endl;
 system("pause");	
 return 0;
}
