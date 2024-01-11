/*The problem you've described is a classic example of a combinatorial problem known as "stars and bars" or "balls and bins."
The goal is to find the number of non-negative integer solutions to the equation x1 + x2 + ... + xn = m, where x1, x2, ..., xn are non-negative integers.

Imagine you have m identical items (stars, balls, etc.) and n-1 dividers (bars).
You want to distribute the m items among n bins (variables x1, x2, ..., xn).

For instance, if n = 3 and m = 5, a possible distribution could be 2 + 1 + 2.
Represent this distribution with stars and bars: **|*|**.

The number of ways to arrange m stars and n-1 bars is the same as the number of solutions to the equation x1 + x2 + ... + xn = m.
The formula for finding the number of arrangements is:

C(m + n - 1, n - 1) = (m + n - 1)! / ((n - 1)! * m!)

Here, C(m + n - 1, n - 1) is a binomial coefficient, representing the number of ways to choose n-1 positions (or dividers) out of m + n - 1 total positions (stars and dividers combined).

So, in your case, the number of solutions to x1 + x2 + ... + xn = m is C(m + n - 1, n - 1).*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
vector<int>fact;
int modularExponential(int base,int exponent){
    if(exponent==0)return 1;
    int temp=modularExponential(base,exponent/2);
    if(exponent&1){
        return ((((temp%mod)*(temp%mod))%mod)*(base%mod))%mod;
    }
    else{
        return ((temp%mod)*(temp%mod))%mod;
    }
    return -1;
}
void solve() {
 int n,m;
 cin>>n>>m;
  int ans=((fact[n+m-1]*modularExponential(fact[n-1],mod-2)))%mod;
  ans=(ans*(modularExponential(fact[m],mod-2)))%mod;
  cout<<ans;
}

int32_t main() {
    fact.resize(1e7);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=1e7;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
   solve();
    cout<<endl;
    
   
    return 0;
}
