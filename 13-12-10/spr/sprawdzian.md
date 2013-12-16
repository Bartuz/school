#1
##a
double WielCzebRek(int n, int x){
	if (n == 0) return 1;
	if (n == 1) return x;
	return 2*x*WielCzebRek(n-1,x)-WielCzebRek(n-2,x);
}
##b

double WielCzebIter(int n, int x){
	double temp[2];
	temp[0] = 1;
	temp[1] = x; 
	for (int i = 2; i<=n; i++){
		temp[0] = 2*x*temp[1] - temp[0];
		swap(temp[0],temp[1]);
	}
	return temp[1];
}