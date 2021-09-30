/*[0][0] ~ [0][9] ���� 1~9 ���ڰ� ������  �࿡�� �ݺ�
[0][0] ~[9][0] ���� 1~9 ���ڰ� ������ ������ �ݺ�
[3n][3n] ~[n + 2][n + 2] ���� 1~9 ���ڰ� ������ ��.0 <= n < 3 �������� �ݺ�*/

#include<iostream>
#include<vector>
using namespace std;
int sudoku[9][9];
int cnt = 0; //ä������ ���� ����.0�ǰ���
bool check = false;
vector<pair<int, int>>v;
bool numcheck(int c, int d) {
	int target = sudoku[c][d];

	for (int i = 0; i < 9; i++) {
		if (target == sudoku[c][i] && i != d) return false;//�࿡�� �ݺ�?
		if (target == sudoku[i][d] && i != c) return false;//������ �ݺ�?
	}
	int p = c / 3;
	int q = d / 3;
	for (int i = p * 3; i < p * 3 + 3; i++) {
		for (int j = q * 3; j < q * 3 + 3; j++) {
			if (target == sudoku[i][j] && i != c && j != d) return false;
		}
	}//�������� �ݺ�
	return true;
}
void find(int t) {
	if (check) return; //������� �ִٸ�?
	if (t == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		check = true;
		return;
	}

	//1~9 ���� ������
	for (int i = 1; i <= 9; i++) {
		//����
		auto a = v[t];
		int x = a.first;
		int y = a.second;
		//�����ϱ�

		sudoku[x][y] = i;
		if (numcheck(x, y)) {
			find(t + 1);
		}
		sudoku[x][y] = 0;
	}
	return;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				v.push_back({ i,j });
				cnt++;
			}
		}
	}//�Է��ϱ�
	find(0);
}
