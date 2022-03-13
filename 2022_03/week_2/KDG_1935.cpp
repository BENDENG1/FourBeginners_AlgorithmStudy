#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	//���� �� ��
	string stack;
	cin >> stack;
	//string ���ڹ迭�� �Է¹���
	vector<int> number(n);
	vector<double>result;

	char temp;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	} //�������� n�� ũ�⸸ŭ �Է¹���

	for (int i = 0; i < stack.size(); i++) {
		temp = stack[i];
		
		if (temp >= 'A' && temp <= 'Z') {
			result.push_back(number[temp - 'A']);
		}//�Է¹������� ���Ĺ� �빮�ڶ�� number�� �������� �����ؼ� result �Լ��� �ִ´�.
		else {
			double a, b;
			b = result.back();
			result.pop_back();
			a = result.back();
			result.pop_back();

			switch (temp) {
			case '+':
				result.push_back(a + b);
				break;
			case '-':
				result.push_back(a - b);
				break;
			case '*':
				result.push_back(a * b);
				break;
			case '/':
				result.push_back(a / b);
				break;
			}
		}
	}
	cout << setprecision(2) << fixed << result.back(); //�Ҽ� �ι�°����

}