#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int main() {
    int d[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int L;
    cin >> L;

    sort(d, d + n);

    int b1[MAX], b2[MAX];
    int b1L, b2L;
    b1L = b2L = L;
    int h = 0;
    int k = 0;

    for (int i = 0; i < n; ++i) {
        if (b1L - d[i] >= 0 && i % 2 == 0) { // Thêm những chương trình có i chia hết cho 2 vào b1
            b1[h] = d[i];
            ++h;

            b1L -= d[i];
        } else if (b2L - d[i] >= 0 && i % 2 != 0) { // Thêm những chương trình có i không chia hết cho 2 vào b2
            b2[k] = d[i];
            ++k;

            b2L -= d[i];
        } else { // Không thể thêm chương trình nào vào cả 2 băng nhớ => break luôn
            break;
        }
    }

    for (int i = 0; i < h; ++i) {
        cout << b1[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < k; ++i) {
        cout << b2[i] << ' ';
    }

    cout << "\nTong so chuong trinh luu tru duoc la: " << h + k;
    return 0;
}