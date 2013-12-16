#include <iostream>
#include <cmath>
using namespace std;
double f(double);
int main(int argc, char *argv[]) {
	double h,p,k,eps,pole;
	p = 2, k = 8, eps = 100;
	h = k/eps - p/eps;
	pole = 0;
	int x;
	cin >> x;
	for (int i=0; i<eps; i++) {
		pole+= (abs(f(x+i*h))+abs(f(x+(i+1)*h)))*h/2;
	}
	cout << pole;
}
double f(double x){
	return x*x + 2*x - 8;
}