/*
��� �Լ��� ���ڰ� ä������ ��, ���ڰ� ä�������� 81�̻��̸� �Լ��� ��Ż�Ͽ� �����Ѵ�.
1. �࿡�� ���ڰ� �� �ٸ��� �Ǻ�
2. ������ ���ڰ� �� �ٸ��� �Ǻ�
3. 3*3�簢������ ���ڵ��� �� �ٸ��� �Ǻ�.
���� �������� �����ϸ� ���ڸ� ���Խ�Ű�� cnt==81�� �ȴٸ� ���ᰡ �ȴ�.
��� �Լ��� ��ġ�� 1,2,3���� ��� Ȯ������ �־��ش�.
�ᱹ 1,2,3�� ���ڰ� ��ġ�°��� ���°� �Ǻ��� �ȴٸ� ���� dfs(cnt+1)�� ��ͷ� �������ش�.

��[��][������]
��[��][�ప��]
�簢��[�簢�� ����][����]

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[10][10];
bool row[10][10]; //�� ���߱�
bool col[10][10]; //�� ���߱�
bool square[10][10]; //3*3 ���簢�� ���߱�
void dfs(int cnt);


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (arr[y][x] != 0)
		dfs(cnt + 1);
	else {
		for (int i = 1; i <= 9; i++) { //���� �ڽľ� ���⼭ ���ڰ� 1~9�ε� �� i=0���� �ϳ�.. ����������.
			if (row[y][i] == false && col[x][i] == false && square[(y/3)*3+(x/3)][i] == false) {
				row[y][i] = true;
				col[x][i] = true;
				square[(y / 3) * 3 + (x / 3)][i] = true;
				arr[y][x] = i;
				dfs(cnt + 1);
				arr[y][x] = 0;
				row[y][i] = false;
				col[x][i] = false;
				square[(y / 3) * 3 + (x / 3)][i] = false;

			}
		}
	}

}