#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define ll long long
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
       ll ans1=0,ans2=0;
        for(ll i=0;i<n;i++)
        {
            ans1++;
            if(v[i]<=x)
            {
                ans2+=v[i];
            }
            else
            {
            break;
            }
        }

        cout<<ans1<<" "<<ans2<<endl;


    }
}

