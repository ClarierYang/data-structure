#include <cstdio>
#include <iostream>
using namespace std;
#define maxn 100005
void heapadjust(int a[], int s, int m) {
    //重新调整为最大堆
    int rc = a[s];
    for (int j = 2 * s; j <= m; j *= 2) {
        if (j < m && a[j] < a[j + 1]) ++j;  // j为较大记录的下标
        if (rc >= a[j]) break;
        a[s] = a[j];
        s = j;
    }
    a[s] = rc;
}
void heapsort(int a[], int n) {
    for (int i = n / 2; i > 0; i--) heapadjust(a, i, n);//建堆，从最后一个非叶子结点开始
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);//依次将堆顶和最后一个非排序元素互换
        heapadjust(a, 1, i - 1);//重新调整为最大堆
    }
}
int main() {
    int n, a[maxn];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    heapsort(a, n);
    for (int i = 1; i <= n; i++)
        if (i != n)
            cout << a[i] << " ";
        else
            cout << a[i];
}