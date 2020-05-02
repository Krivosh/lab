#include<iostream>
#include <windows.h>
#include <stdio.h>
#include<math.h>
using namespace std;
double fun(double r,  double d) {
    return((r + d) / 2);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int N; // размер массива
    cout << "Enter integer value: ";
    cin >> N; // получение от пользователя размера массива
    double* A = new double[N]; // Выделение памяти для массива
    cout << "Массив : {";
    for (int i = 1; i <= N; i++) { // Заполнение массива и вывод значений его элементов
        A[i] = i;
        cout << A[i] << ",";
    }
    cout << "}" << endl;
    for (int u = 0; u < 5; u++) {
        cout << "Массив  : {";
        A[0] = A[1];
        cout << A[0] << ",";

        for (int i = A[1]; i < N - 1; i++) {
            double  k = fun( A[i -1], A[i + 1]);
            A[i] = k;
            cout << A[i] << ",";
        }A[N] = A[N - 1];
        cout << A[N - 1];
        cout << "}" << endl;
    }
   
    system("pause");
    return 0;
}
