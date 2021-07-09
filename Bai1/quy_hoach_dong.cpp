// Dãy con ở đây là dãy liên tiếp
#include <iostream>
using namespace std;

const int MAX = 100;

/* Bảng phương án có dạng như sau
		0    1    2  3  4   5   <- j
		-2   11  -4 13  -5  2
		_______________________
0	-2	|-2  9*  5* 18  13  15
1	11	|0   11  7  20 15  17
2	-4	|0   0  -4  9   4   6
3	13	|0   0   0  13  8   10
4	-5	|0   0   0  0  -5  -3
5	2	|0   0   0  0   0   2

i
*/



int main() {
    int s[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(s) / sizeof(s[0]);

    int a[MAX][MAX] = {0};

    // Lập bảng phương án
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                a[i][j] = s[i];		// Tức là phần tử trên đường chéo chính của bảng phương án lần lượt được gán bằng -2, 11, -4, 13, -5, 2
            } else if (j > i) {		// Nếu j > i giả sử ở 9* thì 9 là kết quả của -2 + 11, (-2 ở bên trái 9) và (11 ở trên đường chéo chính bên dưới 9) tức là tổng dãy con {-2, 11} là 9
                a[i][j] = a[i][j - 1] + s[j]; // Tương tự ở 5* thì 5 cũng là kết quả của 9 + (-4), (9 ở bên trái 5 và -4 ở đường chéo chính)
            }
        }
    }

    int tongMax = INT_MIN;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i][j] > tongMax) {
                tongMax = a[i][j];
                start = i;
                end = j;
            }
        }
    }

    cout << "Day con co tong lon nhat bang " << tongMax << " la: ";
    for (int i = start; i <= end; ++i) {
        cout << s[i] << "; ";
    }

    return 0;
}