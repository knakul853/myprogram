/* author:
   nakul bharti :1:26 PM
Saturday, 23 June 2018 (IST)

   */

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define Size 50008
using namespace std;
vi g[Size];
vi visit(Size);
int node=0;
void dfs(int s)
{
    visit[s]=1;
    node++;
    for(auto i:g[s])
    {
       if(visit[i]==0)
       {
           dfs(i);
       }

    }

}
int main()
{
        int v,e,s;
        cin>>v>>e>>s;
        int x,y;
        g[v];
        for(int i=0;i<e;i++)
        {
            cin>>x>>y;
            x--;y--;
            g[x].pb(y);

        }
        if(e==0)
            cout<<v-1<<endl;
        else{
        dfs(--s);
        int ct=0;
        for(int i=0;i<v;i++)
        {
            if(!visit[i]&&i !=s)
            {
                dfs(i);
                ct++;
            }

        }
        //cout<<node<<endl;
        cout<<ct<<endl;

for(int i=0;i<=v;i++){
    g[i].clear();
    visit[i]=0;
}
        }

    }

