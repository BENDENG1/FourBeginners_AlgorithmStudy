#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	//�̰� ��������. �Է°��� �޾����� �ʾƼ� ������ ��ġ�� ���ʹ�. 
	//cin.ignore(�о���� ���� ����, �����Ҷ� �Է��� ����) -> ���� �˰Ե�. ��������
	cin.ignore();

	for (int tmp = 0; tmp < t; tmp++) {
		
		string s;
		getline(cin, s);
		pair<int, char> alpha[26] = { {0,' '} };

		//��ĭ�� ������ ���� �׷��� ���� �������� ��� �޾ƾ���
		//abcde/fghij/klmno/pqrst/uvwxy/z ->26��
		//�׳� �ϴ°ͺ��� pair�� ��� ���߿� ���� ���� ���ڰ� � �������� check ->ó���� �̷��� ���ؼ� �ָ���
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ')continue;
			alpha[s[i] - 'a'] = { alpha[s[i]-'a'].first + 1, s[i] };
		}
		sort(alpha, alpha + 26, cmp);

		if (alpha[0].first == alpha[1].first) {
			cout << "?" << "\n";
		}
		else {
			cout << alpha[0].second << "\n";
		}
	}

}
