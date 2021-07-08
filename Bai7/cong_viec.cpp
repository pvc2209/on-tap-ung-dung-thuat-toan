#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;

struct CongViec {
    int s;
    int f;
};

bool compare(CongViec a, CongViec b) {
    return a.f < b.f;
}

CongViec cv[MAX];
int n;

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cv[i].s >> cv[i].f;
    }

    sort(cv, cv + n, compare);

    // for (int i = 0; i < n; ++i) {
    //     cout << cv[i].s << ' ' << cv[i].f << endl;
    // }

    int demMax = 0;
    for (int i = 0; i < n; ++i) {
        int bd = cv[i].s;
        int kt = cv[i].f;
        int dem = 1;

        for (int j = i + 1; j < n; ++j) {
            if (cv[j].s >= kt) {
                bd = cv[j].s;
                kt = cv[j].f;
                ++dem;
            }
        }

        if (dem > demMax) {
            demMax = dem;
        }
    }

    cout << demMax;
    return 0;
}