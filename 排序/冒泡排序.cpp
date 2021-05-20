#include <bits/stdc++.h>
using namespace std;
void bubblesort(int k[],int n)
{
    int i=n;
    int lastchangeindex;  //记录最后一次交换的位置
    while(i>1)
    {
        lastchangeindex=1;
        for(int j=1;j<i;j++)
        {if(k[j+1]<k[j]){
            int tmp=k[j+1];
            k[j+1]=k[j];
            k[j]=tmp;
        }
        lastchangeindex=j;
        }
        i=lastchangeindex;//本趟进行交换的最后一个记录的位置，说明后面的都有序了
    }
}
int main() {
    int k[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    bubblesort(k, n);
    for (int i = 1; i <= n; i++) cout << k[i] << " ";
}
