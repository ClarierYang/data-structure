#include <bits/stdc++.h>
using namespace std;
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

/*int main() {
    int k[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    insertsort(k, n);
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
    for (int i = 1; i <= 10000; i++) re_order[i] = 101 - i;
    //随机
    srand(int(time(0)));
    for (int i = 1; i < n; i++) random_order[i] = rand() % 20000;
    cout << "**********插入排序**********" << '\n';
    t = clock();
    insertsort(in_order, 10000);
    s = clock();
    cout << "顺序时间" << double(s - t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    insertsort(re_order, 10000);
    t = clock() - t;
    cout << "逆序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';

    t = clock();
    insertsort(random_order, 10000);
    t = clock() - t;
    cout << "乱序时间" << double(t) / CLOCKS_PER_SEC * 1000 << "ms" << '\n';
}