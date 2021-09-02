#include<iostream>
using namespace std;
int   have[10001];


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int k, n, cnt;
    long long low = 1, mid, ans = 0, high = 0;//���⼭ high�� �־��� ���߿� ���� ū ���� �ǹ��Ѵ�.
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> have[i];
        if (have[i] > high)
            high = have[i];
    }

    while (low <= high) {
        mid = (low + high) / 2;
        cnt = 0;
        for (int i = 1; i <= k; i++) {
            cnt += (have[i] / mid);
        }

        if (cnt >= n) {
            low = mid + 1;
            if (mid > ans)
                ans = mid;
        }
        else
            high = mid - 1;
    }
    cout << ans;


}

//20200822 ���� 1654��