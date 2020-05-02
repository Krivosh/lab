#include <iostream>
#include <string.h>
using namespace std;
char* InvertStr(char* s, int k, int n) {
static char ts[40];
int i = 0, j = k + n;
if (k > strlen(s))
return 0;
while (k > 0 && k > j) {
ts[i] = s[k - 1];
i++;
k--;
}
return ts;
}
int main() {
char s[228];
int k, n;
cin >> s;
cin >> k;
cin >> n;
cout << InvertStr(s, k, n) << endl;
system("pause");
return 0;
}
