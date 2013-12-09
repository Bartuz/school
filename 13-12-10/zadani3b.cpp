#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
bool isRosnaca(string);
int main(int argc, char *argv[]) {
	ofstream fout("zadanie3b.txt");
	int temp, counter;
	string text;
	ifstream fin("dane1.txt");
	fout << "1: ";
	while (fin >> temp){
		stringstream buffer;
		buffer << temp;
		text = buffer.str();
		if (isRosnaca(text)) {
			counter++;
		}
	}
	fin.close();
	fout << counter;
	fin.open("dane2.txt");
	fout << endl << "2: "; 
	while (fin >> temp){
		stringstream buffer;
		buffer << temp;
		text = buffer.str();
		if (isRosnaca(text)) {
			counter++;
		}
	}
	fout << counter;
	fin.close();
	fin.open("dane3.txt");
		fout << endl << "3: ";
		while (fin >> temp){
			stringstream buffer;
			buffer << temp;
			text = buffer.str();
			if (isRosnaca(text)) {
				counter++;
			}
		}
		fout << counter;
}
bool isRosnaca(string s){
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i]>=s[i+1]) {
			return false;
		}
	}
	return true;
}