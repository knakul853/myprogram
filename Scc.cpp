#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
using namespace std;
const int V = 100;
vi g[V];
vi gr[V];
int visit[V];
stack<int>st;
vi cp;
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
    visit[v]= 1;
    cp.pb(v);
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1)
    {

    int v,e;
    cin>>v>>e;
    if(v==0&& e==0)return 0;
    for(int i=0;i<v;i++)
    {
        g[i].clear();
        visit[i]=0;
        gr[i].clear();
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

    int cto=0,cte=0;
    for(int i=0;i<v;i++)
    {
        visit[i]=0;
    }

    while(!st.empty())
    {
        int tp = st.top();
        if(!visit[tp])
        {
            dfs2(tp);
            if(cnt%1)
            {
                cto+=cnt;
            }
            else
            {
                cte+=cnt;
            }
            cnt=0;
        }
        else
        {
            st.pop();
        }
    }

cout<<cte<<endl;
    cout<<cto-cte<<endl;
    cp.clear();

    }

}
