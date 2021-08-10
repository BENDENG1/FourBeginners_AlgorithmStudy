#include <iostream>
#include <algorithm>
using namespace std;
int DP[10001];
int a[10001];

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) cin >> a[i];

	DP[0] = a[0];
	DP[1] = a[1] + a[0];
	DP[2] = max(a[0] + a[1], a[0] + a[2]);
	DP[2] = max(DP[2], a[1] + a[2]);



	for (int i = 3; i < T; i++) {
		DP[i] = max(DP[i - 2] + a[i], DP[i - 3] + a[i - 1] + a[i]);

		DP[i] = max(DP[i - 1], DP[i]);
		
	}//DP3�� ��� �������� ������
	//1���� DP 3�� ������ ���ô°��, VS 1���� 2���� ���ô°�� 
	//�������� 3�� ������ ���ô°��

	cout << DP[T-1] << '\n';
}
