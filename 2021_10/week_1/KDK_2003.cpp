#include <iostream>
#include <vector>
using namespace std;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;


	int arr[10001];
	int sum(0);
	int result(0);
	int start(0);
	int end(0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	while (end <= N) {
		if (sum >= M)
			sum -= arr[start++]; //sum >=M���� ũ�ų� ������ �� ������ START������ �ϳ� ���ϱ�
		else if (sum < M)
			sum += arr[end++];//������ �ڿ� ������ END ���ڸ����� �ϳ� ���ϱ�
		if (sum == M)
			result++;
	}
	cout << result;
}
//2��������