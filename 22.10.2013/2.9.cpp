#include <iostream>
#include <fstream>
using namespace std;
ofstream plik("2.9.a.txt");
bool isPolpierwsza(int, bool = false);
bool isPierwsza(int);
int main(int argc, char *argv[]) {
	ifstream inputFile("liczby2.9.txt");
	int tab[500]; // tutaj trzymam wszystkie liczby z danych.
	int temp,i;
	temp = i = 0;
	while (inputFile >> tab[i] ) {
		i++;
	}
//	cout << tab[499];
	ofstream outputFile("liczby.txt");
	for (int i = 0; i <= 500; i++) {
		if (isPolpierwsza(tab[i])) {
			outputFile << tab[i] << endl;;
		}
	}
	outputFile.close();
    // poniżej jest rozwaizanie zadania 2.9 a)
	int tablica_do_zadania_a[4]= { 65, 851, 1002, 44521 };
	for (int i = 0; i < 4;i++) isPolpierwsza(tablica_do_zadania_a[i], true);
}
bool isPolpierwsza(int liczba, bool wypisz){
	int j = 0;
	int tab[2];
	for (int i = 2; i <= (liczba/2); i++) {
		if ( !( liczba%i ) &&  isPierwsza(i) ){
			tab[j] = i;
			j++;
			if (j==2) {
				break;
			}
		}
	
	}
	if (j==1) {
		tab[1] = tab[0];
	}
	if (tab[0] * tab[1] == liczba) {
		if (wypisz) plik << tab[0] << " * " <<  tab[1] << endl;
		return true;
	} else {
		if (wypisz) plik << "NIE" << endl;
		return false;
	}
}
bool isPierwsza(int liczba){
	for (int i = 2; i <= liczba/2; i++) {
		if ( !(liczba%i) ) {
			return false;
		}
	}
	return true;
}