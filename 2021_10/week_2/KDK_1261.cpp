#include <iostream>
#include <deque>
using namespace std;

int n, m;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int maze[101][101];	 //�̷� ����
int visit[101][101]; //�湮 Ȯ�� �� ���� �ν� Ƚ��

deque<pair<int, int>> q;


void bfs() {
	visit[0][0] = 0;
	q.push_back(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == -1) {
					//���� ���� ���� ���̸� ���� �ν� �ʿ� �����Ƿ�
					//���� ��ǥ�� visit���� ���� ��ǥ�� visit���� ����
					if (maze[nx][ny] == 0) {
						visit[nx][ny] = visit[x][y];
						q.push_front(make_pair(nx, ny));
					}
					//���� ���� �ִ� ���̸� ���� �μž� �ϹǷ�
					//���� ��ǥ�� visit���� ���� ��ǥ�� visit�� + 1
					else {
						visit[nx][ny] = visit[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp - 48;
			visit[i][j] = -1;
		}
	}    //�̷ο� ���� ������ �Է�

	bfs();

	cout << visit[n - 1][m - 1] << "\n";
}
