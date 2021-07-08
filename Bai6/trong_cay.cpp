#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 100;
int a[MAX];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                swap(a[i], a[j]);
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << ' ';
    // }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            if (a[j] > 0)
                --a[j];
        }
    }

    // for (int i = 0; i < n - 1; ++i) {
    //     if (a[i] > 0)
    //         --a[i];
    // }

    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    cout << max + n + 1;

    return 0;
}
