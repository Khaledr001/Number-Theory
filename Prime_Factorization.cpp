#include<bits/stdc++.h>
#define lli long long int
using namespace std;
#define max 100000
bool mark[max+9];
vector <lli> prime;

void seive()
{
    lli i,j;
    mark[1] = 1;
    for(i = 4; i <= max; i+=2) mark[i] = 1;
    prime.push_back(2);
    for ( i = 3; i <= max; i += 2)
    {
        if(!mark[i]) {
            prime.push_back(i);
            if(i*i <= max) {
                for ( j = i*i; j <= max; j += (i*2))
                    mark[j] = 1;
            }
        }
    }
    return;
}

vector<lli> factor,power;

void factorization(int n)
{
    lli i,j,cnt,len = prime.size();
    for ( i = 0; i*i < n && i < len; i++)
    {
        cnt = 0;
        if(n % prime[i] == 0) {
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                cnt ++;
            }
            factor.push_back(prime[i]);
            power.push_back(cnt);
            cout << prime[i] << ' ' << cnt << endl;
        }
    }
    if(n > 1) {
        factor.push_back(n);
        power.push_back(1);
    }
    return;
}

int main()
{
    seive();
    int i,j,n;
    cin >> n;
    factorization(n);
    return 0;
}