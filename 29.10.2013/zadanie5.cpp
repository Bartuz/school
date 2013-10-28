#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int tab[2],temp,i;
	ifstream file;
	string nazwaPliku;
	for (int j = 1; j < 4; j++) {
		nazwaPliku="";
		nazwaPliku += "dane5-" + to_string(j) + ".txt";
		file.open(nazwaPliku);
		for (int i = 0; i < 2; i++){
			file >> tab[i];
		}
		i = 0;
		temp = tab[0] + tab[1];
		while ( (file >> tab[i]) ) {
			if ( tab[0] + tab[1] > temp) {
				temp = tab[0] + tab[1];
			}
			if (i == 0) {
				i++;
			} else {
				i--;
			}
		}
		cout << "dla " << nazwaPliku << " maksymalna suma to "  << temp << endl;
		file.close();
	}
}