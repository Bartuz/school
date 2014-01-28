#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	fstream fin1("../tj.txt");
	fstream fin2("../klucze1.txt");
	ofstream fout("1a.txt");
	string klucz,txt,temp;
	int j,letter;
	while (fin1 >> txt && fin2 >> klucz) {
//		cout << txt << " z kluczem " << klucz << endl;
		j = 0;
		temp = "";
		for (int i = 0; i < txt.length(); i++) {
			letter = (int)txt[i] + (int)klucz[j] - 64;
			if (letter > 90 ) letter-=26;
			cout << letter << endl;
			temp+= (char)letter;
//			cout << (int)'A';
			j++;
			if (j == klucz.length()) j = 0;
		}
		fout << temp << endl;
	}
}