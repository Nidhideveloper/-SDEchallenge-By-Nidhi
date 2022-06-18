double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double error = 1e-7;
    double diff=1e18;
    double guess = 2;
    while(diff>error){
        double g1 = (pow(guess, n)*(n-1)+m)/(n*pow(guess, n-1));
        diff = abs(guess - g1);
        guess = g1;
    }
    return guess;
}