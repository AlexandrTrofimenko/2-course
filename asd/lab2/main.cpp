#include <iostream>
using namespace std;
int main()
{
    int x; 
    cin >> x;
    int k, l, m, p;
    for (int i = 1; i < x; i++)
    {
        p = i;
        k = 0;
        l = 0;
        m = 0;
        while (p % 3 == 0)
        {
            k++;
            p /= 3;
        }
        while (p % 5 == 0)
        {
            l++;
            p /= 5;
        }
        while (p % 7 == 0)
        {
            m++;
            p /= 7;
        }
        if (p == 1)
        {
            cout << i << " = 3^" << k << " * 5^" << l << " * 7^" << m << endl;
        }
    }
    return 0;
}