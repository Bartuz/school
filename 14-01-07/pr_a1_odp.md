#1
a)
					P	F
Jan Łukasiewicz			X
###polska notacja
Benoit Mandelbrot		X
###fraktale
Leopold Infeld		X
###jakis fizyk
Paul Baran				X
###zapoczatkowal internet (przez wymyslenie przesylu danych tak, że dzielił je na fragmenty [komutacja pakietów])

b)
P	F
X	
	X
	X
	X
c)
P	F
	X
	X
X
X
d)
P	F
X
	X	
X
	X
e)
do {
	I1();
	while(!w1){
		I2();
	}
} while(!w2)
---
#2
a)
3,4,3
3,5,3
5,6,6,6,2
2,6,2
b)
using namespace std;
int n,i,j,temp;
i = 1;
cin >> n;
int tab[n] = {1,2,2,1};
while(i < n-1){
	if(tab[i-1] < tab[i]){
		if(tab[i+1] < tab[i]){
		cout << tab[i-1] << ", " << tab[i] << ", " << << tab[i+1]  endl;
		} else {
			temp = i;
			while(tab[i+1] == tab[i]){
				temp++;
			}
			if (tab[temp+1] < tab[temp]){
				cout << tab[i-1] << ", ";				for (int j = i; i <= temp; j++){
					cout << tab[j] << ", ";
				}
				cout << tab[temp+1] << endl;
			}
			i = temp;
		}
		i++;
	}
}
c)
(n-1)(n)
o(n^2)
---
3)
a)
Trafia do innej sieci, jeśli ma do niej dostęp (np. przez trasownik).
b)
135	1
67	1
33	1
16	1
8	0
4	0
2	0
1	1
0

100	0
50	0
25	1
12	0
6	0
3	1
1	1
0

10	0
5	1
2	0
1	1
0

224	0
112	0
56	0
28	0
14	0
7	1
3	1
1	1
0



IP: 	10001111	1100100		00001010	00000000	
MASKA:	11111111	1111111		11100000	00000000
XOR: 	01110000	0011011		11101010	00000000
NOT:	10001111	1100100		00010101	11111111

HOST_MIN : 00011111	11111110
			31		254

inny adres rozgloszeniowy ( ten nowy to: 10001111	1100100		00010101	11111111)
zmniejszy sie liczba podsieci.
hostów zostanie tyle samo

135.100.2.11
135.100.3.12
135.100.4.13
135.100.5.14

sa to adresy, który sluza do wysylania pakietow do wszystkich hostów w danych sieciach.
135	1
67	1
33	1
16	1
8	0
4	0
2	0
1	1
0

100	0
50	0
25	1
12	0
6	0
3	1
1	1
0

193	1
96	0
48	0
24	0
12	0
6	0
3	1
1	1
0

1	1
0

IP: 	10001111	1100100		11000001	00000000	
MASKA:	11111111	1111111		11100000	00000000
XOR: 	01110000	0011011		00100001	00000000
NOT:	10001111	1100100		11011110	11111111
								

Adres to: 135.100.222.255

