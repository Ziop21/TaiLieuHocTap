#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext = NULL;
};

struct LIST
{
	NODE* pHead = NULL;
	NODE* pTail = NULL;
};

void xuat_dslk(LIST list);
void themnode_vaodau(LIST& list, int val);
int get_index(NODE* begin, NODE* end);

int main()
{
	LIST ds;
	themnode_vaodau(ds, 4);
	themnode_vaodau(ds, 3);
	themnode_vaodau(ds, 2);
	themnode_vaodau(ds, 1);
	xuat_dslk(ds);
	swap(ds.pHead->data, ds.pTail->data);
	xuat_dslk(ds);
	cout << "So luong node: " << get_index(ds.pHead, ds.pHead) << endl;
	
	int L = get_index(ds.pHead, ds.pHead);
	int R = get_index(ds.pHead, ds.pTail);
	int flag = (L + R) / 2;

	//Xác định node pivot
	NODE* pivot = ds.pHead;
	for (int i = 0; i != flag; i++)
	{
		pivot = pivot->pNext;
	}

	cout << pivot->data << endl;
	return 0;
}

int get_index(NODE* begin, NODE* end)
{
	int sl = 0;;
	for (NODE* i = begin; i != end; i = i->pNext)
	{
		sl++;
	}
	return sl;
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