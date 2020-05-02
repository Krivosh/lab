#include <iostream>
#include <stdlib.h>
using namespace std;
int counter;
int combin2(int n, int k)
{
  if ( (n == k) || (k == 0)) {
    counter++;
    return 1; }
  counter += 2;
return combin2(n - 1, k) + combin2(n - 1, k - 1);
}
int main()
{
int n , k , c;
cout << "n= ";
cin >> n;
if (n > 20) {
    cout << "Error" << endl;
    system("pause");
        return 0;
}
cout << "k= ";
cin >> k;
counter = 0;
c = combin2(n, k);
cout << "n= " << n <<endl<< "k=" << k <<endl<< "c=" << c <<endl<< "counter= " << counter << endl;
system("PAUSE");
return 0;
}
