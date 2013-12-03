#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double);
double g(double);
int main(int argc, char *argv[]) {
	double poczatek,koniec,epsilon,h,a,x,pole;
	poczatek = pole = 0, koniec = 10;
	epsilon = (koniec - poczatek)/0.01;
	h = koniec/epsilon - poczatek/epsilon;
	for (int i = 0; i < epsilon; i ++) {
		pole+= (abs(f(poczatek+i*h))+abs(f(poczatek+(i+1)*h)))*h/2;
		pole+= (abs(g(poczatek+i*h))+abs(g(poczatek+(i+1)*h)))*h/2;
	}
	ofstream fout("wyniki.txt");
	fout.precision(4);
	fout << pole << endl;
	fout << "Sposob trapezowy. Obliczam pole kolejnych trapezow." << endl;
	a = 0;
	x = 0;
	while (a < 26 || !( (int(g(x)) == g(x)) || ( int(f(x)) == f(x)) ) ) {
		x++;
		a = g(x) - f(x);
	}
	fout << "C = " << x+100 << endl << "wierchołki to kolejno: " << x << "," << f(x) << "; " << x << "," << g(x) << "; " << x+100 << "," << f(x) << "; " << x+100 << "," << g(x); 
	fout.close();
}
double f(double x){
	return -(x*x)/50;
}
double g(double x){
	return 1+x*x/100 - x/200;
}