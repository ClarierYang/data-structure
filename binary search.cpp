#include<iostream>
using namespace std;
int binarysearch(int nums[], int n, int target) {
    int left = 0, right = n;
    while(left < right) {
        int mid = left + (right - left)/2;
        cout << "Searching: [" << left << "," << right << ") mid:" << mid <<endl;
        if( nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target)
        {
            left = mid + 1;
        }else if ( nums[mid]> target)
        {
            right = mid;
        }
    }
    cout << "Not Found!" << endl;
    return -1;

}
