#include<iostream>
#include<cmath>
//int arr[1100000][2] ���� ���ͷ� �ָ��� �ϴ°� �� ���ҵ� ->�׳� ���� 2^n-1�ΰ� �˰Եȴٸ� �Ѵ� �ʿ���µ�.
using namespace std;
void hanoi(int n, int start, int mid, int end);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int k;
	cin >> k;
	int move = pow(2, k) - 1;
	cout << move << "\n";
	hanoi(k, 1, 2, 3);
}

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		cout << start << " "<<end<< "\n"; //�׸����� �׷ȵ��� ������ �Ѱ��϶� �ű�ΰ�
	}
	else {
		hanoi(n - 1, start, end, mid); //��� 2��
		cout << start << " " << end << "\n"; //�ű涧���� ���
		hanoi(n - 1, mid, start, end); //��� 3����
	}
}