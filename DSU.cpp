#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int par[maxn];
int root(int v){
    return par[v]<0?v:(root(par[v]));
}
void merge(int x,int y){ 
    if((x = root(x)) == (y = root(y)))     return ;
    if(par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;

}

string get(int x,int y){
    return root(x)==root(y)?"YES":"NO";
}

int n,q,a,b;
string s;
main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(par,-1,sizeof(par));
    cin>>n>>q;
    while(q--){
        cin>>s>>a>>b;
        if(s=="union"){
            merge(a,b);
        }else{
            cout<<get(a,b)<<"\n";
        }
    }
}
