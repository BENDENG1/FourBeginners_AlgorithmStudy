#include<iostream>

using namespace std;

int main() {
    int n, m, k, count = 0;
    cin >> n >> m >> k;

    while (1) {
        if (k <= (n - 2 + m - 1) && n >= 2 && m >= 1) {           //������ ���� �� �ִ� ���ڰ� �����ְ� k�� ���� 1���̶� ���� �� �� �ִ°� ���� �۴ٸ�.
            n -= 2;
            m -= 1;
            count++;
        }
        else break;
    }

    cout << count << endl;
    return 0;
}