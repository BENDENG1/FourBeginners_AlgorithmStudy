#include<iostream>
using namespace std;
int d[1001][10];//���� 1~100 �ڴ� 0~9
int main() {
	int n, j, i, ans;
	cin >> n;


	for (i = 0; i < 10; i++) {
		d[1][i] = 1;//����� 0�� ���� 0~9 ��ΰ���
	}
	for (int i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			ans = 0;
			for (int k = j; k>= 0; k--) {
				ans += d[i - 1][k] % 10007; //�������̹Ƿ� 0~j������ ����� �� ��
			}
			d[i][j] = ans % 10007;
		}
		
	}
	ans = 0;
	for (i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	cout << ans%10007;
	return 0;
}