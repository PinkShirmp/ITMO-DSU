#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+1;
int par[maxn];
int root(int v){return par[v]<0?v:par[v]=root(v);}
void merge(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    if(par[x]<par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int get(int x){

}

main(){
    cin.tie(0)->sync_with_stdio(0);

}
