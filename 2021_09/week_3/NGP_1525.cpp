#include<iostream>
#include<queue>
#include<string>
#include<set>
using namespace std;

//��������
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int ans = -1;
string start;
void bfs(string start);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int num = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0)
				tmp = 9;
			num = num * 10 + tmp;
		}
	}
	start = to_string(num);
	bfs(start);


}

void bfs(string start) {
	queue<pair<string,int>> q;
	set<string> visit; //�̰� �����ض�
	q.push({ start,0 });

	while (!q.empty()) {
		string s = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (s == "123456789") {
			cout << cnt;
			exit(0);
		}
			

		int place = s.find('9');
		int y = place / 3;
		int x = place % 3;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
				string tmp = s;

				//�̷��Ե� �����ϱ���.. swap
				swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
				if (visit.find(tmp) == visit.end()) {  //����
					q.push({ tmp,cnt + 1 });
					visit.insert(tmp); //����
				}
			}
		}


	}
	cout << -1;
}