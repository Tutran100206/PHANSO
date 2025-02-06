#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
struct PHANSO
{
	long long tu, mau;
};
void nhap(string &s);
void chuyendoiso(string s, PHANSO& k);
void xuat(PHANSO k);
void xuatPS(PHANSO k, PHANSO k1);
int UCLN(long long a, long long b);
int BCNN(long long a, long long b);
void rutgon(PHANSO &k);
void tong2PS(PHANSO k, PHANSO k1);
void hieu2PS(PHANSO k, PHANSO k1);
void tich2PS(PHANSO k, PHANSO k1);
void thuong2PS(PHANSO k, PHANSO k1);
void rutgonPS(PHANSO& k, PHANSO& k1);
void quydongsaukhirutgon(PHANSO k, PHANSO k1);
void sosanh2PS(PHANSO k, PHANSO k1);
void cacthaotacphanso(PHANSO k, PHANSO k1);
int main() {
	PHANSO k, k1;
	string s,s1;
	nhap(s);
	nhap(s1);
	chuyendoiso(s, k);
	chuyendoiso(s1, k1);
	cacthaotacphanso(k, k1);
	return 0;
}
void nhap(string &s) {
	cin >> s;
}
void chuyendoiso(string s, PHANSO &k) {
	stringstream ss(s);
	string tam;
	vector<string>v;
	while (getline(ss, tam, '/')) {
		v.push_back(tam);
	}
	k.tu = stoll(v[0]);
	k.mau = stoll(v[1]);
}
void xuat(PHANSO k) {
	cout << k.tu << "/" << k.mau << endl;
}
void xuatPS(PHANSO k, PHANSO k1) {
	cout << k.tu << "/" << k.mau << " " << k1.tu << "/" << k1.mau << endl;
}
void cacthaotacphanso(PHANSO k, PHANSO k1) {
	tong2PS(k, k1);
	hieu2PS(k, k1);
	tich2PS(k, k1);
	thuong2PS(k, k1);
	rutgonPS(k, k1);
	quydongsaukhirutgon(k, k1);
	sosanh2PS(k, k1);
}
int UCLN(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
void rutgon(PHANSO &k) {
	if (k.mau < 0) {
		k.tu = -k.tu;
		k.mau = -k.mau;
	}
	int x = UCLN(abs(k.tu), k.mau);
	k.tu /= x;
	k.mau /= x;
}
void tong2PS(PHANSO k, PHANSO k1) {
	PHANSO tong;
	tong.tu = k.tu * k1.mau + k1.tu * k.mau;
	tong.mau = k.mau * k1.mau;
	rutgon(tong);
	xuat(tong);
}
void hieu2PS(PHANSO k, PHANSO k1) {
	PHANSO hieu;
	hieu.tu = k.tu * k1.mau - k1.tu * k.mau;
	hieu.mau = k.mau * k1.mau;
	rutgon(hieu);
	xuat(hieu);
}
void tich2PS(PHANSO k, PHANSO k1) {
	PHANSO tich;
	tich.tu = k.tu * k1.tu;
	tich.mau = k.mau * k1.mau;
	rutgon(tich);
	xuat(tich);
}
void thuong2PS(PHANSO k, PHANSO k1) {
	PHANSO thuong;
	thuong.tu = k.tu * k1.mau;
	thuong.mau = k.mau * k1.tu;
	rutgon(thuong);
	xuat(thuong);
}
void rutgonPS(PHANSO& k, PHANSO &k1) {
	rutgon(k);
	rutgon(k1);
	xuatPS(k, k1);
}
int BCNN(long long a, long long b) {
	return (a / UCLN(a, b)) * b;
}
void quydongsaukhirutgon(PHANSO k, PHANSO k1) {
	PHANSO QD1;
	QD1.tu = k.tu * (BCNN(k.mau, k1.mau) / k.mau);
	QD1.mau = BCNN(k.mau, k1.mau);
	PHANSO QD2;
	QD2.tu = k1.tu * (BCNN(k.mau, k1.mau) / k1.mau);
	QD2.mau = QD1.mau;
	xuatPS(QD1, QD2);
}
void sosanh2PS(PHANSO k, PHANSO k1) {
	double x = (1.0) * k.tu / k.mau;
	double y = (1.0) * k1.tu / k1.mau;
	if (x > y) {
		cout << 1;
	}
	else if (x < y) {
		cout << -1;
	}
	else {
		cout << 0;
	}
}
/*
* baitap chuong1 bai6 PHANSO 
* note: full 20/20 testcase uteoj va full 200/200 
*/


