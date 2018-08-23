#include<bits/stdc++.h>
using namespace std;
const int N = 1e2;
int p[N][N];
int stp,ct;
char A[N];
struct suf{
int rnk[2];
int p;

};
typedef struct suf suf;
int cmp(suf a,suf b)
{
    return (a.rnk[0]==b.rnk[0]?(a.rnk[1]<b.rnk[1]?1:0):(a.rnk[0]<b.rnk[0]?1:0));

}
void build(int n)
{
    suf ar_suf[n];
    for(int i=0;i<n;i++)
    {
        p[0][i] = A[i]-'a';
    }

    for(stp=1,ct=1;ct<n; stp++,ct*= 2)
    {

        for(int i=0;i<n;i++)
        {

            ar_suf[i].rnk[0] = p[stp-1][i];
            ar_suf[i].rnk[1] = (i+ct)<n?p[stp-1][i+ct]:-1;
            ar_suf[i].p = i;
        }

        sort(ar_suf,ar_suf+n,cmp);
        for(int i=0;i<n;i++)
        {
            p[stp][ar_suf[i].p]=i>0 && ar_suf[i].rnk[0]==ar_suf[i-1].rnk[0] && ar_suf[i].rnk[1]==ar_suf[i-1].rnk[1]?p[stp][ar_suf[i-1].p]:i;


        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<ar_suf[i].p<<" ";
    }
}
int main()
{
gets(A);
int n = strlen(A);
build(n);

}
