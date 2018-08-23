#include <cstdio>
#include <algorithm>
using namespace std;

int niz[8001];

int main()
{
    int n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=0;i<n;i++)
    {
        if(niz[i]!=0 || i==0)
        {
            niz[i+a]=max(niz[i+a],niz[i]+1);
            niz[i+b]=max(niz[i+b],niz[i]+1);
            niz[i+c]=max(niz[i+c],niz[i]+1);
        }
    }
    printf("%d",niz[n]);
}
