#include<stdio.h>
#include <algorithm>

void PrintArray(int n, int A[]);
void SelectionSort(int n, int A[]);
void BubbleSort1(int n, int A[]);
void BubbleSort2(int n, int A[]);
void ShakerSort(int n, int A[]);
void InsertSort(int n, int A[]);
void main()
{
	//Khai bao bien
	int n, A[100];

	//Nhap 
	printf("Nhap n: "); scanf("%d",&n);
	printf("Nhap mang: ");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}

	//Solve
//	SelectionSort(n, A);
//	InsertSort(n,A);
//	BubbleSort1(n,A);
//	ShakerSort(n,A);	
//	BubbleSort2(n,A);
	PrintArray(n,A);
}

void BubbleSort2(int n, int A[])
{
    bool alreadySwap = false;
	for (int i = 0; i < n - 1; i++)	//Phan tu cuoi cung se duoc sap xep
	{			
				alreadySwap = false;
				for (int j = n-1; j > i; j--)  
				{											
							if (A[j-1] > A[j])
							{
								std:: swap(A[j], A[j-1]);
								alreadySwap = true; // Kiem tra lan lap nay co swap khong 
							}
				}
				// Neu khong co swap nao duoc thuc hien => mang da sap xep, khong can lap them 
				if(alreadySwap == false)
				{
					break;
				}									//Nguyen Phong Phu - 20110696
    }
}

void ShakerSort(int n, int A[])			//Nguyen Phong Phu - 20110696
{
	int Left = 0;
	int Right = n - 1;
	int flag = n - 1;
	while (Left < Right)
	{		
				//Dua gia tri nho nhat ve vi tri left
				for (int i2 = Right; i2 > Left; i2--)
				{
								if (A[i2] < A[i2 - 1])
								{
									std:: swap(A[i2], A[i2 - 1]);
									flag = i2;
								}
				}
				Left = flag;
				//Dua gia tri lon nhat ve vi tri right
				for (int i1 = Left; i1 < Right; i1++)
				{
								if (A[i1] > A[i1 + 1])
								{
									std:: swap(A[i1], A[i1 + 1]);
									flag = i1;
								}
				}
				Right = flag;	
	}
}

void BubbleSort1(int n, int A[])
{
	//Bien dung de kiem tra co swap ko
    bool alreadySwap = false;

    for (int i = 0; i < n - 1; i++)	//Phan tu cuoi cung se duoc sap xep
	{			
				alreadySwap = false;
				for (int j = 0; j < n - i -1; j++)  //Tai vi: sau khi thuc hien moi lan lap thi phan tu lon nhat se nam sau cung
				{												 //				khong can phai duyet lai			
							if (A[j] > A[j+1])
							{
								std:: swap(A[j], A[j+1]);
								alreadySwap = true; // Kiem tra lan lap nay co swap khong 
							}
				}
				// Neu khong co swap nao duoc thuc hien => mang da sap xep, khong can lap them 
				if(alreadySwap == false)
				{
					break;
				}									//Nguyen Phong Phu - 20110696
    }
}

void InsertSort(int n, int A[])
{
	int j, key;

	/* Di chuyen cac phan tu co gia tri lon hon gia tri 
       key va sau mot vi tri so voi vi tri ban dau
       cua no */
	for (int i = 1; i < n ; i++)
	{
		key = A[i];
		j = i - 1;

		while (j >= 0 && A[j] > key)
		{
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = key;
	}											//Nguyen Phong Phu - 20110696
}

void SelectionSort(int n, int A[])
{
	int temp, min_index;
	for (int i=0;i<n-1;i++)
	{
		min_index = i;

		//Tim phan tu nho nhat trong doan ben phai i
		for (int j=i+1;j<n;j++)
		{
			if (A[i] > A[j])
			{
				min_index = j;
			}
		}
		//Hoan vi phan tu nho nhat voi i
		if (i != min_index)
		{
			temp = A[i];
			A[i] = A[min_index];
			A[min_index] = temp;
		}
	}
}

void PrintArray(int n, int A[])
{
	for (int i = 0 ; i < n ; i++)
		printf("%d ", A[i]);
}