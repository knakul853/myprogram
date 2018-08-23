#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll combi(int n,int r)
{
    ll res=1;

    for(int i=0;i<r;i++)
    {
        res*= (n-i);


    }
    return res;


}
int main()
{
    int n,r;
    cin>>n>>r;
    int res = combi(n,r);
    cout<<res<<endl;
}

