#include <bits/stdc++.h>
using namespace std;
void Binsertsort(int k[], int n)
// n是数组的长度,注意这个数组k是下标从1~n，k[0]用作哨兵
{
    int i,j;
    for(i=2;i<=n;i++)
    {
    k[0]=k[i];
    int low=1,high=i-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(k[i]<k[mid])//插入点在低半区
        high=mid-1;
        else low=mid+1;
    } //最后的插入位置在high+1
    for(j=i-1;j>=high+1;--j)
    k[j+1]=k[j];
    k[high+1]=k[0];
    }
}

int main() {
    int k[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    Binsertsort(k, n);
    for (int i = 1; i <= n; i++) cout << k[i] << " ";
}