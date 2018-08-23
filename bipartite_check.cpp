#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define Size 100000
using namespace std;
vi g[Size];
vi color(Size);
bool bipartite(int v)
{
    queue<int>q;
    q.push(v);
    color[v]=0;//red
    while(!q.empty())
    {
       // cout<<q.size()<<endl;
        int u =q.front();
        q.pop();
        for(auto i:g[u])
        {
            if(color[i]==-1)
            {
                //cout<<i<<endl;
                color[i]=color[u]^1;
                q.push(i);
            }
            else if(color[i]==color[u]){
                return false;
            }
        }
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v,e;
    cin>>v>>e;
    int x,y;
    for(int i=0;i<v;i++)
    {
        g[i].clear();
    }
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        --x;--y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i=0;i<v;i++)
    {
        color[i]=-1;
    }
    int s;
    cin>>s;
    bool res = bipartite(--s);
   if(res == true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
