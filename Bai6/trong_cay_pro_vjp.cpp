#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 100000;
int a[MAX];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n, greater<int>());

    for (int i = 0; i < n; ++i) {
        a[i] -= n - i - 1;

        if (a[i] < 0) // Tránh trường hợp đầu vào 1 1 1 1 chẳng hạn
            a[i] = 0;
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << ' ';
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
