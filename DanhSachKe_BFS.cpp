/*DUYET DANH SACH KE BANG THUAT TOAN BFS VOI 
INPUT TU FILE 'input.dsk.txt'*/

// file: input_dsk.txt
//10
//1 2 3 5 10 0
//2 1 4 0
//3 1 6 7 9 0
//4 2 0
//5 1 8 0
//6 3 7 0
//7 3 6 0
//8 5 9 0
//9 3 8 0
//10 1 0

#include<iostream>
#include<fstream>
#include<queue>
#define MAX 20
int sizes = 0;
using namespace std;
struct node {
	int data;
	node* next;
};
node* first[MAX];
void init()
{
	for (int i = 0; i < sizes; i++)
	{
		first[i] = NULL;
	}
}
node* createNode(int x)
{
	node* new_node = new node;
	if (!new_node)
		return NULL;
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}
void insert_last(node*&f,int x)
{
	node* p = createNode(x);
	if (f == NULL)
	
		f = p;

	else
	{
		node* current = f;
		while (current->next != NULL)
			current = current->next;
		current->next = p;
	}
}
void input_file()
{
	ifstream inData;
	int x;
	inData.open("input_dsk.txt");
	if (inData.is_open())
	{
		int x;
		inData >> sizes;

		for (int i = 0; i < sizes; i++)
		{
			inData >> x;
			while (x != 0)//dieu kien dung nhap canh ke
			{
				insert_last(first[i], x);
				inData >> x;
			}
			cout << endl;
		}

		inData.close();
		cout << "da doc file thanh cong" << endl;
	}
	else
		cout << "mo file khong thanh cong" << endl;

}

void BFS(int startVertex)
{
	bool* visited = new bool[MAX] {false};//Mang kiem tra dinh da tham chua
	queue<int>q;
	visited[startVertex] = true;
	q.push(startVertex);
	while (!q.empty())//neu hang doi chua rong
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 0; i < sizes; i++)
		{
			node* p = first[i];
			while (p != NULL)
			{	
				int num = p->data;
				if (!visited[num])//neu chua duoc den tham
				{
					q.push(num);
					visited[num]=true;//danh dau da tham roi, khong can duyet no nua
				}
				p = p->next;
			}
		}

	}
	delete[]visited;

}
void output()
{
	for (int i = 0; i < sizes; i++)
	{
		node* p = first[i];
		while (p!=NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
void free()
{
	for (int i = 0; i < sizes; i++)
	{
		node* p = first[i];
		while (p != NULL)
		{
			node* xoa = p;
			p = p->next;
			delete xoa;

		}
		first[i] = NULL;
	}

}
int main()
{
	int x;
	input_file();
	output();
	int startVertex;
	cout << "Nhap dinh duyet dau tien: "; cin >> startVertex;
	BFS(startVertex);
	free();
	system("pause");
	return 0;
}