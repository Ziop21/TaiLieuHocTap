#include <iostream>
#include <algorithm>
using namespace std;

void nhapMang2Chieu(int& m, int& n, int A[][100]);
void xuatMang2Chieu(int m, int n, int A[][100]);
void ShackerSort_Mang2Chieu(int m, int n, int A[][100]);

int main()
{
    // Khai báo và nhập mảng 
    int m, n, A[100][100];
	nhapMang2Chieu(m, n, A);
	// Ứng dụng thuật toán ShackerSort
	ShackerSort_Mang2Chieu(m, n, A);
	// Xuất mảng A
	xuatMang2Chieu(m, n, A);
}

void ShackerSort_Mang2Chieu(int m, int n, int A[][100])
{
	int L_r = 0;
	int L_c = 0;
	int R_r = m - 1;
	int R_c = n - 1;
	int flag_r;
	int flag_c;

	while (L_c < R_c || L_r < R_r)
	{
		// Đưa phần tử nhỏ nhất về vị trí L
		int i1_c = R_c;
		int i1_r = R_r;
		while (i1_c > L_c || i1_r > L_r)
		{
			if (i1_c == 0)
			{
				if (A[i1_r][i1_c] < A[i1_r - 1][n - 1])
				{
					swap(A[i1_r][i1_c], A[i1_r - 1][n - 1]);
					flag_c = i1_c;
					flag_r = i1_r;
				}
				i1_r--;
				i1_c = n - 1;
			}
			else
			{
				if (A[i1_r][i1_c] < A[i1_r][i1_c - 1])
				{
					swap(A[i1_r][i1_c], A[i1_r][i1_c - 1]);
					flag_c = i1_c;
					flag_r = i1_r;
				}
				i1_c--;
			}
		}
		L_c = flag_c;
		L_r = flag_r;

		// Đưa phần tử lớn nhất về vị trí R
		int i2_c = L_c;
		int i2_r = L_r;
		while (i2_c < R_c || i2_r < R_r)
		{
			if (i2_c == n - 1)
			{
				if (A[i2_r][i2_c] > A[i2_r + 1][0])
				{
					swap(A[i2_r][i2_c], A[i2_r + 1][0]);
					flag_c = i2_c;
					flag_r = i2_r;
				}
				i2_r++;
				i2_c = 0;
			}
			else
			{
				if (A[i2_r][i2_c] > A[i2_r][i2_c + 1])
				{
					swap(A[i2_r][i2_c], A[i2_r][i2_c + 1]);
					flag_c = i2_c;
					flag_r = i2_r;
				}
				i2_c++;
			}
		}
		R_c = flag_c;
		R_r = flag_r;
	}
}
void xuatMang2Chieu(int m, int n, int A[][100])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}
void nhapMang2Chieu(int& m, int& n, int A[][100])
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}

