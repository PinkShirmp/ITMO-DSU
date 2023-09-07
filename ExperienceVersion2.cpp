#include <bits/stdc++.h>
const int maxn=2*2e5+1;
using namespace std;

int par[maxn],bonus[maxn];
 
int root(int v) {
    if (par[v] < 0) {
        return v;
    }
    int RootV = root(par[v]);
    if (par[v] != RootV) {
        bonus[v] += bonus[par[v]];
    }
    return par[v] = RootV;
}
void merge(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    if(par[x]<par[y]) swap(x,y);
    //merge node
    par[x]+=par[y];
    par[y]=x;
    //minus;
    bonus[y]-=bonus[x];
}

int get(int x){
    int rootx=root(x);
    if(x==rootx){
        return bonus[x];
    }else{
        return bonus[x]+ bonus[rootx];
    }
}

int add(int x,int v){
    int g=root(x);
    bonus[g]+=v;
}

int n,q;
main(){
    cin.tie()->sync_with_stdio(0);
    cin>>n>>q;
    string type;
    memset(par,-1,sizeof(par));
    int a, b, c;
    while (q--) {
        cin >> type;
        if (type == "add") {
            cin >> a >> b;
            add(a, b);
        } else if (type == "join") {
            cin >> a >> b;
            merge(a, b);
        } else {
            cin >> a;
            cout << get(a) << "\n";
        }
    }
}
