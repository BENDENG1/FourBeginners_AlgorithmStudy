#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int n(0);
int cnt(0);
int seq[100001];
int main() {
	stack<int>s;
	vector<char> ans;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> seq[i];
	
	
	for (int i = 1; i <= n; i++) {
		s.push(i);
		ans.push_back('+');

		//������ ������� �ʰ�,cnt��° ������ ������ ������ ���Ұ� �������
		while (!s.empty() && s.top() == seq[cnt]) {
			s.pop();
			ans.push_back('-');
			cnt++;
		}
	}

	if 
		(!s.empty()) cout << "NO";//������ ��������ٸ� ���Ͱ� ����־�� �Ѵ�.
	else 
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
}