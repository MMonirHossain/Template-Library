#include<bits/stdc++.h>

using namespace std;

//#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e18
#define mod 1000000007
#define limit 1000003
#define ceil(a,b) (ll)((a+b-1)/b)

ll C[65][65];
ll m=998244353;
void combination(){
    for(int i=0;i<63;i++){C[i][0]=1;C[i][i]=1; }

    for(int i=1;i<62;i++){
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
        }
    }
}



void solve(){


}//end of8 solve()



int main(){
Fast;
combination();
int t=1;
cin>>t;
for(int i=1;i<=t;i++){
    solve();
}

return 0;
}



