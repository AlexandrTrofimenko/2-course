#include <iostream>
using namespace std;
const int n = 11, d = 10;
int Digit(int x, int d)
{
    while (d > 1)
    {
        x /= 10;
        d--;
    }
    return x % 10;
}

void radixSort(int dop_mas[n][n], int mas[n], int d)
{
    int mas_col[n] = {0}, i, j, temp = 0;
    for (i = 0; i < n; i++)
    {
        int a = Digit(mas[i], d);
        dop_mas[mas_col[a]][a] = mas[i];
        mas_col[a]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mas_col[i]; j++)
        {
            mas[temp] = dop_mas[j][i];
            temp++;
        }
    }
}
void help(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        help(arr, n, largest);
    }
}

void heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        help(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        help(arr, i, 0);
    }
}

int main()
{
    int mas[n] = { 67654, 5433567, 12609977, 935599876, 142334567, 61300987, 7328853, 126456789, 847766, 6888655 ,388766 };
    int dop_mas[n][n];
    for (int i = 1; i < d + 1 ; i++)
        radixSort(dop_mas, mas, i);
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
  /*  heap(mas, n);
    for (int i = 0; i < n; ++i)
        cout << mas[i] << " ";*/
    return 0;
}