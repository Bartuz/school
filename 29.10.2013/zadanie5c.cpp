#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int i, tab[10000];
	ifstream file;
	string nazwaPliku;
	ofstream fout("zadanie5c.txt");
//	cout << "przed petla" <<endl;
	for (int j = 1; j < 4; j++) {
		nazwaPliku="";
		nazwaPliku += "dane5-" + to_string(j) + ".txt";
		file.open(nazwaPliku);
		i = 0;
		while (file >> tab[i]) {
//			cout << tab[i] << " ";
			i++;
		}
//		cout << endl;
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i-j-1; k++){
				if (tab[k] > tab[k+1]){
					swap(tab[k], tab[k+1]);
				}
			}
		}
		for (int j = 0; j < i; j++){
//			cout << tab[j] << " ";
		}
//		cout << endl;
		int popularne[i],pomocnicza,max, licznik;
		max = pomocnicza = 0;
		licznik =1;
		for (int j = 0; j < i; j++) {
			if (tab[j+1] == tab[j]){
				licznik+=1;
				continue;
			} else if (licznik > max) {
				pomocnicza = 0;
				popularne[pomocnicza] = tab[j];
				max = licznik;
			} else if (licznik == max) {
				pomocnicza +=1;
				popularne[pomocnicza] = tab[j];
			}
			licznik = 1;
		}
		fout << "dla " << nazwaPliku << " najpopularniejsze to :";
		for (int j = 0; j <= pomocnicza; j++) {
			fout << popularne[j] << " ";
		}
		fout << endl;
		file.close();	
	}
}