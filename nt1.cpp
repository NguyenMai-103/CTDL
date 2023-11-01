#include<iostream>
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
int main() {
	int a[MAX];
	int n;
	do {
		cout << "Nhap so luong phan tu trong mang: ";
		cin >> n;
		if (n < 0 || n>100)
			cout << "So luong phan tu khong hop le, moi nhap lai" << endl;

	} while (n < 0 || n>100);
	nhapMang(a, n);
	xuatMang(a, n);
	system("pause");
	return 0;
 }