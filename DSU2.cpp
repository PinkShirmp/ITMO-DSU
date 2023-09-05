#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+1;
int par[maxn],minres[maxn],maxres[maxn];
int root(int v){return par[v]<0?v:par[v]=root(par[v]);}
void merge(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    if(par[x]<par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    maxres[x]=max(maxres[x],maxres[y]);
    minres[x]=min(minres[x],minres[y]);

}
int n,m;
main(){  
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++){
        maxres[i]=minres[i]=i;
    }
     string s;
    int u,v;
    while(m--){
        cin>>s;
        if(s=="union"){
            cin>>u>>v;
            merge(u,v);
        }else{
         cin>>v;
         v=root(v);
        cout<<minres[v]<<" "<<maxres[v]<<" "<<abs(par[v])<<"\n";    
        }
    }
}
