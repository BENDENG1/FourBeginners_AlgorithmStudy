#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int nums[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };

	string s;
	cin >> s;
	int sum = 0;
	
	for (int i = 0; i < s.length(); i++) {
		int tmp = nums[s[i] - 'A'];
		v.push_back(tmp);
	}
	
	//�̰� �ᱹ���� �׳� �����ڵ鳢�� �ٴ��ϴ°� �ƴѰ�?
	//�����׸��� 10�� �������� �׳� ��� 10�� ������ ���ָ� �Ǵµ�
	for (int i = 0; i < s.length(); i++) {
		sum += v[i];
		sum %= 10;
	}

	if (sum % 2 == 0) {
		cout << "You're the winner?";
	}
	else
		cout << "I'm a winner!";

	
}