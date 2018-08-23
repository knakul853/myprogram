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
vector<pair<int,int>>sol;
void cl()
{
    for (int i=0;i<V;i++)
    {
        g[i].clear();
        parent[i] = -1;
        visit[i] = 0;
        ans=0;
        ti=0;
    }
}

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
                sol.pb(mp(v+1,i+1));
            }


        }
        else if(parent[v]!=i)
        {
            low[v]=min(low[v],disc[i]);
        }


    }


}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

   int t,h=0;
   cin>>t;
   while(t--)
   {
       cl();
       int v,e;
       cin>>v>>e;
       for(int i=0;i<e;i++)
       {

           int x,y;
           cin>>x>>y;
           --x;--y;
           g[x].pb(y);
           g[y].pb(x);
       }

       for(int j=0;j<v;j++)
       {
           if(!visit[j])
            dfs(j);
       }
       cout<<"Caso #"<<++h<<endl;
       if(ans)
       cout<<ans<<endl;
       else
        cout<<"Sin bloqueos"<<endl;
       ans=0;
       sort(sol.begin(),sol.end());
       for(int i=0;i<sol.size();i++)
       {
           if(sol[i].first<sol[i].second)
           cout<<sol[i].first<<" "<<sol[i].second<<endl;
       }
       sol.clear();
   }

}

