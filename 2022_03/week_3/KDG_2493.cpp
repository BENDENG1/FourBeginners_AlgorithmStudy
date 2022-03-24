#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, height;
	stack<pair<int, int>> sta;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> height;
		while (!sta.empty()) { //���� �ִٸ�?
			if (sta.top().second > height) {
				cout << sta.top().first << ' ';
				break;
			}//�ٷ� ������ ���
			sta.pop();
		}//�ƴϸ� �ݺ�
		if (sta.empty()) {
			cout << "0 ";
		}//���鰪 �� ������ ���� ���� ��� 0���� ���
		sta.push({ i,height });//���Ŀ� �ٽ� �� ����
	}
}