#include <bits/stdc++.h>
#define lli long long int
#define MAX 10000000
using namespace std;

vector <int> prime;
bool mark[MAX+10];

void sieve()
{
    lli i,j;
    mark[1] = 1;
    prime.push_back(2);
    
    // Here 2 is the only even prime number. This loop is for even number.
    for(i = 4; i <= max; i+=2) mark[i] = 1;
    
    //This loop is for odd number.
    for ( i = 3; i <= max; i += 2)
    {
        if(!mark[i]) {
          // Here i is prime number.
            prime.push_back(i);
            if(i*i <= max) { // this condition means i <= sqrt(MAX).sqrt() function take more time.
                for ( j = i*i; j <= max; j += (i*2)) {
                    /* j contain only odd number. odd * odd = odd (i*i) .
                    even + odd = odd ((i*2) is even) (j is odd) */
                    mark[j] = 1;
                }
            }
        }
    }
    return;
}

int main()
{
    sieve();
    lli n,i;
    cin >> n;
    for(i = 0;prime[i] <= n && i < prime.size(); i++)
        cout << prime[i] << ' ';
    return 0;
}
