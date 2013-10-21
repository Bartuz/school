#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool isPierwsza(int);
int main(int argc, char *argv[]) {
	ifstream plik("liczby2.10.txt");
	ofstream fout("2.10.txt");
	int temp;
	while (plik >> temp) {
		if ( temp > 2 && ( (int)sqrt(temp) == sqrt(temp) ) && ( isPierwsza(sqrt(temp) )) ) {
			fout << temp << endl;
		}
	}
}
bool isPierwsza(int liczba){
	for (int i = 2; i <= liczba/2; i++) {
		if ( !(liczba%i)) {
			return false;
		}
	}
	return true;
}