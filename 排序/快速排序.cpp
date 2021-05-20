#include<bits/stdc++.h>
using namespace std;
/*int partition(int k[],int low,int high)
//交换k[low...high]的记录，使枢轴记录到位，并返回其所在位置
{  
    int pivotkey=k[low];//用子表的第一个记录作枢轴记录
    while(low<high)
    {
        while(low<high&&k[high]>=pivotkey)
        high--;
        swap(k[high],k[low]);
        while(low<high&&k[low]<=pivotkey)
        low++;
        swap(k[high], k[low]);
    }
    return low;
}*/
//改进版partition
int partition(int k[], int low, int high)
//交换k[low...high]的记录，使枢轴记录到位，并返回其所在位置
{
    int pivotkey = k[low];  //用子表的第一个记录作枢轴记录
    k[0]=k[low];//用子表的第一个记录作枢轴记录
    while (low < high) {
        while (low < high && k[high] >= pivotkey) high--;
        k[low]=k[high];
        while (low < high && k[low] <= pivotkey) low++;
        k[high]=k[low];
    }
    k[low]=k[0];
    return low;
}
void qsort(int k[],int low,int high)
{
    if(low<high)
    {
        int pivotloc=partition(k,low,high);
        qsort(k,low,pivotloc-1);
        qsort(k,pivotloc+1,high);
    }
}
/*int main() {
    int k[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    qsort(k,1,n);
    for (int i = 1; i <= n; i++) cout << k[i] << " ";
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
    cout << "**********快速排序**********" << '\n';
    t = clock();
    qsort(in_order, 1,10000);
    s = clock();
    cout << "顺序时间" << double(s - t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    qsort(re_order,1, 10000);
    t = clock() - t;
    cout << "逆序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    qsort(random_order, 1,10000);
    t = clock() - t;
    cout << "乱序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';
}