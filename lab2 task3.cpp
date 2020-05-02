#include <iostream>
#include <stdlib.h>
using namespace std;

int combin2(int n, int k)
{   
    int counter = 0;
    if ((n == k) || (k == 0))
    {
        counter++;
        return 1;
    }
   
   return combin2(n - 1, k) + combin2(n - 1, k - 1);
}
int main()
{
    int n,  c;
    int k = 0;
    cout << "n= ";
    cin >> n;
    if (n > 20 && 0 <= k && k <= n) {
        cout << "Error" << endl;
        system("pause");
        return 0;
    }
    cout << "k= ";
    cin >> k;
    c = combin2(n, k);
    cout << "n= " << n << endl << "k=" << k << endl << "c=" << c  << endl;
    system("PAUSE");
    return 0;
}
