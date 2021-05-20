#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int tmp[maxn];
void merge(int a[], int low, int mid, int high) {
    int l = low, m = mid + 1;
    int k = 0, i = 0;
    while (l <= mid && m <= high) {
        if (a[l] <= a[m])
            tmp[k++] = a[l++];
        else
            tmp[k++] = a[m++];
    }
    if (l <= mid) {
        for (i = l; i <= mid; i++) tmp[k++] = a[i];
    }
    if (m <= high)
        for (i = m; i <= high; i++) tmp[k++] = a[i];
    for (i = low; i <= high; i++) a[i] = tmp[i];
}
void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
//快速排序
int partition(int k[], int low, int high)
//交换k[low...high]的记录，使枢轴记录到位，并返回其所在位置
{
    int pivotkey = k[low];  //用子表的第一个记录作枢轴记录
    k[0] = k[low];          //用子表的第一个记录作枢轴记录
    while (low < high) {
        while (low < high && k[high] >= pivotkey) high--;
        k[low] = k[high];
        while (low < high && k[low] <= pivotkey) low++;
        k[high] = k[low];
    }
    k[low] = k[0];
    return low;
}
void qsort(int k[], int low, int high) {
    if (low < high) {
        int pivotloc = partition(k, low, high);
        qsort(k, low, pivotloc - 1);
        qsort(k, pivotloc + 1, high);
    }
}
//插入排序
void insertsort(int k[], int n)
// n是数组的长度,注意这个数组k是下标从1~n，k[0]用作哨兵
{
    int j;
    for (int i = 2; i <= n; i++) {
        if (k[i] < k[i - 1])
        //如果K[i]>=k[i-1]那么k[1···i]依然是有序表，这时候并不用调整k[i]位置
        {
            k[0] = k[i];
            k[i] = k[i - 1];  //同时将k[i-1]向后移位
            for (j = i - 2; k[j] > k[0]; j--) {
                k[j + 1] = k[j];  //记录后移
            }  //出循环时的k[j]<=k[0]，所有k[0]应当插在k[j+1]的位置
            k[j + 1] = k[0];
        }
    }
}
//选择排序
void Selectsort(int k[], int n) {
    int tempmax;
    for (int i = 1; i <= n; i++) {
        tempmax = k[i];
        for (int j = i + 1; j <= n; j++) {
            if (k[j] < tempmax) {
                int temp = k[j];
                k[j] = tempmax;
                tempmax = temp;
            }
        }
        k[i] = tempmax;
    }
}
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
    qsort(in_order, 1, 10000);
    s = clock();
    cout << "顺序时间" << double(s - t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    qsort(re_order, 1, 10000);
    t = clock() - t;
    cout << "逆序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    qsort(random_order, 1, 10000);
    t = clock() - t;
    cout << "乱序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';
}