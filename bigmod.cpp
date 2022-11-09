#include<bits/stdc++.h>
using namespace std;

#define ll long long int


#define mod 1000000007
ll bigMod(ll a,ll b){
    if(b==0){return 1;}
    ll x=bigMod(a,b/2);
    x=(x*x)%mod;
    if(b&1){x=(a*x)%mod;}
    return x;
}


//complexity square root of m
ll phi(ll m){

    ll ans=m;

    for(ll i=2;i<=sqrt(m)+1;i++){
        if(m%i==0){
            ans=ans-(ans/i);
            while(m%i==0){m=m/i;}
        }
    }


   if(m>1){ans=ans-(ans/m);}

    return ans;
}



void solve(){
    ll a;
    cin>>a;

    cout<<phi(a)<<"\n";
}

int main(){


int n;
cin>>n;

while(n--){solve();}


return 0;
}
