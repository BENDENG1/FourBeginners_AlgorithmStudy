#include<iostream>
using namespace std;

int main() {
	int number;
	int sum = 0;
	char a;

	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> a;
		sum += a - 48; //Ȥ�� '0'���ε� ���� ����? ����
	}
	cout << sum << endl;
}