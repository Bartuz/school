#include <iostream>

using namespace std;
bool isPrime(int);
int main(int argc, char *argv[]) {
	int L = 13;
	if ( isPrime(L) )
		cout << "Tak";
	else 
		cout << "Nie";
}
bool isPrime(int liczba){
	for (int i = 2; i <= liczba/2; i++) {
		if ( !(liczba%i) ) {
			return false;
		}
	}
	return true;
}