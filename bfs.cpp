/* author:
   nakul bharti :

   */

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define Size 1000002
using namespace std;
vi g[Size];
vi visit(Size,0);
vi dist(Size,-1);
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    visit[u]=1;
    dist[u]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();

        for(auto i:g[v])
        {
            if(!visit[i])
            {
                dist[i]=dist[v]+1;
                q.push(i);
            }
        }

    }
}
int main()
{
    int v,e,s;
    cin>>v>>e>>s;
    int x,y;
    for(int i=0;i<v;i++)
    {
        g[i].clear();
    }
    dist.clear();
    visit.clear();
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        --x;--y;
        g[x].pb(y);

    }
   bfs(--s);
   for(int i=0;i<v;i++)
   {
       cout<<dist[i]<<" <<;
   }

}
