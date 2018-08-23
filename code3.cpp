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
int a[N];
int main()
{
   io
   string s1,s2;
   cin>>s1>>s2;
   int l = s1.length();
   int l2 = s2.length();
   int ct=0;
   int ct1=0;
   int k=0;
   if(s1==s2)
   {
       cout<<0<<endl;
       return 0;
   }
   if(l==0||l2==0)
   {
       cout<<abs(l-l2)<<endl;
       return 0;
   }
   for(int i=0;i<min(l,l2);i++)
       {
           if(s1[k]==s2[k])
           {
               ct++;

           }
           else{break;}
           k++;
       }
       k= l-1;
       int j = l2-1;
       for(int i=min(l,l2)-1;i>=0;i++)
       {
           if(s1[k]==s2[j])
           {
               ct1++;
           }
           else{break;}
           k--;j--;
       }


    ct = max(ct,ct1);
    int res = l+l2-(ct)*2;
    cout<<res<<endl;





}

