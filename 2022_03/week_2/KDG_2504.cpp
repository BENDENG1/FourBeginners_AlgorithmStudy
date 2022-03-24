#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	stack<char> st;

	int temp(1);
	int result(0);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			temp *= 2;
			st.push('(');
		}//(�� ��� *2 �ϰ� st���� '(' push
		else if (s[i] == '[') {
			temp *= 3;
			st.push('[');
		}//'['�ϰ�� *3 �ϰ� st���� '[' push
		else if (s[i] == ')') {
			if (st.empty() || (st.top() != '(')) {
				cout << 0 << '\n';
				return 0;
			}//���� ��ȣ�� ���Դµ� ��� �ְų� ������ '('�� �ȳ��������

			if (s[i - 1] == '(') {
				result += temp;
			}//������ �ٷ� '('�ϰ�� ���簪�� ������ �ϱ����� �ӽð��� �ִ´�. ex) (())

			temp /= 2;
			st.pop();//�� ���� *2�� �̸� ���������Ƿ� �����ش�. 
		}
		else if (s[i] == ']') {
			if (st.empty() || (st.top() != '[')) {
				cout << 0 << '\n';
				return 0;
			}

			if (s[i - 1] == '[') {
				result += temp;
			}

			temp /= 3;
			st.pop();
		}
	}

	if (!st.empty())
		result = 0;
	cout << result << endl;
}