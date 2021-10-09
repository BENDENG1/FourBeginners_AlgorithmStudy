#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1234;
    while (cin >> n && n != 0) {   //0�� �ƴҶ����� ���� �ִ´�.
        vector<int> num(n);

        for (int i = 0; i < n; i++)
            cin >> num[i];
        //���� �迭�� �Է�
        vector<bool> comb(n, false);

        for (int i = 0; i < 6; i++)
            comb[i] = true;
        //6����  ���� �迭�� true �� 

        do {
            for (int i = 0; i < n; i++)
                if (comb[i]) //6���� �����Ѵ�.
                    cout << num[i] << ' ';
            cout << '\n';
        } while (prev_permutation(comb.begin(), comb.end()));
        cout << '\n';
    }
    return 0;
}