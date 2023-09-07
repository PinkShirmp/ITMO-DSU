#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+1;
const int maxk=150001;
int par[maxn];
int root(int v){return par[v]<0?v:par[v]=root(par[v]);}
void marge(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    if(par[x]<par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
bool ask(int x,int y){
    return (root(x)==root(y))?true:false;
}
int n,mi,q,u,v;
map<pair<int,int>,bool>m;

struct{
    string t;
    int u,v;
}QueryData[maxk];
main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(par,-1,sizeof(par));
    cin>>n>>mi>>q;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        m[make_pair(u,v)]=true;
        m[make_pair(v,u)]=true;
    }
    string type;
    for(int i=1;i<=q;i++){
        cin>>type>>u>>v;
        if(type=="cut"){
            m[make_pair(u,v)]=false;
            m[make_pair(v,u)]=false;
            QueryData[i].t=type;
            QueryData[i].u=u;
            QueryData[i].v=v;
        }else{
            QueryData[i].t=type;
            QueryData[i].u=u;
            QueryData[i].v=v;
        }
    }

    //build dsu//
    
    for(auto x: m){
        pair<int,int> key=x.first;
        int value=x.second;
        if(value){
            marge(key.first,key.second);
        }
    }
    //query//
    vector<string> res;;
    for(int i=q;i>=1;i--){
        string type=QueryData[i].t;
        int u=QueryData[i].u, v=QueryData[i].v;
        if(type=="cut"){ //cut = connect
            marge(u,v);
        }else if(type=="ask"){
            res.push_back((ask(u,v)?"YES":"NO"));
        }
    }
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<"\n";
    }
}
