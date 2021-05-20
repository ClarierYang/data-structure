#include<iostream>
using namespace std;
int lowerbound(long long nums[], int n, long long target) {
    int left = 0, right = n;
    int result = -1;
    while(left<right) {
        int mid = left + (right - left)/2;
        if (nums[mid] >= target){
            right = mid;
        } else
        {
            result = mid;
            left = mid + 1;
        }
    }
    if(result==-1&&nums[0]<target) result = 0;
    return result;
}
int upperbound(long long nums[], int n, long long target) {
    int left = 0, right = n;
    int result = -1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            result = mid;
            right = mid;
        }
    }
    if (result == -1 && nums[n-1] > target) result = n-1;
    return result;
}
