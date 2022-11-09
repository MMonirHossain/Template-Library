#include<bits/stdc++.h>

using namespace std;

//#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll unsigned long long
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e18
#define mod 1000000007
#define limit 100005
#define ceil(a,b) (ll)((a+b-1)/b)

vector<int > prime;
int total_prime;

bool visit[limit];

void seive(){
    prime.push_back(2);
    visit[1]=1;
    for(int i=4;i<limit;i=i+2){visit[i]=1;}
    int mx=sqrt(limit);

    for(int i=3;i<limit;i=i+2){

        if(!visit[i]){
                prime.push_back(i);
                if(i<=mx){
                    for(int j=i*i;j<limit;j=j+(i<<1) ){
                        visit[j]=1;
                    }
                }
        }
    }
    total_prime=prime.size();
}



void solve( ){

int a,b,c,d;
cin>>a>>b>>c>>d;







}//end of8 solve()



int main(){
Fast;
seive();


int t=1;
cin>>t;
for(int i=1;i<=t;i++){
    solve();
}

return 0;
}
