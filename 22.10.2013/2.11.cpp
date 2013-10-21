#include <iostream>
using namespace std;
int najmniejszyDzielnik(int &, int &);
int main(int argc, char *argv[]) {
	int temp,n;
	temp = n = 19;
	int iloczynCzynnikow=1;
	int dzielniki[n];
	int i = 0;
	do {
		dzielniki[i] = 0;
		iloczynCzynnikow*=najmniejszyDzielnik(temp, dzielniki[i]);
		i++;
	} while (iloczynCzynnikow != n);
	for (int j = 0; j < i; j++ ) {
		cout << dzielniki[j];
		if ( (i-1)==j) {
			cout << ".";
		} else {
			cout << ", ";
		}
	
	}
}
int najmniejszyDzielnik(int &liczba, int &dzielnik){
	for (int i = 2; i <= liczba; i++) {
		if ( !(liczba%i) ) {
			dzielnik=i;
			liczba/=i;
			return i;
		}
	}
}