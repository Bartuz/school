#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int isFib(int);
int main(int argc, char *argv[]) {
	ifstream fin("dane.txt");
	ofstream fout("zadanie5.txt");
	int temp,min,max,first;
	first = 1;
	vector <int> ciag;
	vector <int> najdluzszy;
	while (fin >> temp) {
		if (isFib(temp)){ 
			if (first) {
				ciag.push_back(temp);
				max = temp;
				min = temp;
				first = 0;
			}
			if (temp > ciag.back()) {
				ciag.push_back(temp);
			} else {
				if (najdluzszy.size() < ciag.size()) {
					najdluzszy = ciag;
				}
				ciag.clear();
			}
			fout << temp << endl;
			if (temp > max) max = temp;
			if (temp < min) min = temp;
		}
	}
	cout << najdluzszy.size();
	fout << "MIN = " << min << "\nMAX = " << max << endl;
	fout << "CIAG (dlugosc "<<  najdluzszy.size() << "): ";
	copy(najdluzszy.begin(),najdluzszy.end(),ostream_iterator<int>(fout, " "));
	return 0;
}
int isFib(int liczba){
	if (liczba == 1 || liczba == 0) {
		return 1;
	}
	int temp[2], summ;
	temp[0] = 0;
	temp[1] = 1;
	do {
		summ = temp[0] + temp[1];
		if (liczba == summ) return 1;
		temp[0] = summ;
		swap(temp[0],temp[1]);
	} while (summ <= liczba);
	return 0;	
}