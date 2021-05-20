#include <bits/stdc++.h>
using namespace std;
void shellinsert(int k[],int dk,int n)
{
    int i,j;
    for(i=dk+1;i<=n;i++)
    {
        if(k[i]<k[i-dk])
        {k[0]=k[i];
        for(j=i-dk;j>0&&k[0]<k[j];j-=dk)
        k[j+dk]=k[j];//记录后移
        k[j+dk]=k[0];}
    }
}
void shellsort(int k[],int dlta[],int t,int n)
{
    for(int i=0;i<t;i++)
    shellinsert(k,dlta[i],n);
}
int main() {
    int k[100];
    int dlta[10], t=2,n;
    dlta[0] = 3, dlta[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    shellsort(k, dlta,t,n);
    for (int i = 1; i <= n; i++) cout << k[i] << " ";
}