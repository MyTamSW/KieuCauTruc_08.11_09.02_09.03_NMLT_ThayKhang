#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct phanso
{
	int Tu;
	int Mau;
};
typedef struct phanso PHANSO;

void Nhap(PHANSO&);
void Xuat(PHANSO);

void Nhap(PHANSO[], int&);
void Xuat(PHANSO[], int);

int ktDuong(PHANSO);
int DemDuong(PHANSO[], int);
int SoSanh(PHANSO, PHANSO);
PHANSO LonNhat(PHANSO[], int);
int ViTriNhoNhat(PHANSO[], int);
PHANSO DuongDau(PHANSO[], int);
PHANSO DuongNhoNhat(PHANSO[], int);
int ktAm(PHANSO);
int TimViTri(PHANSO[], int);
void HoanVi(PHANSO&, PHANSO&);
void SapTang(PHANSO[], int);

int main()
{
	PHANSO a[100];
	int n;
	Nhap(a, n);
	Xuat(a, n);

	int kq = DemDuong(a, n);
	cout << "\nSo luong phan so duong cua mang: " << kq;

	PHANSO x = LonNhat(a, n);
	cout << "\nPhan so lon nhat trong mang la: ";
	Xuat(x);

	int kq1 = ViTriNhoNhat(a, n);
	cout << "\nVi tri co gia tri nho nhat trong mang la: " << kq1;

	PHANSO y = DuongDau(a, n);
	cout << "\nGia tri duong dau tien trong mang: ";
	Xuat(y);

	PHANSO z = DuongNhoNhat(a, n);
	cout << "\nGia tri duong nho nhat trong mang la: ";
	Xuat(z);

	cout << "\nMang sau khi sap tang la: ";
	SapTang(a, n);
	Xuat(a, n);
	return 0;
}
void Nhap(PHANSO& x)
{
	cout << "Nhap tu: ";
	cin >> x.Tu;
	cout << "Nhap mau: ";
	cin >> x.Mau;
}
void Xuat(PHANSO x)
{
	cout << x.Tu << "/" << x.Mau;
}
// Bai 182
void Nhap(PHANSO a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: " << endl;
		Nhap(a[i]);
	}
}
// Bai 183
void Xuat(PHANSO a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		Xuat(a[i]);
		cout << "   ";
	}
}
//  Bai 184
int ktDuong(PHANSO x)
{
	if (x.Tu * x.Mau > 0)
		return 1;
	return 0;
}
int DemDuong(PHANSO a[], int n)
{
	int dem = 0;
	for (int i = 0; i <= n - 1; i++)
		if (ktDuong(a[i]))
			dem++;
	return dem;
}
// Bai 185
int SoSanh(PHANSO x, PHANSO y)
{
	float a = (float)x.Tu / x.Mau;
	float b = (float)y.Tu / y.Mau;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

PHANSO LonNhat(PHANSO a[], int n)
{
	PHANSO lc = a[0];
	for (int i = 0; i <= n - 1; i++)
		if (SoSanh(a[i], lc) == 1)
			lc = a[i];
	return lc;
}
// Bai 186
int ViTriNhoNhat(PHANSO a[], int n)
{
	int lc = 0;
	for (int i = 0; i <= n - 1; i++)
		if (SoSanh(a[i], a[lc]) == -1)
			lc = i;
	return lc;
}
// Bai 187
PHANSO DuongDau(PHANSO a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		if (ktDuong(a[i]))
			return a[i];
	PHANSO lc = { 0,1 };
	return lc;
}
// Bai 188
PHANSO DuongNhoNhat(PHANSO a[], int n)
{
	if (n == 0)
	{
		PHANSO lc = { -1,1 };
		return lc;
	}
	PHANSO lc = DuongNhoNhat(a, n - 1);
	if (ktDuong(a[n - 1]) == 0)
		return lc;
	if (ktDuong(lc) == 0)
		return a[n - 1];
	if (SoSanh(a[n - 1], lc) == -1)
		lc = a[n - 1];
	return lc;
}
// Bai 189
int ktAm(PHANSO x)
{
	if (x.Tu * x.Mau < 0)
		return 1;
	return 0;
}
int TimViTri(PHANSO a[], int n)
{
	if (n == 0)
		return -1;
	int lc = TimViTri(a, n - 1);
	if (ktAm(a[n - 1]) == 0)
		return lc;
	//if (ktAm(lc) == 0)
		return n - 1;
	if (SoSanh(a[n - 1], a[lc]) == -1)
		lc = n - 1;
	return lc;
}
// Bai 190
void HoanVi(PHANSO &a, PHANSO &b)
{
	PHANSO temp = a;
	a = b;
	b = temp;
}
void SapTang(PHANSO a[], int n)
{
	for (int i = 0;i <= n - 2;i++)
		for (int j = i + 1;j <= n - 1;j++)
			if (SoSanh(a[i], a[j]) == 1)
				HoanVi(a[i], a[j]);
}