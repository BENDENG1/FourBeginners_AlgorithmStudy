#include <iostream>
#include <map>
#include <string>
#include <ctype.h> //���Ĺ��ΰ���?

using namespace std;
map<string, int> m1;
map<int, string> m2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m1.insert(make_pair(s, i)); 
		m2.insert(make_pair(i, s));
	}
	for (int i = 1; i <= m; i++) {
		cin >> s;
		if (isalpha(s[0])) { //���ĺ����� Ȯ���ϴ� ��
			cout << m1[s] << '\n';
		}//�� ���
		else {
			cout << m2[stoi(s)] << '\n';
		} //��Ʈ�� �Լ��� 
	}
}