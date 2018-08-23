#include<bits/stdc++.h>
using namespace std;
struct suffix{

int Rank[2];
int index;
};
int cmp(struct suffix a,struct suffix b)
{
    return a.Rank[0]==b.Rank[0]?(a.Rank[1]<b.Rank[1]?1:0):(a.Rank[0]<b.Rank[1]?1:0);

}
int *build(char *txt,int n)
{
    struct suffix suffixes[n];

    for(int i=0;i<n;i++)
    {
        suffixes[i].index = i;
        suffixes[i].Rank[0] = txt[i]-'a';
        suffixes[i].Rank[1] = (1+i)<n?txt[1+i]-'a':-1;
    }
    sort(suffixes,suffixes+n,cmp);
    int ind[n];
    for(int k=4;k<2*n;k*=2)
    {
        int rnk = 0;
        int pre_rnk = suffixes[0].Rank[0];
        suffixes[0].Rank[0] = rnk;
        ind[suffixes[0].index] = 0;
        for(int i=1;i<n;i++)
        {
            if(suffixes[i].Rank[0]==pre_rnk && suffixes[i].Rank[1]==suffixes[i-1].Rank[1])
            {
                pre_rnk = suffixes[i].Rank[0];
                suffixes[i].Rank[0] = rnk;
            }
            else
            {
                pre_rnk = suffixes[i].Rank[0];
                suffixes[i].Rank[0] = ++rnk;

            }
            ind[suffixes[i].index] = i;

        }
        for(int i=0;i<n;i++)
        {
            int next = suffixes[i].index+k/2;
            suffixes[i].Rank[1] = next<n?(suffixes[ind[next]].Rank[0]):-1;

        }
        sort(suffixes,suffixes+n,cmp);



    }
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {

        arr[i] = suffixes[i].index;
    }
    return arr;

}
int main()
{
     char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = build(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
   for(int i=0;i<n;i++)
   {
       cout<<suffixArr[i]<<" ";
   }
    return 0;


}
