/*You are given an integer n (n≥0) represented with k digits in base (radix) b. So,

n=a1⋅bk−1+a2⋅bk−2+…ak−1⋅b+ak.
For example, if b=17,k=3 and a=[11,15,7] then n=11⋅172+15⋅17+7=3179+255+7=3441.

Determine whether n is even or odd.

Input
The first line contains two integers b and k (2≤b≤100, 1≤k≤105) — the base of the number and the number of digits.

The second line contains k integers a1,a2,…,ak (0≤ai<b) — the digits of n.

The representation of n contains no unnecessary leading zero. That is, a1 can be equal to 0 only if k=1.

Output
Print "even" if n is even, otherwise print "odd".

You can print each letter in any case (upper or lower).*/

#include <stdio.h>

int main(){
    int b,k;
    scanf("%d %d", &b, &k);
    int a[k];
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    
    if(b%2 == 0){
        if(a[k-1]%2 == 0) printf("even");
        else printf("odd");
    }
    else{
        int odd_count=0;
        for(int i=0; i<k; i++){
            if(a[i]%2 != 0)
                odd_count++;
        }
        if(odd_count%2 ==0) printf("even");
        else printf("odd");
    }
    return 0;
}
