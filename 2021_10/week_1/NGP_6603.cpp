/*
������������ �־����ϱ� ���� �̸� sort�� �ʿ� ����.. 

�׳� ��� ����Ǽ��� Ž���ϸ� �Ǵ°Ŵ�..
���̰� 6�� �����Ѵٸ� ����� �ϰ� �ǰ�
���� 1 2 3 4 5 6 7 8 9 ���
1���� �����Ҥ� ��ͷ� �� ���ڸ� �� �̾Ƴ��� �������� ���ٰ� �����ϸ� ���Ұ��̴�.

������ ����Ž�� ������ Ǯ�ٰ� ������ prev_permutation(arr,arr+k)�� �ص� ������ ������ ����.
*/


#include<iostream>

using namespace std;
int k;
int arr[13];
int ans[6];
void choose_num(int num1, int num2);


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	
	while (1) {
		cin >> k;
		if (k == 0)
			break;

		for(int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		choose_num(0, 0);
		cout << "\n";
	}
	return 0;
}

void choose_num(int tmp, int length) {
	if (length == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = tmp; i < k; i++) {
		ans[length] = arr[i];
		choose_num(i + 1, length + 1);
	}
}