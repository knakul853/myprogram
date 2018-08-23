/* author:
   nakul bharti :

   */

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define Size 1000000
using namespace std;
vi g[Size];
vi visit(Size,0);
int node;
void dfs(int u)
{
    //cout<<u<<endl;
    node++;
    visit[u]=true;
    for(auto i:g[u])
    {
        if(!visit[i])
        {
            dfs(i);

        }

    }

}

int main(){
    int t;
    cin>>t;

    while(t--){
            int x,y;
    int v,e,clib,crod;


cin>> v >> e >> clib >> crod;

for(int i=0;i<e;i++)
{
    cin>>x>>y;
    x--;y--;
    g[x].pb(y);
    g[y].pb(x);

}

long cost=0;

for(int i=0;i<v;i++)
{

    if(!visit[i]){
         node=0;
        dfs(i);
       // cout<<node<<endl;
        cost+=clib;
        if(clib>crod)
        {
            cost+=(crod*(node-1));
        }
        else{
            cost+=(clib*(node-1));
        }
        node=0;
    }


}
cout<<cost<<endl;
for(int i=0;i<=v;i++)
{
    g[i].clear();
    visit[i]=false;

}

    }
    return 0;

}


