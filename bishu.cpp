#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define Max 100000
using namespace std;
vvi g(Max);
vector<bool>visit(Max,false);
vector<int>dist(Max,0);
void dfs(int sv)
{
    visit[sv]=true;
    for(auto i:g[sv])
    {
        int v=i;
        if(!visit[i])
        {
            dist[i]=dist[sv]+1;
            dfs(i);
        }
    }

}
int main()
{
int v,e;
cin>>v;
e=v-1;
dist.clear();
visit.clear();
for(int i=0;i<v;i++)
{
    g[i].clear();
}
int x,y;
for(int i=0;i<e;i++){
    cin>>x>>y;
    x--;y--;
    g[x].push_back(y);
    g[y].push_back(x);
}
dfs(0);
int ans=0;
int Min=INT_MAX;

int q;
cin>>q;
int m;
cout<<endl;
while(q--)
{
    cin>>m;
    m--;
    if(dist[m]<Min)
    {
        Min=dist[m];
        ans=m;
    }
}

cout<<ans+1<<endl;



}
