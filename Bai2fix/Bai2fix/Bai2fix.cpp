#include<iostream>
#include<cmath>
using namespace std;

struct PHANSO
{
	long long tu, mau;
};

void nhap1PS(PHANSO& a);
void nhap(PHANSO k[], int& n);
void xuat1PS(PHANSO a);
void cacthaotactrenPS(PHANSO k[], int n);
long long UCLN(long long a, long long b);
long long BCNN(long long a, long long b);
void rutgon(PHANSO& a);
double chiaPS(PHANSO a);
void PSmax(PHANSO k[], int n);
void TongPS(PHANSO k[], int n);
void TichPS(PHANSO k[], int n);
void PSnghichdao(PHANSO k[], int n);

int main() {
	PHANSO k[50];
	int n;
	nhap(k, n);
	cacthaotactrenPS(k, n);
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

void xuat1PS(PHANSO a) {
	cout << a.tu << " " << a.mau << endl;
}

void cacthaotactrenPS(PHANSO k[], int n) {
	PSmax(k, n);
	TongPS(k, n);
	TichPS(k, n);
	PSnghichdao(k, n);
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

double chiaPS(PHANSO a) {
	rutgon(a);
	double x = (1.0) * a.tu / a.mau;
	return x;
}

void PSmax(PHANSO k[], int n) {
	double max = chiaPS(k[0]);
	PHANSO tam = k[0];
	for (int i = 0; i < n; i++) {
		double s = chiaPS(k[i]);
		if (s > max) {
			max = s;
			tam = k[i];
		}
	}
	rutgon(tam);
	xuat1PS(tam);
}

void TongPS(PHANSO k[], int n) {
	PHANSO tong;
	tong.tu = 0;
	tong.mau = k[0].mau;
	for (int i = 0; i < n; i++) {
		tong.mau = BCNN(tong.mau, k[i].mau);
	}
	for (int i = 0; i < n; i++) {
		tong.tu += k[i].tu * (tong.mau / k[i].mau);
	}
	rutgon(tong);
	xuat1PS(tong);
}

void TichPS(PHANSO k[], int n) {
	PHANSO tich;
	tich.tu = 1;
	tich.mau = 1;
	for (int i = 0; i < n; i++) {
		tich.tu *= k[i].tu;
		tich.mau *= k[i].mau;
		rutgon(tich);
	}
	xuat1PS(tich);
}

void PSnghichdao(PHANSO k[], int n) {
	for (int i = 0; i < n; i++) {
		rutgon(k[i]);
		if (k[i].tu < 0) {
			k[i].tu = -k[i].tu;
			k[i].mau = -k[i].mau;
		}
		swap(k[i].tu, k[i].mau);
		cout << k[i].tu << " " << k[i].mau;
		if (i != n - 1) {
			cout << " ";
		}
	}
}
/*
* input:
* 18
* -4 -7
* 6 6
* -3 5
* 4 -10
* -7 -9
* 4 7
* -6 -5
* 6 -1
* -6 10
* 1 -6
* -8 -2
* 1 -7
* 3 1
* -4 5
* 2 6
* -4 9
* 10 -3
* -6 7
* output:
* 4 1
* -397 210
* 16384 643125
* 7 4 1 1 -5 3 -5 2 9 7 7 4 5 6 -1 6 -5 3 -6 1 1 4 -7 1 1 3 -5 4 3 1 -9 4 -3 10 -7 6
* note: full 200/200, 20/20 testcase uteoj
* chu y rutgon ps sau moi lan tinh tich va dau cach cuoi cung
*/
