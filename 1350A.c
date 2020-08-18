/*Orac is studying number theory, and he is interested in the properties of divisors.

For two positive integers a and b, a is a divisor of b if and only if there exists an integer c, such that a⋅c=b.

For n≥2, we will denote as f(n) the smallest positive divisor of n, except 1.

For example, f(7)=7,f(10)=2,f(35)=5.

For the fixed integer n, Orac decided to add f(n) to n.

For example, if he had an integer n=5, the new value of n will be equal to 10. And if he had an integer n=6, n will be changed to 8.

Orac loved it so much, so he decided to repeat this operation several times.

Now, for two positive integers n and k, Orac asked you to add f(n) to n exactly k times (note that n will change after each operation, so f(n) may change too) and tell him the final value of n.

For example, if Orac gives you n=5 and k=2, at first you should add f(5)=5 to n=5, so your new value of n will be equal to n=10, after that, you should add f(10)=2 to 10, so your new (and the final!) value of n will be equal to 12.

Orac may ask you these queries many times.

Input
The first line of the input is a single integer t (1≤t≤100): the number of times that Orac will ask you.

Each of the next t lines contains two positive integers n,k (2≤n≤106,1≤k≤109), corresponding to a query by Orac.

It is guaranteed that the total sum of n is at most 106.

Output
Print t lines, the i-th of them should contain the final value of n in the i-th query by Orac.*/


#include <stdio.h> 
#include <string.h> 

int n = 1e6;
int prime[1000001]; 

int f(int N){
    if(N%2 == 0) return 2;
    
    for(int p=3; p<=N; p+=2){
        if(prime[p]){
            if(N%p == 0) return p;
        }
    }
    
    return -999999;
}

int main(void) {
    
	//***************************************//
    memset(prime, 1, sizeof(prime));
    
    for (int p=2; p*p<=n; p++){ 
        if (prime[p] == 1){
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 0; 
        } 
    }
	//***************************************//
	
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
	    
	    int s,k;
	    scanf("%d %d", &s, &k);
	    for(int i=0; i<k; i++){
	        if(s%2 == 0){
	            s = s + 2 * (k - i);
	            break;
	        }   
	        s = f(s) + s;
	    }
	     printf("%d\n", s);
	}
	return 0;
}

