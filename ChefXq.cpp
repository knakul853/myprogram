#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SQRT 320
#define MXN 100005
ll a[MXN];
int dp[SQRT][1000001];
ll prefix_xor[SQRT];
int size_block,n;
void update(int v,int ind)
{
    int blnum = ind/size_block;
    prefix_xor[blnum] = prefix_xor[blnum]^a[ind]^v;

    int i = ind,temp=0;
    int j = blnum*size_block;
    while(j<=ind)
    {
        temp = temp^a[j];j++;
    }
    dp[blnum][temp]-=1;
    dp[blnum][temp^a[ind]^v]+=1;
    i++;
    while(i%size_block!=0)
    {
        temp = temp^a[i];
             dp[blnum][temp]-=1;
                 dp[blnum][temp^a[ind]^v]+=1;
                 i++;

    }
    a[ind]=v;

}
ll query(int l,int r,int k)
{
    int res =0;
    ll temp = k;
    while(l+size_block<=r)
    {
        res+=dp[l/size_block][temp];
        temp =temp^prefix_xor[l/size_block];
        l+=size_block;
    }
    temp=temp^k;

    while(l<=r)
    {
        temp=temp^a[l];
        if(temp==k)
            res+=1;
        l++;
    }
    return res;



}
void build()
{
    int blk_ind = -1;
    size_block = sqrt(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ll temp=0;
        if(i%size_block==0)
        {
            blk_ind++;
            temp=0;
        }
        temp = temp^a[i];
        prefix_xor[blk_ind]=temp;
        dp[blk_ind][temp]+=1;

    }
}
int main()
{
    ios::sync_with_stdio(false);	cin.tie(NULL);
	int q;
	cin>>n>>q;
	build();
	while(q--)
	{
    		int t,x, y;
    		cin>>t>>x>>y;
    		if(t == 1)
    			update(x-1,y);
    		else
    			cout<<query(0,x-1,y)<<endl;
	}
	return 0;


}

