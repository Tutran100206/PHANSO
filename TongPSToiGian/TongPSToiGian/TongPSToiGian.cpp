#include<iostream>
#include<cmath>
using namespace std;
struct PHANSO
{
	long int tu, mau;
};
void nhap1PS(PHANSO& a);
void nhap(PHANSO k[], int& n);
long int UCLN(long int a, long int b);
long int BCNN(long int a, long int b);
void rutgon(PHANSO& a);
void Tongpstoigian(PHANSO k[], int n);
int main() {
	PHANSO k[100];
	int n;
	nhap(k, n);
	Tongpstoigian(k, n);
	return 0;
}
void nhap1PS(PHANSO& a) {
	cin >> a.tu >> a.mau;
}
void nhap(PHANSO k[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		nhap1PS(k[i]);
	}
}
void xuat(PHANSO a) {
	cout << a.tu << " " << a.mau;
}
long int UCLN(long int a, long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return abs(a);
}
long int BCNN(long int a, long int b) {
	return (a / UCLN(a, b)) * b;
}
void rutgon(PHANSO &a) {
	if (a.mau < 0) {
		a.tu = -a.tu;
		a.mau = -a.mau;
	}
	long int w = UCLN(a.tu, a.mau);
	a.tu /= w;
	a.mau /= w;
}
void Tongpstoigian(PHANSO k[], int n) {
	PHANSO tong;
	tong.tu = 0;
	tong.mau = k[0].mau;
	for (int i = 1; i < n; i++) {
		tong.mau = BCNN(tong.mau, k[i].mau);
	}
	for (int i = 0; i < n; i++) {
		tong.tu += k[i].tu * (tong.mau / k[i].mau);
	}
	rutgon(tong);
	xuat(tong);
}