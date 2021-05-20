#include<bits/stdc++.h>
using namespace std;
void Selectsort(int k[],int n)
{
    int tempmax;
    for(int i=1;i<=n;i++)
    {
        tempmax=k[i];
        for(int j=i+1;j<=n;j++)
        {
            if(k[j]<tempmax)
            {
                int temp=k[j];
                k[j]=tempmax;
                tempmax=temp;
            }
        }
        k[i]=tempmax;
    }
}
/*int main()
{
    int n;
    cin>>n;
    int *k=new int[n];
    for(int i=0;i<n;i++)
    cin>>k[i];
    Selectsort(k,n);
    for(int i=0;i<n;i++)
    cout<<k[i]<<" ";
    cout<<endl;
}*/
int main()
{
    const int n = 10001;
    int in_order[n];
    int re_order[n];
    int random_order[n];
    clock_t t,s;
    //顺序
    for (int i = 1; i <= 10000; i++) in_order[i] = i;
    //逆序
    for (int i = 1; i <= 10000; i++) re_order[i] = 101 - i;
    //随机
    srand(int(time(0)));
    for (int i = 1; i < n; i++) random_order[i] = rand() % 20000;
    cout << "**********插入排序**********" << '\n';
    t = clock();
    Selectsort(in_order, 10000);
    s = clock() ;
    cout << "顺序时间" << double(s-t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    Selectsort(re_order, 10000);
    t = clock() - t;
    cout << "逆序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    Selectsort(random_order, 10000);
    t = clock() - t;
    cout << "乱序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';
}