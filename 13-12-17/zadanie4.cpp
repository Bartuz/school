#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
//bool isAnagram(string);
int main(int argc, char *argv[]) {
	ofstream fout("odp_4a.txt");
	ofstream wout("odp_4b.txt");
	ifstream fin("anagram.txt");
	string temp,pattern,tab[5];
	int isAnagram = 0, counter = 0, isSameLength;
	for (int k = 0; k<200;k++) {
		for (int i = 0; i<5;i++) {
			fin >> tab[i];
//			cout << tab[i] << " ";
			if (!counter){ 
				counter= tab[i].length();
				pattern = tab[i];
				isAnagram = 1;
				isSameLength = 1;
				sort(pattern.begin(),pattern.end());
				continue;
			}
			
			if (counter!=tab[i].length()) {
				isSameLength = 0;
			}
			temp = tab[i];
			sort(temp.begin(),temp.end());
			if (isAnagram && temp  != pattern) {
				isAnagram = 0;
			}
			if (i == 4 && isSameLength){
				for (int j = 0; j < 5; j++) {
					fout << tab[j] << " ";
					if (isAnagram) wout << tab[j] << " ";
				}
				fout << endl;
				if (isAnagram) wout << endl;
			}
		}
		counter = 0;
	}
	cout << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " " << tab[4]  ;
}