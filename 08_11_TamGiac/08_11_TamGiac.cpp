#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// Bai 127:
struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;
struct tamgiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct tamgiac TAMGIAC;

void Nhap(DIEM&);
void Xuat(DIEM);

void Nhap(TAMGIAC&);
void Xuat(TAMGIAC);

float KhoangCach(DIEM, DIEM);
float DienTich(TAMGIAC);
float ChuVi(TAMGIAC);
DIEM TrongTam(TAMGIAC);

int KiemTra(TAMGIAC);
DIEM HoanhLonNhat(TAMGIAC);
DIEM TungNhoNhat(TAMGIAC);
float TongKhoangCach(TAMGIAC, DIEM);
int DangTamGiac(TAMGIAC);

int main()
{
	TAMGIAC tg;
	Nhap(tg);
	Xuat(tg);
	int kq = KiemTra(tg);
	if (kq == 1)
		cout << "\nBa dinh tao thanh 1 tam giac";
	else
		cout << "\nBa dinh khong tao thanh 1 tam giac";
	float kq1 = DienTich(tg);
	cout << "\nDien tich = " << kq1;
	float kq2 = ChuVi(tg);
	cout << "\nChu vi = " << kq2;
	DIEM G = TrongTam(tg);
	cout << "\nTrong tam";
	Xuat(G);
	DIEM x = HoanhLonNhat(tg);
	cout << "\nDinh co hoanh do lon nhat: ";
	Xuat(x);
	DIEM y = TungNhoNhat(tg);
	cout << "\nDinh co tung do nho nhat: ";
	Xuat(y);
	DIEM M;
	cout << "\nNhap diem can tinh kc: " << endl;
	Nhap(M);
	cout << "\nDiem tinh khoang cach toi 3 dinh tam giac: ";
	Xuat(M);
	float kq3 = TongKhoangCach(tg, M);
	cout << "\nTong khoang cach tu diem toi 3 dinh la: " << kq3;
	int kq4 = DangTamGiac(tg);
	if (kq4 == 1)
		cout << "\nTam giac can.";
	if (kq4 == 2)
		cout << "\nTam giac vuong can.";
	if (kq4 == 3)
		cout << "\nTam giac vuong.";
	if (kq4 == 4)
		cout << "\nTam giac deu.";
	if (kq4 == 5)
		cout << "\nTam giac thuong.";
	return 0;
}
void Nhap(DIEM& a)
{
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
}
void Xuat(DIEM a)
{
	cout << "\n x = " << a.x;
	cout << "\n y = " << a.y;
}
// Bai 128:
void Nhap(TAMGIAC& t)
{
	cout << "Nhap dinh A:\n";
	Nhap(t.A);
	cout << "Nhap dinh B:\n";
	Nhap(t.B);
	cout << "Nhap dinh C:\n";
	Nhap(t.C);
}
// Bai 129:
void Xuat(TAMGIAC t)
{
	cout << "\nToa do dinh A:";
	Xuat(t.A);
	cout << "\nToa do dinh B:";
	Xuat(t.B);
	cout << "\nToa do dinh C:";
	Xuat(t.C);
}

float KhoangCach(DIEM a, DIEM b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// Bai 130:
int KiemTra(TAMGIAC x)
{
	float a = KhoangCach(x.B, x.C);
	float b = KhoangCach(x.C, x.A);
	float c = KhoangCach(x.A, x.B);
	if (a + b > c && a + c > b && b + c > a)
		return 1;
	return 0;
}
// Bai 131:
float ChuVi(TAMGIAC x)
{
	float a = KhoangCach(x.B, x.C);
	float b = KhoangCach(x.C, x.A);
	float c = KhoangCach(x.A, x.B);
	return (a + b + c);
}
// Bai 132:
float DienTich(TAMGIAC x)
{
	float a = KhoangCach(x.B, x.C);
	float b = KhoangCach(x.C, x.A);
	float c = KhoangCach(x.A, x.B);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
// Bai 133:
DIEM TrongTam(TAMGIAC t)
{
	DIEM G;
	G.x = (t.A.x + t.B.x + t.C.x) / 3;
	G.y = (t.A.y + t.B.y + t.C.y) / 3;
	return G;
}
// Bai 134:
DIEM HoanhLonNhat(TAMGIAC t)
{
	DIEM lc = t.A;
	if (t.B.x > lc.x)
		lc = t.B;
	if (t.C.x > lc.x)
		lc = t.C;
	return lc;
}
// Bai 135:
DIEM TungNhoNhat(TAMGIAC t)
{
	DIEM lc = t.A;
	if (t.B.y < lc.y)
		lc = t.B;
	if (t.C.y < lc.y)
		lc = t.C;
	return lc;
}
// Bai 136:
float TongKhoangCach(TAMGIAC t, DIEM P)
{
	float a = KhoangCach(t.A, P);
	float b = KhoangCach(t.B, P);
	float c = KhoangCach(t.C, P);
	return a + b + c;
}
int DangTamGiac(TAMGIAC t)
{
	float a = KhoangCach(t.B, t.C);
	float b = KhoangCach(t.A, t.C);
	float c = KhoangCach(t.A, t.B);
	if (!(a + b > c && b + c > a && c + a > b))
		return 0;// không là tam giác
	if (a == b && b == c)
		return 1;// cân
	if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
	{
		if (a == b || b == c || a == c)
			return 2;// vuông cân
		return 3;// vuông
	}
	if (a == b || b == c || a == c)
		return 4;// đều
	return 5;// thường
}