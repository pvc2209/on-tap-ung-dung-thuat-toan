// https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
#include <iostream>
using namespace std;

int max(int a, int b, int c) { return max(max(a, b), c); }

int dayConMaxGiua(int a[], int l, int m, int r) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = m; i >= l; --i) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = m + 1; i <= r; ++i) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return max(leftSum + rightSum, leftSum, rightSum);
}

int dayConMax(int a[], int l, int r) {
    // Trường hợp mảng chỉ có 1 phần tử
    if (l == r) {
        return a[l];
    }

    int m = (l + r) / 2;

    return max(dayConMax(a, 1, m), dayConMax(a, m + 1, r),
               dayConMaxGiua(a, l, m, r));
}

int main() {
    int a[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(a) / sizeof(a[0]);

    cout << dayConMax(a, 0, n - 1);

    return 0;
}
