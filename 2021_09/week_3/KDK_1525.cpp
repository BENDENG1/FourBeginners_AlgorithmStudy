using namespace std;
#include <stdio.h>
#include <iostream> 
#include <string>
#include <queue>
#include <map>


int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
map<int, int> v;

int bfs(int first) {
	queue<int> q;

	//���� ����(�̵���)
	q.push(first);
	v[first] = 0;

	while (!q.empty()) {


		int now = q.front();
		q.pop();

		//bfs�̹Ƿ� ���� ���� ���� �ּҹ湮ī��Ʈ ���̴�.
		if (now == 123456789) {
			//map���ҿ� �迭ó�� ���� ����!
			return v[now];
		}

		//���� map�� �������¸� ���ڿ��� ��ȯ�Ͽ� 9�� ��ǥ ã�Ƴ���
		string now_str = to_string(now);
		int now_index = now_str.find('9');
		int r = now_index / 3;
		int c = now_index % 3;


		//4���� Ž��
		for (int d = 0; d < 4; d++) {
			//���ο� ��ǥ ���ϱ�
			int nr = r + dx[d];
			int nc = c + dy[d];
			int new_index = nr * 3 + nc;


			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 3)continue;

			//���ο� ��ǥ�� ���� ���ο� map���ϱ�
			//���� 9��ǥ <-> ���ο� 9��ǥ
			string new_str = now_str;
			char tmp = new_str[new_index];
			new_str[new_index] = new_str[now_index];
			new_str[now_index] = tmp;


			int new_int = atoi(new_str.c_str());
			//��ã������=�湮��������
			if (v.find(new_int) == v.end()) {
				//�湮�ϱ�
				v[new_int] = v[now] + 1;
				q.push(new_int);
			}



		}
	}
	return -1;
}

int main() {


	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int first = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 0)tmp = 9;
			first = (first * 10) + tmp; //�ڸ����� �ϳ� �ø��� 1�� �ڸ��� �ش� ���ڰ� �ö󰡰�
			//123456789�� ���°� �ǵ�����
			//1 = > 12 = > 123= > 1234

		}
	}
	cout << bfs(first);





	return 0;

}
