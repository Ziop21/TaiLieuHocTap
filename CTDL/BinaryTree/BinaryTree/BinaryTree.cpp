#include <iostream>
using namespace std;

#define LH -1
#define RH 1
#define EH 0

struct AVLNODE
{
	int data;
	int balance;	//Chỉ số cân bằng LH lệch trái, EH cân bằng, RH lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
};
typedef struct AVLNODE* AVLTree;

AVLTree createNULLTree();
AVLNODE* createNode(int x);
AVLNODE* LeftRotate(AVLNODE* NODE);
AVLNODE* RightRotate(AVLNODE* NODE);
int Insert(AVLNODE* &Root, int x);
int LeftBalance(AVLTree& t);
int RightBalance(AVLTree& t);
int DeleteNode(AVLTree& Root, int x);
int timNodeTheMang(AVLNODE*& Root, AVLNODE*& y);

//Hàm có thể cần tới
void NLR(AVLTree t);
int SetBalance(AVLNODE* node);
int GetHeight(AVLNODE* node);

int main()
{
	AVLNODE* root = createNULLTree();
	int Arr[] = {8, 3, 10, 2, 5, 9, 11, 1, 4, 7, 12, 6};
	for (int i = 0; i < 12; i++)
	{
		Insert(root, Arr[i]);
	}
	
	DeleteNode(root, 9);
	NLR(root);
	DeleteNode(root, 5);
	
	DeleteNode(root, 7);
	
	DeleteNode(root, 1);
	
	//NLR(root);
	return 0;
}

int DeleteNode(AVLTree& Root, int x)
{
	if (Root != NULL)
	{
		if (Root->data > x)
		{
			int temp = DeleteNode(Root->pLeft,x);	
			if (temp == 2)
			{
				switch (Root->balance)
				{
					case LH:
					{
						Root->balance = EH;
						return 2;
					}
					case EH:
					{
						Root->balance = RH;
						return 1;
					}
					case RH:
					{
						return RightBalance(Root);
					}
					default:
						break;
				}
			}
		}
		else if (Root->data < x)
		{
			int temp = DeleteNode(Root->pRight, x);
			if (temp == 2)
			{
				switch (Root->balance)
				{
					case RH:
					{
						Root->balance = EH;
						return 2;
					}
					case EH:
					{
						Root->balance = LH;
						return 1;
					}
					case LH:
					{
						return LeftBalance(Root);
					}
					default:
						break;
				}
			}
		}
		else //Tìm được node cần tìm
		{
			AVLNODE* getAddress = Root;
			if (Root->pLeft == NULL)
			{
				Root = Root->pRight;
			}
			else if (Root->pRight == NULL)
			{
				Root = Root->pLeft;				
			}
			else
			{
				int temp = timNodeTheMang(getAddress, getAddress->pRight);
				if (temp == 2)
				{
					switch (Root->balance)
					{
						case RH:
						{
							Root->balance = EH;
							return 2;
						}
						case EH:
						{
							Root->balance = LH;
							return 1;
						}
						case LH:
						{
							return LeftBalance(Root);
						}
						default:
							break;
					}
				}
			}	
			delete(getAddress);
			return 2;
		}
	}
	else
	{
		cout << "Khong tim thay ... " << endl;
		return 0;
	}
}

int timNodeTheMang(AVLNODE* &Root, AVLNODE* &y)
{
	if (y->pLeft != NULL)
	{
		int temp = timNodeTheMang(Root, y->pLeft);
		
		if (temp == 2)
		{
			switch (y->balance)
			{
				case LH:
				{
					y->balance = EH;
					return 2;
				}
				case EH:
				{
					y->balance = RH;
					return 1;
				}
				case RH:
				{
					return RightBalance(y);
				}
				default:
					break;
			}
		}

		return temp;
	}
	else
	{
		Root->data = y->data;
		Root = y;
		y = y->pRight;
		return 2;
	}
}

int Insert(AVLNODE* &Root, int x)	
{
	// return 0 là thêm thất bại
	// return 1 là thêm thành công và ko làm thay đổi chiều cao cây
	// return 2 là thêm thành công và làm thay đổi chiều cao cây 
	if (Root != NULL)
	{
		if (Root->data == x)
		{
			cout << "Gia tri them vao bi trung...\n";
			return 0;
		}
		else if (Root->data > x)
		{
			//Khai báo temp để kiểm tra xem tình trạng cây sau khi thêm vào
			//Và tiến hành thêm node
			int temp = Insert(Root->pLeft, x);
			//Nếu thêm vào và có thay đổi chiều cao
			if (temp == 2)
			{
				//Duyệt chỉ số cân bằng
				switch (Root->balance)
				{
					//TH node gốc là node lệch trái thì sau khi thêm vào sẽ khiến cây bị mất cân bằng 
					case LH:
						//Tiến hành cân bằng
						return LeftBalance(Root);
					//TH node gốc là node cân bằng
					case EH:
						//Cập nhật chỉ số cân bằng cho node gốc
						Root->balance = LH;
						//Khi node gốc đang cân bằng thì thêm node mới vào sẽ làm cây bị thay đổi chiều cao (lệch trái nhưng chưa mất cân bằng)
						//nên return 2
						return 2;
					//TH node gốc đang là node lệch phải 
					case RH:
						//Sau khi thêm node vào bên trái thì cây sẽ trở thành cây cân bằng
						//Nên cập nhật chỉ số cân bằng = EH
						Root->balance = EH;
						//Trả về 1 vì thêm vào thành công và ko thay đổi chiều cao cây
						return 1;
					default:
						break;
				}
			}
		}
		else if (Root->data < x)
		{
			//Tương tự như ở trên
			int temp = Insert(Root->pRight, x);
			if (temp == 2)
			{
				switch (Root->balance)
				{
					case RH:
						return RightBalance(Root);
					case EH:
						Root->balance = RH;
						return 2;
					case LH:
						Root->balance = EH;
						return 1;
					default:
						break;
				}
			}
		}
	}
	else //Nếu đang node là NULL
	{
		//Thêm node mới vào
		Root = createNode(x);
		//Làm thay đổi chiều cao cây nên trả về 2
		return 2;
	}
}

int LeftBalance(AVLTree& t)
{
	switch (t->pLeft->balance) //Duyệt chỉ số cân bằng của cây con bên trái
	{
		//Nếu cây con cũng lệch trái
		case LH: //Left - Left
		{
			//Xoay
			t = LeftRotate(t);
			//Cập nhật chỉ số cân bằng
			t->balance = EH;
			t->pRight->balance = EH;
			return 2;
		}
		//Nếu cây con đang cân bằng
		case EH: //Left - Equal
		{
			t = LeftRotate(t);
			t->balance = RH;
			t->pRight->balance = LH;
			return 1;
		}
		//Nếu cây con đang lệch phải
		case RH: //Left - Right
		{
			//Xoay
			t->pLeft = RightRotate(t->pLeft);
			t = LeftRotate(t);
			//Cập nhật chỉ số cân bằng
			switch (t->balance)
			{
				case EH:
				{
					t->pLeft->balance = EH;
					t->pRight->balance = EH;
				}
				case LH:
				{
					t->pRight->balance = RH;
					t->pLeft->balance = EH;
				}
				case RH:
				{
					t->pLeft->balance = LH;
					t->pRight->balance = EH;
				}
				default:
					break;
			}
			return 1;
			t->balance = EH;
			break;
		}
		default:
			break;
	}
}
int RightBalance(AVLTree &t)
{
	switch (t->pRight->balance)
	{
		case RH: //Right - Right
		{
			t = RightRotate(t);
			t->balance = EH;
			t->pLeft->balance = EH;
			return 2;
		}
		case EH: //Right - Equal
		{
			t = RightRotate(t);
			t->balance = LH;
			t->pLeft->balance = RH;
			return 1;
		}
		case LH: //Right - Left
		{
			t->pRight = LeftRotate(t->pRight);
			t = RightRotate(t);
			switch (t->balance)
			{
				case EH:
				{
					t->pRight->balance = EH;
					t->pLeft->balance = EH;
					return 1;
				}
				case RH:
				{
					t->pLeft->balance = LH;
					t->pRight->balance = EH;
					return 1;
				}
				case LH:
				{
					t->pRight->balance = RH;
					t->pLeft->balance = EH;
					return 1;
				}
				default:
					break;
			}
			t->balance = EH;
			break;
		}
		default:
			break;
	}
}

AVLNODE* LeftRotate(AVLNODE* P)
{
	//Hàm thực hiện xoay cứ chạy thử là hiểu
	AVLNODE* newRoot = createNULLTree();
	newRoot = P->pLeft;
	P->pLeft = newRoot->pRight;
	newRoot->pRight = P;

	return newRoot;
}
AVLNODE* RightRotate(AVLNODE* P)
{
	AVLNODE* newRoot = createNULLTree();
	newRoot = P->pRight;
	P->pRight = newRoot->pLeft;
	newRoot->pLeft = P;

	return newRoot;
}

AVLTree createNULLTree()
{
	AVLNODE* root = NULL;
	return root;
}
AVLNODE* createNode(int x)
{
	AVLNODE* temp = new AVLNODE;
	temp->data = x;
	temp->balance = EH;
	temp->pLeft = temp->pRight = NULL;
	return temp;
}

//Hàm có thể sẽ dùng đến
void NLR(AVLTree t)
{
	if (t != NULL)
	{
		cout << t->data << "(" << t->balance << ")\t\t";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
int SetBalance(AVLNODE* node)
{
	if (GetHeight(node->pLeft) > GetHeight(node->pRight))
	{
		return LH;
	}
	else if (GetHeight(node->pLeft) < GetHeight(node->pRight))
	{
		return RH;
	}
	else
	{
		return EH;
	}
}
int GetHeight(AVLNODE* node)
{
	if (node != NULL)
	{
		int left = GetHeight(node->pLeft);
		int right = GetHeight(node->pRight);
		if (left < right)
			return right + 1;
		else
			return left + 1;
	}
	else
	{
		return 0;
	}
}