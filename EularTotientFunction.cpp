#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll phi(ll n)
{
    ll res = n;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            res /= i;
            res *= (i-1);

            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res /= n;
        res *= (n-1);
    }
    
    return res;
}

int main()
{
    ll i,t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        printf("PHI of %lld is %lld.\n",n,phi(n));
    }
    return 0;
}