
#include<bits/stdc++.h>

using namespace std;

#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e18
#define mod 1000000007
#define limit 200009
#define ceil(a,b) (int)((a+b-1)/b)


bool visit[limit];
vector<int> v[limit];
int parent[limit];
bool ans;

void printTheGraph(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" : ";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }cout<<"\n";
}

void dfs(int node,int parentt){

    if(visit[node] && node!=parent[parentt] ){
            cout<<node<<" "<<parentt<<"\n";
            ans=1;return;
    }
    if(visit[node] ){return;}

    cout<<"\n\n"<<node<<"\n\n";
    visit[node]=1;
    int sz=v[node].size();

    for(int i=0;i<sz;i++){
        if(!visit[v[node][i]])parent[v[node][i]]=node;
        dfs(v[node][i], node);
    }
}




void solve(){

int n,m;

cin>>n>>m;

map<int,int> mp;

int a,b;
for(int i=0;i<m;i++){
    cin>>a>>b;
    if(a!=b && mp[min(a,b)]!=max(a,b) ){
            v[a].push_back(b);
            v[b].push_back(a);
            mp[min(a,b)]=max(a,b);
    }
}

for(int i=1;i<=n;i++){
    parent[i]=0;
    visit[i]=0;
}


printTheGraph(n);

ans=0;

int i;
for( i=1;i<=n;i++){
        if(!visit[i])dfs(i,i);
        if(ans){break;}
}

for(int i=1;i<=n;i++){
    cout<<parent[i]<<" ";
}cout<<"\n";

if(ans){cout<<"No";}
else cout<<"Yes";

}//end of solve()





int main(){
Fast;
int t=1;
//cin>>t;
while(t--){
solve();
}
return 0;
}

