#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int temp[2],max,i;
	ifstream file;
	string nazwaPliku;
	for (int j = 1; j < 4; j++) { //petla ktora słuzy do ładowanie kolejnych plików.
		nazwaPliku=""; // nazwa pliku zmienia się co nowy krok w pętli
		nazwaPliku += "dane5-" + to_string(j) + ".txt"; // ustawiam zmienną nazwePliku na nową wartość
		file.open(nazwaPliku); // otwieram nowy plik
		file >> temp[0];
		i = 1; // ustawiam pomocniczą zmienna na 1, która będzie wskazywać odpowiedni indeks w tablicy, do której będe zapisywać kolejno odczytane liczby
		max = temp[0]; // zapisuje maxyymalna sume jako pierwsza wczytaną liczbę
		while ( (file >> temp[i]) ) {  // wczytuje kolejna liczbe do tablicy o indeksie i
			if ( temp[0] + temp[1] > max) { // jesli suma nowopobranej w liczby z poprzednio pobranej liczby jest wieksza od max'a
				max = temp[0] + temp[1];  // to max ustawiam na sume 2 ostatnio pobranych liczb
			}
			if (i == 0) { // warunek do rotacji zmienna pomocnicza
				i++;
			} else {
				i--;
			}
		}
		if (temp[!i] > max) { // jeśli max jest mniejszy od ostatnio wczytanej liczby
			max = temp[!i];
		}
		cout << "dla " << nazwaPliku << " maksymalna suma to "  << max << endl; //wypisuje wynik dla danego pliku
		file.close(); // i ów plik zamykam
	}
}