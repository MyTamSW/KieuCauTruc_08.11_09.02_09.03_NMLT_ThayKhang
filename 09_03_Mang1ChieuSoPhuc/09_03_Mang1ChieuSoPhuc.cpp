#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct sophuc
{
	int Thuc;
	int Ao;
};
typedef struct sophuc SOPHUC;

void Nhap(SOPHUC&);
void Xuat(SOPHUC);

void Nhap(SOPHUC[], int&);
void Xuat(SOPHUC[], int);

SOPHUC Tong(SOPHUC, SOPHUC);
SOPHUC Tong(SOPHUC[], int);
SOPHUC DauTien(SOPHUC[], int);
void HoanVi(SOPHUC&, SOPHUC&);
void SapTang(SOPHUC[], int);

int main()
{
	SOPHUC a[100];
	int n;
	Nhap(a, n);
	Xuat(a, n);

	SOPHUC x = Tong(a, n);
	cout << "\nTong la: ";
	Xuat(x);

	SOPHUC y = DauTien(a, n);
	cout << "\nSo phuc dau tien co phan thuc va ao duong la: ";
	Xuat(y);

	cout << "\nSap tang theo phan thuc la: ";
	SapTang(a, n);
	Xuat(a, n);
	return 0;
}
void Nhap(SOPHUC& a)
{
	cout << "\n\tNhap thuc: ";
	cin >> a.Thuc;
	cout << "\tNhap ao: ";
	cin >> a.Ao;
}
void Xuat(SOPHUC a)
{
	cout << a.Thuc << "+" << a.Ao << "i" << "   ";
}
//Bai 191
void Nhap(SOPHUC a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		Nhap(a[i]);
	}
}
//Bai 192
void Xuat(SOPHUC a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		Xuat(a[i]);
}
// Bai 193
SOPHUC Tong(SOPHUC a, SOPHUC b)
{
	SOPHUC s;
	s.Thuc = a.Thuc + b.Thuc;
	s.Ao = a.Ao + b.Ao;
	return s;
}
SOPHUC Tong(SOPHUC a[], int n)
{
	SOPHUC s = { 0,0 };
	for (int i = 0; i <= n - 1; i++)
		s = Tong(s, a[i]);
	return s;
}
// Bai 194
SOPHUC DauTien(SOPHUC a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		if (a[i].Thuc > 0 && a[i].Ao > 0)
			return a[i];
	SOPHUC lc = { 0,0 };
	return lc;
}
//Bai 195
void HoanVi(SOPHUC& a, SOPHUC& b)
{
	SOPHUC temp = a;
	a = b;
	b = temp;
}
void SapTang(SOPHUC a[], int n)
{
	for (int i = 0;i <= n - 2;i++)
		for (int j = i + 1;j <= n - 1;j++)
			if (a[i].Thuc > a[j].Thuc)
				HoanVi(a[i], a[j]);
}