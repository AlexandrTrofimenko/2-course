#include <iostream>
#include <vector>
#include <cmath>
int Digit(int x,int i,int d)
{
	while (d > 1)
	{
		x /= 10;
		d--;
	}
	return x%10;
}

void RadixSort(std::vector<int>& data, int k, int d)
{
	int dc = (k + d - 1) / d;
	int m = pow(2, d);
	int *C = new int [m];
	int *B = new int[data.size()];
	for (int i = 0; i < dc - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			C[j] = 0;
		}
		for (int j = 0; j < data.size()-1; j++)
		{
			int r = Digit(data[j], i);
			C[r] = C[r] + 1;
		}
		for (int j = 1; j < m - 1; j++)
		{
			C[j] = C[j] + C[j - 1];
		}
		for (int j = data.size()-1; j>0; j--)
		{
			int r = Digit(data[j], i);
			C[r] = C[r] - 1;
			B[C[r]] = data[j];
		}
		for (int j = 0; j < data.size() - 1; j++) 
		{
			data[j] = B[j];
		}
	}
	delete[] C;
	delete[] B;
}

void combSort(std::vector<int>& data)
{
	double factor = 1.3; 
	int step = data.size() - 1; 

	while (step >= 1)
	{
		for (int i = 0; i + step < data.size(); i++)
		{
			if (data[i] > data[i + step])
			{
				std::swap(data[i], data[i + step]);
			}
		}
		step /= factor;
	}
}

void insertSort(std::vector<int>& data) {
	int tmp;
	int j;
	for (int i = 0; i < data.size(); i++) {
		tmp = data[i];
		for (j = i - 1; j >= 0 && data[j] > tmp; j--) 
		{
			data[j + 1] = data[j];
		}
		data[j + 1] = tmp;

	}
}
void selectionSort(std::vector<int>& data)
{
	int j = 0;
	for (int i = 0; i < data.size() - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < data.size(); j++)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			std::swap(data[i], data[min]);

		}
	}
}
void shelSort(std::vector<int>& data)
{
	int i, j, step;
	int tmp;
	for (step = data.size() / 2; step > 0; step /= 2)
	{
		for (i = step; i < data.size(); i++)
		{
			tmp = data[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < data[j - step])
					data[j] = data[j - step];
				else
					break;
			}
			data[j] = tmp;
		}
	}
}

int main()
{
	srand(time(NULL));
	std::vector <int> mass;
	int n; std::cin >> n;
	std::cout << "Range of mass" << std::endl;
	for (int i = 0; i < n; i++)
	{
		mass.push_back(rand());
	}
	for (int i = 0; i < n; i++)
		std::cout << mass[i] << " ";
	RadixSort(mass,4,10);
	std::cout << std::endl << "after sort" << std::endl;
	
	for (int i = 0; i < n; i++)
		std::cout << mass[i] << " ";

	return 0;
}