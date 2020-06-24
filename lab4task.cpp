#include <iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct solder
{
    string surname;
    string name;
    string patronymic;
    string adress;
    string nationality;
    string Position;
    string Rank;
    };
solder in();
string decToBe(solder build);
string toBe(int num);
int find(vector<solder>data);
void out(string path);
void infile(string path, string line);
void deleting(vector<solder>data, int k);
void sort(vector<solder>data);
int main()
{
    setlocale(0, "");
    bool t = true;
    string path = "ForFilesLab";
    int del;
    while (t)
    {
        cout << "Выберите:" << endl;
        cout << "1-Ввод данных" << endl;
        cout << "2-Добавление одного элемента" << endl;
        cout << "3-Вывод содержимого бинарного файла на экран" << endl;
        cout << "4-Удаление элемента" << endl;
        cout << "5-Сортировка данных" << endl;
        cout << "6-Выход" << endl;
        int N;
        int n = 0;
        vector<solder>data;
        string str;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1://ввод данных
            cout << "Сколько структур записать?" << endl;
            cin >> N;

            for (int i = 0; i < N; i++)
            {
                data.push_back(in());
            }
            for (int i = 0; i < N; i++)
            {
                str += decToBe(data[i]);
            }
            infile(path, str);

            break;
        case 2://добавление одного элемента
            data.push_back(in());
            for (int i = 0; i < data.size(); i++)
            {
                str += decToBe(data[i]);
            }
            infile(path, str);
            break;
        case 3://вывод содержимого на экран
            out(path);
            system("pause");
            system("cls");
            break;
        case 4://удаление элемента
            cout << "Выберите:" << endl;
            cout << "1-удаление структуры по номеру" << endl;
            cout << "2-удаление структуры по ключу" << endl;
            int q;
            cin >> q;
            switch (q)
            {
            case 1:
                cout << "Введите номер структуры" << endl;
                del;
                cin >> del;
                del--;
                deleting(data, del);
                break;
            case 2:
                del = find(data);
                deleting(data, del);
                break;
            default:
                cout << "ERROR!!!" << endl;
                break;
            }
            for (int i = 0; i < data.size(); i++)
            {
                str = decToBe(data[i]);
            }
            infile(path, str);
            break;
        case 5://сортировка
            sort(data);
            for (int i = 0; i < data.size(); i++)
            {
                str = decToBe(data[i]);
            }
            infile(path, str);
            break;
        case 6:
            t = false;
            break;
        default:
            cout << "ERROR!!!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
string decToBe(solder build)
{      
    string becode;
    for (int i = 0; i < build.surname.length(); i++)
    {
        string temp = toBe((int)build.surname[i]);
        becode += temp;
    }
    for (int i = 0; i < build.name.length(); i++)
    {
        string temp = toBe((int)build.name[i]);
        becode += temp;
    }
    for (int i = 0; i < build.patronymic.length(); i++)
    {
        string temp = toBe((int)build.patronymic[i]);
        becode += temp;
    }
    for (int i = 0; i < build.adress.length(); i++)
    {
        string temp = toBe((int)build.adress[i]);
        becode += temp;
    }
    for (int i = 0; i < build.nationality.length(); i++)
    {
        string temp = toBe((int)build.nationality[i]);
        becode += temp;
    }
    for (int i = 0; i < build.Position.length(); i++)
    {
        string temp = toBe((int)build.Position[i]);
        becode += temp;
    }
    for (int i = 0; i < build.Rank.length(); i++)
    {
        string temp = toBe((int)build.Rank[i]);
        becode += temp;
    }      
    return becode;
}
string toBe(int n)
{
    string result;
    do
    {
        result += ('0' + (n % 2));
        n = n / 2;
    } while (n > 0);
    reverse(result.begin(), result.end());
    return result;
}
solder in()
{
    solder* st = new solder;
    cout << "Введите имя" << endl;
    cin >> st->name;
    cout << "Введите фамилию" << endl;
    cin >> st->surname;
    cout << "Введите отчество" << endl;
    cin >> st->patronymic;
    cout << "Введите адресс проживания" << endl;
    cin >> st->adress;
    cout << "Введите национальность" << endl;
    cin >> st->nationality;
    cout << "Введите должность" << endl;
    cin >> st->Position;
    cout << "Введите звание" << endl;
    cin >> st->Rank;
 
   
    system("cls");
    return *st;
}
int find(vector<solder>data)
{
    cout << "Выберете параметр для поиска" << endl;
    cout << "1 - Фамилия" << endl;
    cout << "2 - Национальность" << endl;
    cout << "3 - Должность" << endl;
    cout << "4 - Звание" << endl;
    int f;
    cin >> f;
    int find2, findi;
    string finds;
    switch (f)
    {
    case 1:
        cin >> finds;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].surname == finds)
            {
                find2 = i;
                break;
            }
        }
    case 2:
        cin >> finds;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].nationality == finds)
            {
                find2 = i;
                break;
            }
        }
    case 3:
        cin >> findi;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].Position == finds)
            {
                find2 = i;
                break;
            }
        }
    case 4:
        cin >> findi;
        for ( int i = 0; i < data.size(); i++)
        {
            if (data[i].Rank == finds)
            {
                find2 = i;
                break;
            }
        }
    
    default:
        cout << "ERROR!!!" << endl;
        break;

    }
    return find2;
}
void deleting(vector<solder>data, int k)
{
    for (int i = 1; i < data.size(); i++)
    {
        data[k + i - 1].surname = data[k + i].surname;
        data[k + i - 1].name = data[k + i].name;
        data[k + i - 1].patronymic = data[k + i].patronymic;
        data[k + i - 1].adress = data[k + i].adress;     
        data[k + i - 1].nationality = data[k + i].nationality;
        data[k + i - 1].Position = data[k + i].Position;
        data[k + i - 1].Rank = data[k + i].Rank;       
    }
}
void sort(vector<solder>data)
{
    solder temp;
    cout << "Выберете параметр для сортировки" << endl;
    cout << "1 - Фамилия" << endl;
    cout << "2 - Национальность" << endl;
    cout << "3 - Должность" << endl;
    cout << "4 - Звание" << endl;
    int q;
    cin >> q;
    switch (q)
    {
    case 1:
        for (int k = 0; k < data.size(); k++)
        {
            for (int i = 0; i < data.size() - 1; i++)
            {
                if ((int)data[i].surname[0] > (int)data[i + 1].surname[0])
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int k = 0; k < data.size(); k++)
        {
            for (int i = 0; i < data.size() - 1; i++)
            {
                if ((int)data[i].nationality[0] > (int)data[i + 1].nationality[0])
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                }
            }
        }
        break;
    case 3:
        for (int k = 0; k < data.size(); k++)
        {
            for (int i = 0; i < data.size() - 1; i++)
            {
                if (data[i].Position > data[i + 1].Position)
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                }
            }
        }
        break;
    case 4:
        for (int k = 0; k < data.size(); k++)
        {
            for (int i = 0; i < data.size() - 1; i++)
            {
                if (data[i].Rank > data[i + 1].Rank)
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                }
            }
        }   
        break;
    default:
        cout << "ERROR!!!" << endl;
        break;
    }
}
void out(string path)
{
    ifstream file;
    file.open(path);
    if (file.is_open())
    {
        string str;
        while (getline(file, str))
            cout << str << endl;
    }
    else cout << "ERORR!!!" << endl;
    file.close();
}
void infile(string path, string line)
{
    ofstream file;
    file.open(path);
    if (file.is_open())
    {
        file << line;
    }
    else cout << "ERORR!!!" << endl;
    file.close();
}
