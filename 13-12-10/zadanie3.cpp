#include <iostream>
#include <fstream>
using namespace std;
int nwd(int, int);
int main(int argc, char *argv[]) {
	ifstream fin("dane1.txt");
	ofstream fout("zadanie3.txt");
	int file_number, temp;
	fin >> file_number;
	fin >> temp;
	temp = nwd(temp,file_number);
	while (fin >> file_number) {
		temp = nwd(temp,file_number);
	}
	fout << "Plik 1: " << temp;
	fin.close();
	fin.open("dane2.txt");
	fin >> file_number;
	fin >> temp;
	while (fin >> file_number) {
		temp = nwd(temp,file_number);
	}
	fout << "Plik 2: " << temp;
	fin.close();
	fin.open("dane3.txt");
	fin >> file_number;
	fin >> temp;
	while (fin >> file_number) {
		temp = nwd(temp,file_number);
	}
	fout << "Plik 3: " << temp;
	fin.close();
}
int nwd(int a,int b){
	while (a!=b) {
		if (a>b) {
			a-=b;
		} else {
			b-=a;
		}
	}
	return a;
}