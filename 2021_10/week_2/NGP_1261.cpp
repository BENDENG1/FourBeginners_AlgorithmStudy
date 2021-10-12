/*
bfs�� Ǯ�� ������ �����ε� �ʹ�.
�ٸ� ���⼭ ���� �ִٸ� ī��Ʈ���ϰ� ���� ���ٸ� ī��Ʈ�� ���ϸ� ���� ������?
��.. �ּڰ��� �����Ѵٴ°��� ������Ȥ�� �Ʒ��� �������� ���� +1�� �ǰԵȴ�.
�츮�� �ᱹ (m-1,n-1)�� ��ǥ�� �����ϱ� �����̴�.
�� �ٵ� �ݷʸ� �׷��ôµ� �װ� �ƴѵ� �׳� bfs�� ��� ���� �����Ҷ� �ϴ°� ������?

�� �׷��ϱ� ��� ��θ� Ž���ϴµ� �������� ���ڰ� ���ٸ� ��� ���� �����ϸ� ���� ������?
�̰Ŵ� �׳� �������� ũ�� ���Ž�Ű�� �Ǵ¹���..!

*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int value[101][101];
void bfs(int a, int b);
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
			value[i][j] = 111111111;
		}
	}

	bfs(0, 0);
	printf("%d", value[n - 1][m - 1]);

}

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	value[a][b] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//if (y == n - 1 && x == m - 1) continue; //break�� �ƴ϶� continue�� �̳��! ->�׸��� ���� �̰� ������ ������ �� bfs�� ������ �˾Ƽ� ��Ż�ϴµ�!!

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			
			if (arr[ny][nx] == 0) {
				if (value[ny][nx] > value[y][x]) {
					value[ny][nx] = value[y][x];
					q.push({ ny,nx });
				}
			}
			else {
				if (value[ny][nx] > value[y][x] + 1) {
					value[ny][nx] = value[y][x] + 1;
					q.push({ ny,nx });
				}
			}

		}

	}

}