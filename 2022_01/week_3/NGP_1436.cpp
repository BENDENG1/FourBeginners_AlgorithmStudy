/*
10�� �����鼭 1���ڸ����� ������ �����ϴ� ���·� �����ϸ� ������?
ex)666�̸� �׳� ��� 6661�����Ÿ� 10���� ������ 666�� �ȴ�.
���� �����Ѵٸ� 111666111�� ������ ������ ������ ��ġ�� ������ 1000�� ������ 666�̶�� ���ڰ� ������ �ȴٸ� �ٽ� ���� while���� ������ �Ǵ°�.

*/
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);


	int n;
	cin >> n;

	int cnt = 0, ans = 0, tmp;
	while (cnt != n) {
		ans++;
		tmp = ans;
		while (tmp != 0) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				tmp = tmp / 10;
			}
		}
	}

	cout << ans;

	return 0;
}