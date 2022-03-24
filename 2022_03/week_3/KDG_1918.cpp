#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, result;
	stack<char> stack;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			result += str[i];
			continue;
		} //A~Z�� �Է�
		if (str[i] == '(') {
			stack.push(str[i]);
			continue;
		} // ��ȣ ���°� �����? �ϴ� push
		if (str[i] == ')') {
			while (stack.top() != '(') {
				result += stack.top();
				stack.pop();
			}
			stack.pop();
			continue;
		}//�ݴµ�, ���� ���� stack ���� '('�� �ƴҰ�� ���信 ���� stack top�� �ְ� pop �ؼ� ã�´�
		if (str[i] == '*' || str[i] == '/') {
			while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
				result += stack.top(), stack.pop();
		}// '*'�� '/'�� ���������� ��¼�� ���� ��� �Ѵ�.
		else {
			while (!stack.empty() && stack.top() != '(')
				result += stack.top(), stack.pop();
		} // '+'�� '-'�� ��ȣ�� ���� ��� �״���
		stack.push(str[i]);
	}

	while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	}
	cout << result << "\n";
	return 0;
}