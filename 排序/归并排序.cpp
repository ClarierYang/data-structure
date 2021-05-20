#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int tmp[maxn];
void merge(int a[],int low,int mid,int high)
{
    int l=low,m=mid+1;
    int k=0,i=0;
    while(l<=mid&&m<=high)
    {
        if(a[l]<=a[m])
        tmp[k++]=a[l++];
        else
        tmp[k++]=a[m++];
    }
    if(l<=mid)
    {
        for(i=l;i<=mid;i++)
        tmp[k++]=a[i];
    }
    if(m<=high)
    for(i=m;i<=high;i++)
    tmp[k++]=a[i];
    for(i=low;i<=high;i++)
    a[i]=tmp[i];
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
/*int main()
{
    int n,a[maxn];
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    mergesort(a,1,n);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
}*/
int main() {
    const int n = 10001;
    int in_order[n];
    int re_order[n];
    int random_order[n];
    clock_t t, s;
    //顺序
    for (int i = 1; i <= 10000; i++) in_order[i] = i;
    //逆序
    for (int i = 1; i <= 10000; i++) re_order[i] = 10001 - i;
    //随机
    srand(int(time(0)));
    for (int i = 1; i < n; i++) random_order[i] = rand() % 20000;
    cout << "**********归并排序**********" << '\n';
    t = clock();
    mergesort(in_order, 1, 10000);
    s = clock();
    cout << "顺序时间" << double(s - t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    mergesort(re_order, 1, 10000);
    t = clock() - t;
    cout << "逆序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    mergesort(random_order, 1, 10000);
    t = clock() - t;
    cout << "乱序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';
}
