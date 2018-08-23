#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define Size 100000
using namespace std;
vi g[Size];
vi visit(Size);
stack<int> ans;
void dfs(int v)
{
    visit[v]=1;
    for(auto i:g[v])
    {
        if(visit[i]!=1)
        {
            dfs(i);
        }
    }
    ans.push(v+1);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v,e;
    cin>>v>>e;
    for(int i=0;i<v;i++)
    {
        g[i].clear();
        visit[i]=0;
    }
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].pb(y);
    }

    for(int i=0;i<v;i++)
    {
        if(!visit[i])
        dfs(i);
    }

   while(!ans.empty())
   {
       cout<<ans.top()<<" ";
       ans.pop();
   }



}
