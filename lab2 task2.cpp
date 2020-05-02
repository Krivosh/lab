#include <iostream>
#include <string.h>
using namespace std;
char* InvertStr(char* s, int k, int n) {
	static char ts[256];
	int i = 0, j = k + n;
	if (k > strlen(s)) {
		system("pause");
		return 0;
	}
	
	while (k >0 && k < j) {
		ts[i] = s[k-1 ];
		i++;
		k--;
		
	}
	return ts;
}
int main() {
	setlocale(LC_ALL, "Russian");
	char s[228];
	int k, n;
	cout << "Введите строку s : ";
	cin >> s;
	cout << "Введите номер символа с котрого  будет инвертироваться строка s : ";
	cin >> k;
	cout << "Введите количество символо для инвертирования : ";
	cin >> n;
	cout << InvertStr(s, k, n) << endl;
	system("pause");
	return 0;
}
