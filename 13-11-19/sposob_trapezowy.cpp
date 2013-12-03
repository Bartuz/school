#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int LIMIT = 9999;

double f(double);
void sort(double [][2]);

int main(int argc, char *argv[]) {
	double h,a,b,n, pole, wyniki[LIMIT][2];
	a = 3;
	b = 5;
	srand(time(NULL));
	int i = 0;
	do {
		n = rand() % 9999 + 1;
		h = b/n-a/n;
		for (int i = 0; i < n; i++) {
				pole +=  h/2 * ( abs(f(a + i * h)) + abs(f(a + (i+1) * h)) );
			}
		wyniki[i][0] = n;
		wyniki[i][1] = pole;
		pole = 0;
		i++;
	} while ( i <= LIMIT );
	sort(wyniki);
	for (int i = 0 ; i < LIMIT; i ++) {
		if (wyniki[i-1][0] == wyniki[i][0]) continue; 
		cout << "Dla n = " << wyniki[i][0] << " pole = " << wyniki[i][1] << endl;
	}
}
void sort(double t[][2]){
	for (int i = 0; i < LIMIT; i++) {
		for (int j = 1;  j  < LIMIT-i; j++) {
			if (t[j-1][0] > t[j][0]) {
				swap(t[j-1],t[j]);
			}
		}
	}
}
double f(double x){
	return  1*sqrt(74) * x*x - 99 * x + 3;
}