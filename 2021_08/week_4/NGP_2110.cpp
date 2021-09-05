#include<iostream>
#include<algorithm>
using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }
int home[200001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, c;
    long long  low = 1, high = 0, mid, dis = 0, point;
    int ans = 0;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> home[i];
        high = get_max(high, home[i]);
    }
    sort(home, home + n+1); //1���� �����ε� SORT(N+1) +1�� ���ؼ� 5���̳� Ʋ���ٴ�.
    
    while (low <= high) {
        mid = (low + high) / 2;
        int cnt = 1;
        point = home[1];

        //����Ʈ�� �������� ���� ������ ��ġ�ϴµ� ���࿡ 2��Ž������ �Ÿ��� �ָ� cnt++�� ���ش�.
        for (int i = 2; i <= n; i++) {
            dis = home[i] - point;
            if (mid <= dis) {
                cnt++;
                point = home[i];
            }
        }

        //���ڰ� ���ų� ���ٸ� low=mid+1
        if (cnt >= c) {
            ans = mid;
            low = mid + 1;
        }//���ٸ� high=mid-1
        else {
            high = mid - 1;
        }

    }
    cout << ans;
}