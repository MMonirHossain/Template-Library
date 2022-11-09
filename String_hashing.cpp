#include<bits/stdc++.h>

using namespace std;


#define ll long long int
#define mod 1000000007
#define limit 100005

//bigMod function
ll bigMod(ll a,ll b){
    if(b==0){return 1;}
    ll x=bigMod(a,b/2);
    x=(x*x)%mod;
    if(b&1){x=(a*x)%mod;}
    return x;
}


//only polynomial hashing function
ll getHash(string s){
    ll ans=0;
    ll p=31;
    ll p_power=1;
    int lim=s.size();

    for(int i=0;i<lim;i++){
        ans=( ans + (s[i]-96)*p_power ) %mod;
        p_power=(p*p_power)%mod;
    }

    return ans;
}

//calculation of prefix/cululative hash


ll dp[limit];///before submitting the code the size of this array must be changed,otherwise it will produce an runtime error
ll invp[limit];
void calculatePrefixHash(string str){

    ll p=31;
    ll p_val=1;
    int lim=str.size();
    dp[0]=(str[0]-96);
    invp[0]=1;
    invp[1]=bigMod(p,mod-2);

    for(int i=2;i<lim;i++){
        invp[i]=(invp[i-1]*invp[1]) %mod;
    }

    for(int i=0;i<10;i++){cout<<invp[i]<<" ";}cout<<"\n";



    for(int i=1;i<lim;i++){
            p_val=(p*p_val)%mod;
           dp[i]=( dp[i-1] + (str[i]-96)*p_val ) %mod;
    }

    for(int i=0;i<lim;i++){
          cout<< dp[i]<<" ";
    }cout<<"\n";

}

ll substrHash(int i,int j){
    if(i==0){return dp[j];}

    ll x=dp[j]-dp[i-1];

    if(x<0){x=x+mod;}

    return (x*invp[i] )%mod;
}





int main(){

string s;
int t,q,i,j;
cin>>t;

while(t--){
    cin>>s>>q;
    calculatePrefixHash(s);

    while(q--){
        cin>>i>>j;
        cout<<substrHash(i,j)<<"\n";
    }

}


return 0;
}
