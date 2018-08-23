#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define io ios::sync_with_stdio(false)
using namespace std;
const int V = 100;
vi g[V];
vi gr[V];
int visit[V];
stack<int>st;
int cnt;
void dfs1(int v)
{
    visit[v] = 1;
    for(auto i:g[v])
    {
        if(!visit[i])
        {
            dfs1(i);
        }

    }
    st.push(v);
}

void dfs2(int v)
{
    visit[v] = 1;
    cnt++;
    for(auto i:gr[v])
    {
        if(!visit[i])
        {
            dfs2(i);
        }
    }

}
int main()
{
    io;
    int v,e;
    cin>>v>>e;
    for(int i=0;i<v;i++)
    {

        g[i].clear();
        gr[i].clear();
        visit[i]=0;
    }

   for(int i=0;i<e;i++)
   {
       int x,y;
       cin>>x>>y;
       --x;--y;
       g[x].pb(y);
       gr[y].pb(x);

   }

   for(int i=0;i<v;i++)
   {
       if(!visit[i])
       {
           dfs1(i);
       }
   }

   for(int i=0;i<v;i++)
   {
       visit[i] =0;
   }
   int odd=0,even=0;
    while(!(st.empty()))
    {
        int tp = st.top();
        st.pop();
        if(!visit[tp])
        {
            dfs2(tp);
            if(cnt&1)
            {
                odd+=cnt;
            }
            else
            {
                even+=cnt;
            }
            cnt=0;
        }

    }
    cout<<odd-even<<endl;

}

