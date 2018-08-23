#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define io ios::sync_with_stdio(false)
using namespace std;
const int V = 1e3+5;
vi g[V];
int visit[V];
int ti;
int low[V];
int disc[V];
int parent[V];
int ans=0;
int ct=0;
vi ap;
vector<pair<int,int>>sol;

void dfs(int v)
{
    int child=0;
    visit[v]=1;
    low[v]=disc[v] =++ti;
    for(auto i:g[v])
    {
        if(!visit[i])
        {
            child++;
            parent[i] = v;
            dfs(i);
            low[v] = min(low[v],low[i]);
            if(low[i]>disc[v])
            {
                ans++;
                sol.pb(mp(v,i));
            }
            if(parent[v]==-1 && child>1)
            {
                ct++;
                ap.pb(v);
            }
            if(parent[v]!=-1 && low[i]>=disc[v])
            {
                ct++;
                ap.pb(v);
            }


        }
        else if(parent[v]!=i)
        {
            low[v]=min(low[v],disc[i]);
            ct++;
        }


    }


}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
       int v,e;
       cin>>v>>e;
       for(int i=0;i<v;i++)
       {
           parent[i] = -1;
       }
       for(int i=0;i<e;i++)
       {

           int x,y;
           cin>>x>>y;
           g[x].pb(y);
           g[y].pb(x);
       }

       for(int j=0;j<v;j++)
       {
           if(!visit[j])
            dfs(j);
       }
       cout<<ap.size()<<endl;
       sort(ap.begin(),ap.end());
       for(int i=0;i<ap.size();i++)
        cout<<ap[i]<<" ";
       ap.clear();
       cout<<endl;
       cout<<ans<<endl;
       ct=0;
       sort(sol.begin(),sol.end());
       for(int i=0;i<sol.size();i++)
       {
           if(sol[i].first<sol[i].second)
           cout<<sol[i].first<<" "<<sol[i].second<<endl;
       }
       sol.clear();
}


