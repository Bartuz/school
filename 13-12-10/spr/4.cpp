#include <iostream>
#include <cmath>
double pierwiastek(double,int);
using namespace std;
int main(int argc, char *argv[]) {
	int a = 49, n = 2;
	double wynik = 1+(a-1)/n;
	for (int i = 1; i <= n; i++) {
		wynik = 1/n*((n-1)*wynik+a/pow(wynik,n-1));
	}
	cout << wynik;
//	cout << pierwiastek(liczba,stopien);
}
double pierwiastek(double a,int n){
	if (n == 1) {
		return 1 + (a - 1)/n;
	}
	return 1/n*( (n - 1)*pierwiastek(a,n-1)+a/pow(pierwiastek(a,n-1),n-1));
}