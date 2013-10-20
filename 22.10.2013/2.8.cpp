#include <iostream>
const int SEED1 = 9999;
const int SEED2 = 9999;
using namespace std;
int main(int argc, char *argv[]) {
	int M,N;
	srand(time(NULL));
	M = rand() % SEED1 + 1; // zakres (1..100)
	N = rand() % SEED2 + 2; // zakres (2..SEED2)
	int A[M];
	cout << "M = " << M << " a N = " << N << endl;
	for (int i = 0; i < M; i++) {
		A[i] = rand() % (N-1) + 2; // zakred (2..N)
		cout << A[i] << " ";
	}
	cout << endl;
	int T[N+1]; // index T odpowiada liczbie którą reprezentuje.
	for (int i = 2; i <= N; i++) {
		T[i] = 0;
		for (int j = 0; j < M; j++) {
			if (A[j] > i ) {
				continue;
			} else if (!(i%A[j])) { // ma dzielnik
				T[i] = 1; // wiec ustawiam 1 ( 1 = jest podzielne)
				break;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << i << " - " << T[i];
		if (T[i]) {
			cout << " // jest podzielne";
		} else {
			cout << " // nie jest podzeilne";
		}
		cout << endl;
	}
}