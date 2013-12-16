#include <iostream>
#include <cmath>
using namespace std;
double f(double);
int main(int argc, char *argv[]) {
	double p,k,eps,srodek;
	eps = 0.1;
	p= -10;
	k = 10;
	if ( (f(p) * f(k) ) > 0) {
		cout << "brak m0";
		return 0;
	}
	srodek = p/2 + k/2;
	while (abs(f(srodek))>eps){
//		cout << "p = " << p << " k = " << k << "f(p) = " << f(p) <<  endl;
		srodek = p/2 + k/2;
		if ( (f(p)*f(srodek)) > 0) {
			p = srodek;
		} else {
			k = srodek;
		}
	}
	cout << "mz dla x~~ " <<srodek;
}
double f(double x){
	return x*x*x + 0.4*x*x - 4.47*x + 5.58;
}