
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	// 1.���� �ϳ��� �ݵ�� ����
	// 2.������ 3�� Ȥ�� ������ 3�� �������� ���� �ȵȴ�.
	// 3. ���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee�� oo�� ����Ѵ�.

	while (1) {
		//vowel ���� constant ���� ans->������ �����ϴ���
		int vowel = 0, constant = 0,  ans = 0;
		string s;
		cin >> s;

		if (s == "end") break;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') { //�����ϰ��
				ans = 1;
				vowel++;
				constant=0;
			}
			else {  //�����ϰ��
				vowel = 0;
				constant++;
			}

			if (vowel == 3 || constant == 3) {
				ans = 0;
				break;
			}

			if (i < s.length() - 1) {
				if (s[i] == 'e' && s[i + 1] == 'e')
					continue;
				else if (s[i] == 'o' && s[i + 1] == 'o')
					continue;
				else if(s[i] == s[i + 1]) {
					ans = 0;
					break;
				}
			}
		}

		if (ans == 1)
			cout << "<" << s << ">" << " is acceptable.\n";
		else
			cout << "<" << s << ">" << " is not acceptable.\n";

	}
}



