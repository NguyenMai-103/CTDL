#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}
void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= " << a[i] << endl;
	}
}
void swap(int &a, int &b)
{
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
}
void selectionSort(int a[], int n)
{
	int min_pos;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (int j = i+1; j < n; j++)
		{
			
			if (a[j] < a[min_pos])
				min_pos = j;
		}
		swap(a[i], a[min_pos]);
	}
}
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
}
void bubleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}
int main() {
	int a[MAX];
	int n, chon;
	bool flag = false;
	
	do {
		cout << "Nhap so luong phan tu trong mang: ";
		cin >> n;
		if (n < 0 || n>100)
			cout << "So luong phan tu khong hop le, moi nhap lai" << endl;

	} while (n < 0 || n>100);
	do
	{
		cout << "1. Nhap mang" << endl;
		cout << "2. xuat mang" << endl;
		cout << "3. selection sort" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chon;
		switch (chon) {
		case 1:
		{
			cout << "nhap mang: " << endl;
			nhapMang(a, n);
			flag = true;
			break;
		}
		case 2:
		{
			if (flag)
			{
				xuatMang(a, n);
			}
			else
				cout << "Can nhap mang de thuc hien tiep cac thao tac khac" << endl;
			break;
		}
		case 3:
		{
			if (flag)
			{
				selectionSort(a, n);
				cout << "da sap xep thanh cong" << endl;
			}
			else
				cout << "Can nhap mang de thuc hien cac thao tac khac" << endl;
			break;
		}
		case 4:
		{
			if (flag)
			{
				interchangeSort(a, n);
				cout << "da sap xep thanh cong" << endl;
			}
			else
				cout << "Can nhap mang de thuc hien cac thao tac khac" << endl;
			break;
		}
		case 5:
		{
			if (flag)
			{
				bubleSort(a, n);
				cout << "da sap xep thanh cong" << endl;
			}
			else
				cout << "Can nhap mang de thuc hien cac thao tac khac" << endl;
			break;
		}
		}
	} while (chon != 0);
	
	
	system("pause");
	return 0;
}