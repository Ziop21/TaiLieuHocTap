#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead = NULL;
	NODE* pTail = NULL;
};

void menu(LIST& list);
void xuat_dslk(LIST list);
void themnode_vaodau(LIST& list, int val);
void themnode_vaocuoi(LIST& list, int val);
void themnode_vaogiatribatky(LIST& list, int val, int val_0);
NODE* xoanode_dau(LIST& list);
NODE* xoanode_cuoi(LIST& list);
void xoanode_batki(LIST& list, int val);


void isempty(LIST& list); //hang doi//
void push(LIST& list);
int pop(LIST& list);


void QuickSort(LIST& list, NODE* low, NODE* high);
int get_index(NODE* begin, NODE* end);
NODE* getNodePrevious(LIST list, NODE* end);

int main()
{
	LIST list;



	/*push(list);
	push(list);
	push(list);
	pop(list);
	isempty(list);*/
	menu(list);
}
void isempty(LIST& list) //hang doi//
{
	if (list.pHead == NULL && list.pTail == NULL)
		cout << "hang doi trong..." << endl;
	else
		cout << "hang doi ban..." << endl;
}
void push(LIST& list)
{
	int val;
	cout << "nhap gia tri: ";
	cin >> val;
	themnode_vaodau(list, val);
	cout << "Them gia tri " << val << " thanh cong... " << endl;
}
int pop(LIST& list)
{
	NODE* kq = xoanode_dau(list);
	cout << "node lay ra khoi stack: " << kq->data << endl;
	return kq->data;
}

void menu(LIST &list)
{
	while (true)
	{
		int choice;
		system("cls");
		cout << "1. Them node vao DSLK" << endl;
		cout << "2. Duyet DSLK" << endl;
		cout << "3. Xoa node" << endl;
		cout << "4. Sap xep tang dan (QuickSort). " << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			while (true)
			{
				int val;
				int choice_2;
				system("cls");
				cout << "1. Dau" << endl;
				cout << "2. Cuoi" << endl;
				cout << "3. Sau gia tri tu chon" << endl;
				cout << "0. Thoat" << endl;
				cout << "Nhap lua chon: ";
				cin >> choice_2;
				if (choice_2 == 1)
				{
					cout << "Nhap gia tri muon them vao: ";
					cin >> val;
					themnode_vaodau(list, val);
					break;
				}
				else if (choice_2 == 2)
				{
					cout << "Nhap gia tri muon them vao: ";
					cin >> val;
					themnode_vaocuoi(list, val);
					break;
				}
				else if (choice_2 == 3)
				{
					int val_0;
					cout << "Nhap gia tri muon them vao: ";
					cin >> val;
					cout << "Ban muon them gia tri vua nhap vao sau gia tri: ";
					cin >> val_0;
					themnode_vaogiatribatky(list, val, val_0);
					break;
				}
				else if (choice_2 == 0)
				{
					break;
				}
			}
			system("pause");
			break;
		case 2:
			xuat_dslk(list);
			system("pause");
			break;
		case 3:
		{
			while (true)
			{
				int val;
				int choice_2;
				system("cls");
				cout << "1. Dau" << endl;
				cout << "2. Cuoi" << endl;
				cout << "3. Sau gia tri tu chon" << endl;
				cout << "0. Thoat" << endl;
				cout << "Nhap lua chon: ";
				cin >> choice_2;
				if (choice_2 == 1)
				{
					NODE* kq = xoanode_dau(list);
					if (kq != NULL)
					cout << "Node vua bi xoa la: " << kq->data << endl;
					else
						cout << "Danh sach trong..." << endl;
					delete(kq);
					xuat_dslk(list);
					break;
				}
				else if (choice_2 == 2)
				{
					NODE* kq = xoanode_cuoi(list);
					if (kq != NULL)
						cout << "Node vua bi xoa la: " << kq->data << endl;
					else
						cout << "Danh sach trong..." << endl;
					delete(kq);
					xuat_dslk(list);
					break;
				}
				else if (choice_2 == 3)
				{
					int val;
					cout << "Nhap gia tri: ";
					cin >> val;

					xoanode_batki(list, val);
					xuat_dslk(list);
					break;
				}
				else if (choice_2 == 0)
				{
					break;
				}
			}
			system("pause");
			break;
		}
		case 4:
		{
			QuickSort(list, list.pHead, list.pTail);
			xuat_dslk(list);
			system("pause");
			break;
		}
		default:
			break;
		}
		cout << endl;
		if (choice == 0)
			break;
	}
}

void QuickSort(LIST& list, NODE *low, NODE* high)
{
	int L = get_index(list.pHead, low);
	int R = get_index(list.pHead, high);

	NODE* key = list.pHead;
	for (int i = 0; i != (L + R) / 2; i++)
	{
		key = key->pNext;
	}

	int i = L;
	int j = R;
	NODE* temp_L = low;
	NODE* temp_R = high;
	
	while (i < j)
	{
		
		while (temp_L->data < key->data)
		{
			i++;
			temp_L = temp_L->pNext;
		}
		while (temp_R->data > key->data)
		{
			j--;
			temp_R = getNodePrevious(list, temp_R);
		}
		if (i <= j)
		{
			swap(temp_L->data, temp_R->data);
			i++;
			temp_L = temp_L->pNext;
			j--;
			temp_R = getNodePrevious(list, temp_R);
		}
	}
	
	if (i < R)
		QuickSort(list, temp_L, high);
	if (j > L)
		QuickSort(list, low, temp_R);
}
NODE* getNodePrevious(LIST list, NODE* end)
{
	for (NODE* temp = list.pHead ;; temp = temp->pNext)
	{
		if (temp->pNext == end)
		{
			return temp;
		}
	}
}
int get_index(NODE* begin, NODE* end)
{
	int index = 0;
	for (NODE* i = begin; i != end; i = i->pNext)
	{
		index++;
	}
	return index;
}

void xoanode_batki(LIST& list, int val) //Nguyen Phong Phu - 20110696
{
	if (list.pHead == NULL)
	{
		cout << "DANH SACH TRONG..." << endl;
	}
	else if (list.pHead->data == val)
	{
		NODE* kq = xoanode_dau(list);
		cout << "Node vua bi xoa la: " << val << endl;
		delete(kq);
	}
	else
	{
		NODE* i;
		for (i = list.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext != NULL)
				if (i->pNext->data == val)
				{
					NODE* kq = i->pNext;
					if (kq == list.pTail)
					{ 
						xoanode_cuoi(list);
						cout << "Node vua bi xoa la: " << val << endl;						
					}
					else
					{
						i->pNext = kq->pNext;
						cout << "Node vua bi xoa la: " << val << endl;
					}
					delete(kq);
					return;
				}
		}
		cout << "Khong co gia tri vua nhap trong dslk..." << endl;
	}
}
NODE* xoanode_cuoi(LIST& list)
{
	if (list.pHead == NULL)
	{
		return NULL;
	}
	else if (list.pHead == list.pTail)
	{
		NODE* kq = list.pHead;
		list.pHead = list.pTail = NULL;
		return kq;
	}
	else
	{
		NODE* kq = list.pTail;
		for (NODE* i = list.pHead; ; i = i->pNext)
		{
			if (i->pNext == list.pTail)
			{
				i->pNext = NULL;
				list.pTail = i;
				return kq;
			}
		}
	}
}
NODE* xoanode_dau(LIST& list) 
{
	if (list.pHead == NULL)
	{
		return NULL;
	}
	else if (list.pHead == list.pTail)
	{
		NODE* temp = list.pHead;
		list.pHead = list.pTail = NULL;
		return temp;
	}
	else
	{
		NODE* temp1 = list.pHead;
		list.pHead = list.pHead->pNext;
		return temp1;
	}

}
void themnode_vaogiatribatky(LIST& list, int val, int val_0) //Nguyen Phong Phu 20110696
{
	//Di tim node co gia tri val_0 trong dslk
	NODE* vitri = list.pHead;
	while (vitri != NULL)
	{
		if (vitri->data == val_0)
			break;
		vitri = vitri->pNext;
	}

	//Neu khong co gia tri do trong dslk hoac neu la phan tu cuoi cung trong dslk
	if (vitri == NULL || vitri->data == list.pTail->data)
	{
		themnode_vaocuoi(list, val);
	}
	//truong hop con lai
	else
	{
		NODE* temp = new NODE;
		temp->data = val;
		temp->pNext = vitri->pNext;
		vitri->pNext = temp;
	}
}
void themnode_vaocuoi(LIST& list, int val)
{
	NODE* temp = new NODE;
	temp->data = val;
	temp->pNext = NULL;

	if (list.pHead == NULL && list.pTail == NULL)
	{
		list.pHead = list.pTail = temp;
	}
	else
	{
		list.pTail->pNext = temp;
		list.pTail = temp;
	}
}
void themnode_vaodau(LIST& list, int val)
{
	NODE* temp = new NODE;
	temp->data = val;
	temp->pNext = NULL;

	if (list.pHead == NULL && list.pTail == NULL)
	{
		list.pHead = list.pTail = temp;
	}
	else
	{
		temp->pNext = list.pHead;
		list.pHead = temp;
	}
}
void xuat_dslk(LIST list)
{
	cout << "---------DANH SACH LIEN KET---------" << endl;
	NODE* temp = list.pHead;
	while (temp != NULL)
	{
		cout << temp->data;
		if (temp->pNext != NULL)
			cout << "\t --> \t";
		temp = temp->pNext;
	}
	cout << endl;
}