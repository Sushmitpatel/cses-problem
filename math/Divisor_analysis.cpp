#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
unordered_map<int,int>mp;
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
int gpsum(int r,int a,int n){
    int temp =modularExponential(r,n);
    int denomi=modularExponential((r-1),mod-2);
    return ((((a%mod)*((temp-1+mod)%mod))%mod)*denomi)%mod;
}
void solve() {
int n;
cin>>n;
int no=1,sum=1,product=1;
while(n--){
    int x,y;
    cin>>x>>y;
    mp[x]=y;
    no=(no*(y+1))%mod;
}
cout<<no<<" ";
for(auto it:mp){
    int temp=gpsum(it.first,1,it.second+1);
    sum=(sum*temp)%mod;
}
cout<<sum<<" ";
bool oddexponent=false;
int oddexponentvalue=-1;
for(auto it:mp){
    if(it.second&1){
        oddexponent=true;
        oddexponentvalue=it.first;
        // cout<<oddexponentvalue<<" ";
        break;
    }
    
}
if(oddexponent){
    
    int outexponent=1;
    for(auto it:mp){
        if(it.first==oddexponentvalue){
            outexponent=(outexponent*(it.second+1)/2)%(mod-1);
        }
        else{
            outexponent=(outexponent*(it.second+1))%(mod-1);
        }
    }
    // cout<<outexponent<<" ";
    for(auto it:mp){
        product=(product*modularExponential(it.first,(outexponent*(it.second))%(mod-1)))%mod;
    }

}
else{
    
    int outexponent=1;
    for(auto it:mp){
        outexponent=(outexponent*(it.second+1))%(mod-1);
    }
    for(auto it:mp){
        product=(product*modularExponential(it.first,(outexponent*((it.second)/2))%(mod-1)))%mod;
    }
}
cout<<product;
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
