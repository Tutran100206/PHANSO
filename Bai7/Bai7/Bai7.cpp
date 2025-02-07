#include<iostream>
#include<cmath>
using namespace std;
struct HONSO
{
	long long phannguyen, tu, mau;
};
struct PHANSO
{
	long long tu, mau;
};
void nhapHS(HONSO& a);
void xuatPS(PHANSO b);
void chuyendoihsthanhPS(HONSO a, PHANSO& b);
long long UCLN(long long a, long long b);
long long BCNN(long long a, long long b);
void rutgon(PHANSO& a);
void hieu2ps(PHANSO a, PHANSO b, PHANSO& hieu);
void tong2hs(PHANSO a, PHANSO b);
void tich2hs(PHANSO a, PHANSO b);
int main() {
	HONSO a, a1;
	PHANSO b, b1;
	nhapHS(a);
	nhapHS(a1);
	chuyendoihsthanhPS(a, b);
	chuyendoihsthanhPS(a1, b1);
	tong2hs(b, b1);
	tich2hs(b, b1);
	return 0;
}
void nhapHS(HONSO& a) {
	cin >> a.phannguyen >> a.tu >> a.mau;
}
void xuatPS(PHANSO b) {
	cout << b.tu << "/" << b.mau << endl;
}
long long UCLN(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return abs(a);
}
long long BCNN(long long a, long long b) {
	return (a / UCLN(a, b)) * b;
}
void rutgon(PHANSO& a) {
	if (a.mau < 0) {
		a.tu = -a.tu;
		a.mau = -a.mau;
	}
	long long w = UCLN(a.tu, a.mau);
	a.tu /= w;
	a.mau /= w;
}
void chuyendoihsthanhPS(HONSO a, PHANSO &b) {
	b.tu = a.phannguyen * a.mau + a.tu;
	b.mau = a.mau;
	rutgon(b);
	xuatPS(b);
}
void hieu2ps(PHANSO a, PHANSO b, PHANSO &hieu) {
	long long w = BCNN(a.mau, b.mau);
	hieu.tu = a.tu * (w / a.mau) - b.tu * (w / b.mau);
	hieu.mau = w;
	rutgon(hieu);
}
void tong2hs(PHANSO a, PHANSO b) {
	PHANSO tong;
	long long w = BCNN(a.mau, b.mau);
	tong.tu = a.tu * (w / a.mau) + b.tu * (w / b.mau);
	tong.mau = w;
	rutgon(tong);
	PHANSO x;
	PHANSO k;
	k.tu = tong.tu / tong.mau;
	k.mau = 1;
	hieu2ps(tong, k, x);
	if (x.tu == 0) {
		cout << k.tu << endl;
	}
	else {
		cout << k.tu << "+" << x.tu << "/" << x.mau << endl;
	}
}
void tich2hs(PHANSO a, PHANSO b) {
	PHANSO tich;
	tich.tu = a.tu * b.tu;
	tich.mau = a.mau * b.mau;
	rutgon(tich);
	PHANSO x;
	PHANSO k;
	k.tu = tich.tu / tich.mau;
	k.mau = 1;
	hieu2ps(tich, k, x);
	if (x.tu == 0) {
		cout << k.tu << endl;
	}
	else {
		cout << k.tu << "+" << x.tu << "/" << x.mau;
	}
}
/*
* input: 
* 5 8 9
* 7 0 10
* output:
* 53/9
* 7/1
* 12+8/9
* 41+2/9
* note: full 20/20 testcase uteoj, 200/200 diem
*/