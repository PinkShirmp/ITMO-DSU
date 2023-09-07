#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+1;
int par[maxn],bonus[maxn];


int root(int v){
    if(par[v]<0){
        return v;
    }
    int RootV=root(par[v]);
    if(par[v]!=RootV){
        bonus[v]+=bonus[par[v]];
    }
    return par[v]=RootV;
}

void merge(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    if(par[x]<par[y]) swap(x,y);
    par[x]+=y;
    par[y]=x;
    bonus[x]-=bonus[y];
}
void add(int x,int v){
    int g=root(x);
    bonus[g]+=v;
}
int get(int X){
    int rootX=root(X);
    if(rootX==X){
        return bonus[X];
    }else{
        return bonus[X]+bonus[rootX];
    }
}
int n,q;
main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    memset(par,-1,sizeof(par));
    string type;
    int a,b,c;
    while(q--){
        cin>>type;
        if(type=="add"){
            cin>>a>>b;
            add(a,b);
        }else if(type=="join"){
            cin>>a>>b;
            merge(a,b);
        }else{
            cin>>a;
            cout<<get(a)<<"\n";
        }
    }
}
