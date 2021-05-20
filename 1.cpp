
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
int a[maxn], b[maxn];
// a[]是原始数组，从小到大排序，取k个数合并放入数组b里,b[]有序

int Hafuman(int k) {  //返回总代价
    int cura, curb;   //指针
    int cnt;          //数组b的长度
    cnt = 0;
    cura = curb = 0;
    int cost = 0;
    bool flag = true;
    while (n - cura + cnt - curb > 1) {
        int num = 0;
        //每次取k个时最后一次不够k个数，先取掉x个数，剩下n-x整除k
        if (flag) {
            if ((n - k) % (k - 1) == 0)  //整除
                num = k;                 //取的次数
            else
                num = (n - k) % (k - 1) + 1;
            flag = false;
        } else
            num = k;
        int sum = 0;
        //两个数组里挑选出k个最小的数合并再次放到数组b的末尾
        while (num--) {
            if (cura == n) {  //剩余都是数组b里的
                sum += b[curb];
                curb++;
            } else if (curb == cnt) {  //剩余都是数组a里的
                sum += a[cura];
                cura++;
            } else if (a[cura] < b[curb]) {  //选数组a[cura]
                sum += a[cura];
                cura++;
            } else {  //选数组b[curb]
                sum += b[curb];
                curb++;
            }
        }
        cost += sum;
        b[cnt++] = sum;
    }
    return cost;
}

int main() {
    int n,k;
        scanf("%d", &n);
        scanf("%d", &k);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        printf("%d\n", Hafuman(k));

    return 0;
}