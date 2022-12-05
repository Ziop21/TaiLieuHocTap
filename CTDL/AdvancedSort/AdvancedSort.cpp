#include<stdio.h>
#include <algorithm>

void nhapMang(int Arr[], int &n);
void xuatMang(int Arr[], int n);

//HeapSort													       //QuickSort
void heapSort(int Arr[], int n);							void quickSort(int Arr[], int low, int high);	
void heapify(int Arr[], int n, int i);						 int partition (int Arr[], int low, int high);

//ShellSort
void shellSort(int a[], int n);

void main()
{
	int Arr[100], n;

	nhapMang(Arr,n);

	//heapSort(Arr,n);
	quickSort(Arr, 0, n-1);
	//shellSort(Arr, n);
	
	xuatMang(Arr, n);
}

void shellSort(int Arr[], int n)
{
	int interval, i, j, temp;

	for(interval = n/2; interval > 0; interval /= 2)
	{
				//Lay ra mang con cach nhau 1 khoang interval
				for(i = interval; i < n; i++)
				{
							//sap xep cac phan tu trong mang con bang thuan toan insertSort
							temp = Arr[i];

							for(j = i; j >= interval && Arr[j - interval] > temp; j -= interval)
							{
								Arr[j] = Arr[j - interval];				
							}

							Arr[j] = temp;
				}
			}
}		//Nguyen Phong Phu - 20110696

void quickSort(int Arr[], int low, int high)
{
    if (low < high)
    {
       /* pi la chi so noi phtu nay da dung (stand) dung (true) vi tri
         va la phtu chia mang lam 2 mang con trai & phai */
        int pi = partition(Arr, low, high);
      // Goi de quy sap xep 2 mang con trai va phai
        quickSort(Arr, low, pi - 1);
        quickSort(Arr, pi + 1, high);
    }
}

int partition (int Arr[], int low, int high)
{
    int pivot = Arr[high];    // pivot
    int L = low;
    int R = high - 1;
    while (true)
	{
        while(L <= R && Arr[L] <= pivot) 
			L++;
        while(R >= L && Arr[R] >= pivot)
			R--;
        if (L >= R) 
			break;
		std:: swap(Arr[L], Arr[R]);
        L++;
        R--;
    }
	std:: swap(Arr[L], Arr[high]);
    return L;
}


void heapSort(int Arr[], int n)
{
	// Xay dung cau truc heap (sap xep mang) 
    for (int i=n / 2 - 1; i >= 0; i--) 
        heapify(Arr, n, i); 
  
    // Thay the dau voi muc cuoi cua heap
    for (int i1=n-1; i1>0; i1--) 
    { 
		//Dua dau ve cuoi
		std:: swap(Arr[0], Arr[i1]); 
  
        // Bo phan tu cuoi ra khoi cau truc HeapBinary
        heapify(Arr, i1, 0); 
    } 
}

void heapify(int Arr[], int n, int i) 
{ 
    int largest = i; // Khai bao largest la root
    int l = 2*i; // L = 2*i 
    int r = 2*i + 1; // R = 2*i + 1
  
    // neu L child lon hon largest 
    if (l < n && Arr[l] > Arr[largest]) 
        largest = l; 
  
    // neu R child lon hon largest
    if (r < n && Arr[r] > Arr[largest]) 
        largest = r; 
  
    // neu largest ko phai root 
    if (largest != i) 
    { 
		std::swap(Arr[i], Arr[largest]); 
  
        // Tai tao lai cau truc HeapBinary
        heapify(Arr, n, largest); 
    } 
}		//Nguyen Phong Phu - 20110696

void xuatMang(int Arr[], int n) 
{ 
	printf("Mang sau khi sap xep: ");
    for (int i=0; i<n; ++i) 
        printf("%d ", Arr[i]); 
    printf("\n");
} 

void nhapMang(int Arr[], int &n)
{
	printf("Nhap so luong phtu cua mang: ");
	scanf("%d",&n);
	printf("Nhap mang: ");
	for (int i=0;i<n;i++)
		scanf("%d",&Arr[i]);
}