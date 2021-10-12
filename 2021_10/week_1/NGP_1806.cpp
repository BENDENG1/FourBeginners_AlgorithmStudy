/*
��, �ּҰ��� ���ϸ� �Ǵ°��̱� ������ �������� �����ߴ�.
while���� �̿��ؼ� ���ʺ��� �������� ���� ������ �������� �迭�� +1�� �������ν� ���� �ø���
�� ��Ȳ���� ���� s�� ���� ���� �ѱ�Եȴٸ� ���ʰ��� ��ĭ �������� ���� �����ش�.
��, ��� s�� ���� �ѱ�� ��Ȳ�� �ּҰ��� ��� �����ְ� �ȴ�.
*/

#include<iostream>
#include<algorithm>
using namespace std;
int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int left = 0, right = 0;
	int sum = arr[0];
	int len = n + 1;


	while (left <= right && right < n) {
		if (sum < s) {
			right += 1;
			sum += arr[right];
		}
		else if (sum >= s) {
			len = min(len, right - left + 1);
			sum -= arr[left];
			left += 1;
		}
	}

	if (len == n + 1)
		cout << '0';
	else
		cout << len;

	return 0;
}

