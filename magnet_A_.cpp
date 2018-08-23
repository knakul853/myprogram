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
#define m unordered_map<int,int>
#define st set<int>
const int N = 50005;
vi g(N);
int n;
int p[N];
int main()
{
   io
   int t;
   cin>>t;
int ct=0;
vi ans;
for(int i=0;i<t;i++)
{
    string s;
    cin>>s;
    ans.pb(int(s[0]));

}
for(int i=0;i<ans.size()-1;i++)
{
    if(ans[i] !=ans[i+1])
    {
        ct++;
    }
}
cout<<ct+1<<endl;

}
