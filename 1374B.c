/*You are given an integer n. In one move, you can either multiply n by two or divide n by 6 (if it is divisible by 6 without the remainder).

Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1≤n≤109).

Output
For each test case, print the answer — the minimum number of moves needed to obtain 1 from n if it's possible to do that or -1 if it's impossible to obtain 1 from n.*/

#include <iostream>
using namespace std;

int pow_of_2_3(int n, int m){
    int p = 0;
    while(n%m == 0){
        p++;
        n = n / m;
    }
    return p;
}
int check_other_factor(int n){
    
    while(n%2 == 0){
        n = n/2;
    }
    
    while(n%3 == 0){
        n = n/3;
    }
    
    if(n != 1) return 1;
    return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
	    int n;
	    scanf("%d", &n);
	    
	    if(n == 1){
	        printf("0\n");
	        continue;
	    }
	    
	    if(n%3 != 0){
	        printf("-1\n");
	        continue;
	    }
	    
	    if(check_other_factor(n)){
	        printf("-1\n");
	        continue;
	    }
	    
	    int p2 = pow_of_2_3(n, 2);
	    int p3 = pow_of_2_3(n, 3);
	    
	    if(p2 > p3){
	        printf("-1\n");
	        continue;
	    }
	    
	    printf("%d\n", 2*p3 - p2);
	    
	}
	return 0;
}
