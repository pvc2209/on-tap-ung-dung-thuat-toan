// https://vnoi.info/wiki/algo/dp/basic-problems.md#3-bi%E1%BA%BFn-%C4%91%E1%BB%95i-x%C3%A2u

// https://www.spoj.com/HVT/problems/CHANGEST/

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

int timMin(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {
    string x, y;
    cin >> x >> y;

    int a[MAX][MAX];
    int n = x.length();
    int m = y.length();

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                a[0][j] = j;
            } else if (j == 0) {
                a[i][0] = i;
            } else if (x[i - 1] == y[j - 1]) {
                a[i][j] = a[i - 1][j - 1];
            } else if (x[i - 1] != y[j - 1]) {
                a[i][j] = timMin(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]) + 1;
            }
        }
    }

    cout << "\nBang truy vet:\n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nSo thao tac nho nhat la: " << a[n][m] << endl;

    // Truy vết - càng code càng bug :))
    int i = n;
    int j = m;
    vector<string> steps;
    for (int k = 1; k <= a[n][m]; ++k) {
        char s1 = x[i - 1];
        char s2 = y[j - 1];
        if (x[i - 1] == y[j - 1]) {
            // Nếu 2 ký tự giống nhau thì đi chéo lên và không làm gì cả
            // vì khi lập bảng truy vết ở trên khi 2 ký tự giống nhau
            // ta cũng chỉ gán a[i][j] = a[i - 1][j - 1] nên giờ đi ngược lại
            i = i - 1;
            j = j - 1;

            --k; // đi chéo lên không được tính là 1 bước nên --k
        } else {

            string type;
            if (j == 0) {
                // Khi j bằng 0 ta chỉ việc xóa các ký tự còn lại
                type = "Xoa";
            } else if (i == 0) {
				// Khi i bằng 0 ta chỉ việc chèn các ký tự còn lại
                type = "Chen";
            } else {
                // Thứ tự ưu tiên là Xóa, Chèn, Thay thế nên ở if ta dùng <=
                // Cần đặt thứ tự ưu tiên vì truy truy vết lên có thể a[][] tại
                // 3 vị trí xóa, chèn, thay thế bằng nhau
                // => Cần chọn cái hợp lý nhất

                // Tại sao lại như vậy???
                // VD1: cần chuyển abc -> ab
                // => Xóa c

                // VD2: cần chuyển ab -> abc
                // nếu a[][] tại chèn và thay thế bằng nhau
                // thì ta hoàn toàn có thể chọn thay thế ở đây
                // ab' ' thay thế ' ' thành c
                // => Không hợp lý phải ko...
                // Hợp lý nhất là chèn c vào cuối
                // => Chèn có độ ưu tiên cao hơn thay thế

                type = "Thay the";

                int min = a[i - 1][j - 1];

                if (a[i][j - 1] <= min) {
                    min = a[i][j - 1];
                    type = "Chen";
                }

                if (a[i - 1][j] <= min) {
                    min = a[i - 1][j];
                    type = "Xoa";
                }
            }

            if (type == "Xoa") {
                steps.push_back(type + " " + x[i - 1] + "\n");
                // cout << type << " " << x[i - 1] << endl;
                i = i - 1;
            } else if (type == "Chen") {
                steps.push_back(type + " " + y[j - 1] + "\n");
                // cout << type << " " << y[j - 1] << endl;
                j = j - 1;
            } else if (type == "Thay the") {
                steps.push_back(type + " " + x[i - 1] + " = " + y[j - 1] + "\n");

                // cout << type << " " << x[i - 1] << " = " << y[j - 1] << endl;

                i = i - 1;
                j = j - 1;
            }
        }
    }

    for (int i = steps.size() - 1; i >= 0; --i) {
        cout << steps.at(i);
    }

    return 0;
}