#include<bits/stdc++.h>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN]; // input string
struct entry
{
int nr[2];
int p;    // keep track of index of suffix that is our final ans:
} L[MAXN]; //nr[0]rank of 1st element nr[1] rank of next element
int P[MAXLG][MAXN];// p[i][j] represent rank of jth suffix at i th iteration
int N,i;
int stp, cnt;
int cmp(struct entry a, struct entry b)
{
return a.nr[0]==b.nr[0] ?(a.nr[1]< b.nr[1] ?1: 0): (a.nr[0]< b.nr[0] ?1: 0);  // pretty obious
}
int main()
{
gets(A);
for(N=strlen(A), i = 0; i < N; i++)
P[0][i] = A[i] - 'a';     // at Oth iteration rank of ith suffixes :
for( stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
{

for(i=0; i < N; i++)
{

     L[i].nr[0]=P[stp- 1][i];
     L[i].nr[1]=i +cnt < N? P[stp -1][i+ cnt]:-1;
     L[i].p= i;

}
sort(L, L+N, cmp);
for(i=0; i < N; i++)
P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
}


for(int i=0;i<N;i++)
{
    cout<<L[i].p<<" ";
}
return 0;
}
