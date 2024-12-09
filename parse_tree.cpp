#include<bits/stdc++.h>

using namespace std;

//#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e19
#define mod 1000000007
#define limit 200005
//#define ceil(a,b) (ll)((a+b-1)/b)
//#define abs(a,b) (ll)(max(a,b)-min(a,b))
#define p1f(a)        cout<<a<<"\n"
#define p2f(a,b)     cout<<a<<" "<<b<<"\n"
#define p3f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<"\n"
#define p4f(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"


void solve(){

int n,q;
cin>>n>>q;

int arr[n+1];

for(int i=1;i<=n;i++){cin>>arr[i];}

//stating building the parse tree
// calculation of the row of the parse tree
int row = floor(log2(n));

//taking space for the parsetree
int parsetable[row+1][n+2];


//initialization of the parse tree for the 2^0=1 length
for(int i=2;i<=n;i++){
    parsetable[0][i-1]=abs(arr[i]-arr[i-1]);
}

//calculating the parse tree for the next 2^1 to 2^row
int base=1;
for(int i=1;i<=row;i++){
    for(int j=1;(j+base)<=n;j++){
        parsetable[i][j] = __gcd(parsetable[i-1][j],parsetable[i-1][j+base]);
    }
    base=(base<<1);
}

//seeing the parsetable
//for(int i=0;i<=row;i++){
//    for(int j=1;j<=n;j++){
//        cout<<parsetable[i][j]<<" ";
//    }cout<<"\n";
//}


//starting the query from the parse tree...
// thus gcd is a overlooping friendly function so this query can be completed in O(1) time
// if some function is not overloop friendly then this query will take O(log(n)) and this process should be using binary representation of the query range

int a,b,d,highest_base;

for(int i=1;i<=q;i++){
    cin>>a>>b;
    if(a==b){cout<<"0 ";}
    else{
        d = abs(a-b);
        highest_base = floor(log2(d));
        cout<<__gcd(parsetable[highest_base][a] , parsetable[highest_base][b-(1<<highest_base)] )<<" ";
    }
}




cout<<"\n";

}



int main(){
//freopen("in.txt","r",stdin);

Fast;
int t=1;
cin>>t;


for(int i=1;i<=t;i++){
    solve();
}

return 0;
}


//auto fun_name = [&](int par1,...)->return_type{}


/*


*/
