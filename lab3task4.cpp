#include<iostream>
#include<fstream>
#include<vector>
#include<Windows.h>
#include<string>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");

	ifstream fin;
	fin.open("Laba.txt"); //не удаление предыдущих записей ofstream::app
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		cout << "Данные взятые из файла: " <<endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str<< endl;
		}
		vector<string> myVector;
		string temp;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				myVector.push_back(temp);
				temp.clear();
			}
			else if (i + 1 == str.length()) {
				temp += str[i];
				myVector.push_back(temp);
			}
			else
				temp += str[i];
		}
		int size;
		cout << "Введите длину слова ";
		cin >> size;
		ofstream fout;
		fout.open("newLaba.txt");
		for (int i = myVector.size() - 1; i > 0; i--)
		{
			string s = myVector[i];
			int siz = s.size();
			if (siz == size)
			{
				myVector.erase(myVector.begin() + i);
				break;
			}
		}
		for (int i = 0; i < myVector.size(); i++)
		{
			fout << myVector[i] << " ";
		}
		fout.close();
	}
	fin.close();

	return 0;
}
