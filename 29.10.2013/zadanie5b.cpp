#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int temp,max,i,k;
	ifstream file;
	string nazwaPliku;
	for (int j = 1; j < 4; j++) { //petla ktora słuzy do ładowanie kolejnych plików.
		nazwaPliku=""; // nazwa pliku zmienia się co nowy krok w pętli
		nazwaPliku += "dane5-" + to_string(j) + ".txt"; // ustawiam zmienną nazwePliku na nową wartość
		file.open(nazwaPliku); // otwieram nowy plik
		file >> temp;
		k = 1;
		
		file.close(); // i ów plik zamykam
	}
}