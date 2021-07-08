// https://www.spoj.com/PTIT/problems/PTIT127C/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10000;

struct CongViec {
    CongViec() {}

    CongViec(int s, int f) {
        this->s = s;
        this->f = f;
    }

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

    int demMax = 0;
    vector<CongViec> result;

    for (int i = 0; i < n; ++i) {
        int bd = cv[i].s;
        int kt = cv[i].f;
        int dem = 1;
        vector<CongViec> temp;
        temp.push_back(CongViec(bd, kt));

        for (int j = i + 1; j < n; ++j) {
            if (cv[j].s >= kt) {
                bd = cv[j].s;
                kt = cv[j].f;
                ++dem;

                temp.push_back(CongViec(bd, kt));
            }
        }

        if (dem > demMax) {
            demMax = dem;
            result = temp;
        }
    }

    cout << "\nDanh sach cong viec:\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result.at(i).s << ' ' << result.at(i).f << endl;
    }

    cout << "\nTong so cong viec: " << demMax;
    return 0;
}