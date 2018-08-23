#include<bits/stdc++.h>
using namespace std;
#define f0(i,n) for(int (i) = 0;(i)<n;(i)++)
#define f1(i,n) for(int i = 1;i<=n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define ll long long
#define  sc(n) scanf("%d",&n)
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define io ios::sync_with_stdio(false);cin.tie(0);
const int N = 50005;
vi g[N];
int n;
int main()
{
   io
   int tt;
   cin>>tt;
   while(tt--)
   {
       cin>>n;
       int p[n];
       int a,b;
       f0(i,n)cin>>p[i];
       f0(i,n-1){
       cin>>a>>b;

       a--;b--;

       g[a].pb(b);
       g[b].pb(a);

       }
       unordered_map<int,int>m;

    f0(i,n)m[p[i]]=i+1;

    set<int>st;

    f0(i,n){st.insert(p[i]);}

    f0(i,n){

    st.erase(p[i]);

    for(auto j:g[i])
    {
        st.erase(p[j]);
    }

      auto it = st.rbegin();

    cout<<m[*it]<<" ";

    st.insert(p[i]);



    for(auto j:g[i])
    {
        st.insert(p[j]);
    }



    }
    cout<<endl;
    f0(i,n){g[i].clear();}

   }

}
