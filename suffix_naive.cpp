#include<bits/stdc++.h>
using namespace std;
struct suffix{
int index;
char *suff;

};
int cmp(struct suffix a,struct suffix b)
{
    return strcmp(a.suff,b.suff)<0?1:0;

}
int *build(char * txt,int n)
{
    struct suffix suffixes[n];
    for (int i=0;i<n;i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);

    }
    sort(suffixes,suffixes+n,cmp);
    int *suf_ar = new int[n];
    for(int i=0;i<n;i++)
    {
        suf_ar[i] = suffixes[i].index;
    }
    return suf_ar;
}
int main()
{
     char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = build(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
   for(int i=0;i<n;i++)
   {
       cout<<suffixArr[i]<<"  ";
   }
    return 0;


}
