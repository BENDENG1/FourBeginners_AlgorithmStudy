#include<iostream>
using namespace std;

int paper[2200][2200];
int minuse = 0;
int zero = 0;
int one = 0;

void func(int x, int y, int size) {
	int check = paper[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check == 0 && paper[i][j] != 0)
				check = 2;
			else if (check == 1 && paper[i][j] != 1)
				check = 2;
			else if (check == -1 && paper[i][j] != -1)
				check = 2;//for���� ���� 0 -1 1�� ���� Ȯ���ϰ� ��ġ�ϴ� ��찡 �ƴ϶�� üũ�� 2��
			if (check == 2) {
				func(x, y, size / 3);

				func(x + size / 3, y, size / 3);
				func(x + size * 2 / 3, y, size / 3);

				func(x, y + size / 3, size / 3);
				func(x + size / 3, y + size / 3, size / 3);
				func(x + size * 2 / 3, y + size / 3, size / 3);

				func(x, y + size * 2 / 3, size / 3);
				func(x + size / 3, y + size * 2 / 3, size / 3);
				func(x + size * 2 / 3, y + size * 2 / 3, size / 3);

				9���� ���� Ȯ��
				return;
			}
		}

	}
	if (check == 0)
		zero++;
	else if (check == 1)
		one++;
	else if (check == -1)
		minuse++;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}
	func(0, 0, n);

	cout << minuse << endl;
	cout << zero << endl;
	cout << one << endl;
	return 0;
}