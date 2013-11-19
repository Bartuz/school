#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int max, i, tab[10000], temp, sumaCiagu, sumaMniejszegoCiagu;
	ifstream file;
	string nazwaPliku;
	ofstream fout("zadanie5b.txt");
//	cout << "przed petla" <<endl;
	for (int j = 1; j < 4; j++) {
		nazwaPliku="";
		nazwaPliku += "dane5-" + to_string(j) + ".txt";
		file.open(nazwaPliku);
		i = 0;
		while (file >> tab[i]) {
			if (i == 0) {
				max = tab[0];
			}
			if (max < tab[i]) max = tab[i];
//			cout << tab[i] << " ";
			i++;
		}
		sumaCiagu = 0;
		for (int j = 0; j < i; j++) {
			sumaCiagu += tab[j];
		}
		fout << endl << "sumaCiagu = " << sumaCiagu <<endl;
		if (sumaCiagu > max) {
			max = sumaCiagu;
		}
		sumaMniejszegoCiagu = sumaCiagu;
		for (int m = -1; m < i; m++) {
//			cout <<  m  << " - ";
			if (m >= 0) {
				sumaMniejszegoCiagu -= tab[m];
			} 
			temp = sumaMniejszegoCiagu;
//							cout << "dla "<< sumaMniejszegoCiagu+tab[m]  << "-" << tab[m] << "=" << temp <<  endl;
			if (temp > max) { 
				max = temp;
			}	
			for (int n = i-1; n > m; n-- ) {
//				cout << n << endl;;
				temp -= tab[n];
//				cout << "\t" << temp+tab[n] << "-" << tab[n] << "=" << temp << endl;
				if (temp > max) {
					max = temp;
				}	
			}
		}
		fout << "dla " << nazwaPliku << " maksymalna suma to "  << max << endl;
		file.close();	
	}
}