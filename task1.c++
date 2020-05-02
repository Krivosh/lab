+#include
#include <windows.h>
#include <stdio.h>
#include<math.h>
using namespace std;
double f(double t, double y ) {
return ((t + y) / 2);
}
double fun(double r, double w, double d) {
return((r + w + d) / 3);
}
int main()
{
setlocale(LC_ALL, "Russian");
int N; // размер массива
cout << "Enter integer value: ";
cin >> N; // получение от пользователя размера массива
double* A = new double[N]; // Выделение памяти для массива
cout << "Массив : {";
for (int i = 0; i < N; i++) { // Заполнение массива и вывод значений его элементов
    A[i] = i;
    cout << A[i] << ",";
}
cout << "}" << endl;
for (int u = 0; u < 5; u++){
    cout << "Массив  : {";
A[0] = f(A[0], A[1]);
cout << A[0] << ",";

for (int i = A[1]; i < N - 2; i++) {
    double  k = fun(A[i], A[i + 1], A[i + 2]);
    A[i] = k;
    cout << A[i] << ",";
}A[N - 1] = f(A[N - 1], A[N - 2]);
cout << A[N - 1];
cout << "}" << endl;
}
delete[] A;
system("pause");
return 0;
}
