#include<bits/stdc++.h>
#define Size 100000
using namespace std;
int a[Size];
int block[100];
int block_size;
void build(int input[],int n)
{
    int block_index =-1;
     block_size= sqrt(n);

    for(int i=0;i<n;i++)
    {
        a[i]=input[i];
        if(i%block_size==0)
        {
            block_index++;
        }
        block[block_index]+=a[i];


    }

}
void update(int index,int value)
{
    int block_index = index/block_size;

    block[block_index]+=value-a[index];
    a[index]=value;

}
int query(int l,int r)
{
    int sum=0;
    while(l<r && l%block_size!=0 && l!=0)
    {
        sum+=a[l];
        l++;
    }
    while(l+block_size<=r)
    {
        sum+=block[l/block_size];
        l+=block_size;
    }
    while(l<=r)
    {
        sum+=a[l];
        l++;


    }
    return sum;


}
int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    build(input,n);
    cout<<query(2,7)<<endl;
    update(3,7);
    cout<<query(2,7)<<endl;


}
