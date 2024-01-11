/*logic of this question:- 
 first:- calculate all unique prime divisors of numbers
 second:- for all unique prime divisors count how many number have this as a prime divisors
 note point:- now it is possible that if two number or more number have (same prime divisors more than one) then
 we will be counting the numbers multiple times that we don't need;
 example:-
 20 :- 2,5
 30 :- 2,5,3
 divisor     count
 2             2 (20,30)
 5             2(20,30)
 3             1(30)

 so will count the number who have same divisors that are non prime
 divisors        count
 10              2( 20,30)
 so while making pairs who have gcd more than 1 we will have to use inclusion exclusion principle
 so total no of paie will be
 t=(2*(2-1)/2)+(2*(2-1)/2)+(1*(1-1)/2)-(2*(2-1)/2);
 t=1;
 so total no of pair whill be one that have the gcd more than one; 
 
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int mx=1e6+7;
void solve() {
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
} 

vector<vector<int>>sieve(mx);//to sieve[x] will store unique prime divisor of x;
for(int i=2;i<mx;i++){
   if(sieve[i].size()==0){
    sieve[i].push_back(i);
    for(int j=2*i;j<mx;j+=i){
        sieve[j].push_back(i);
    }
   }
}
  vector<int>nodivisibleby(mx);
  vector<int>noofprime(mx);
  for(int i=0;i<n;i++){
    int size=sieve[arr[i]].size();
    for(int mask=1;mask<(1<<size);mask++){
        int count=0;
        int combination=1;
         for(int j=0;j<size;j++){
            if((1<<j)&mask){
                combination*=sieve[arr[i]][j];
               count++;
            }
         }
         nodivisibleby[combination]++;
         noofprime[combination]=count;   
    }
  }
  int ans=(n*(n-1))/2;
  int temp=0;
  for(int i=1;i<20;i++){
    int t=nodivisibleby[i];
    cout<<i<<" "<<t<<" "<<noofprime[i]<<"|";
    if(noofprime[i]&1)temp+=(t*(t-1)/2);
    else{
        temp-=(t*(t-1)/2);
    }
  }
  //cout<<temp<<" ";
  cout<<ans-temp;
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
