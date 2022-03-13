#include <iostream>
#include <queue>
#include<deque>

using namespace std;
int main() {
	int N;
	cin >> N;
	deque<pair<int, int>> dq1; //ǳ����ȣ,���� ����

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		dq1.push_back({ i,x }); //1~N��
	}

	while (!dq1.empty()) {
		auto num = dq1.front(); // ��ȣ
		cout << num.first << ' ';
		int now = num.second; // ���� ����
		dq1.pop_front();//��Ʈ����

		if (now > 0) {//����̸�
			now--;
			while (!now ==0) {
				dq1.push_back(dq1.front());
				dq1.pop_front();
				now--;
			}//��Ʈ������ ���� ������ �ٲٴ°Ŵϱ�
		}
		else {//�������̸�
			while (!now == 0) {
				dq1.push_front(dq1.back());
				dq1.pop_back();
				now++;
			}
		}
	}
}