#include<iostream>

using namespace std;

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	int arr[10];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		while (k / arr[i]) {
			count += k / arr[i];         //���ϰ� ���� ���� ������ ���� �ִ밪���� ������ ī��Ʈ ��
			k %= arr[i];                //���� �������� ��ȯ
		}
	}
	cout << count << endl;
	return 0;
}