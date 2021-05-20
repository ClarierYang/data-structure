#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int binarysearch(int n, int key, vector<int>& a) {
    if (a[n - 1] < key) return n + 1;
    int right = 0, left = n - 1, mid, p;
    while (right <= left) {
        mid = (right + left) / 2;
        if (a[mid] < key) {
            right = mid + 1;
        } else if (a[mid] >= key) {
            p = mid;
            left = mid - 1;
        }
    }
    return p + 1;
}
int main()
{
    vector<int> a;
    int n,key,k;
    cin>>n>>key;
    for(int i=0;i<n;i++)
    cin>>k;
    a.push_back(k);
    binarysearch(n,key,a);
}