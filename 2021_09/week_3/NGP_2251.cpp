#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void bfs(int x, int y, int z);
vector<int> ans;
bool visited[200][200];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	//memset(visited, 0, sizeof(visited)); -> ���������� ���ʿ� bool �Լ����� false�� �ʱ�ȭ�ϴ� ������ �̰͵� �ʿ��Ҷ��� ����.

	bfs(a, b, c);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}


void bfs(int x, int y, int z) {
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0, 0),z));

	while (!q.empty()) {
		int first = q.front().first.first;
		int second = q.front().first.second;
		int third = q.front().second;
		q.pop();

		//1963���� �����ߴ� continue�� ���°� ���ϴ°� ������� Ȱ��.
		if (visited[first][second]==true)continue;
		visited[first][second] = true;

		if (first == 0) 
			ans.push_back(third);
		
		//���� �ð� �����̰� bfs�ð� ���̱�� ������ ���� �ɰ� �����ϴ°��� �� �����ٴ� ���� �����ؼ� �����غ���.
		//1)a->b 2)b->a 3)a->c 4)c->a 5)b->c 6)c->b�� �������� ��Ȳ�� ���� Ŭ���� �������� �����ؼ� 12������ ������ �ɵ�ʹ�.
		
		//1)
		if (first + second > y)
			q.push(make_pair(make_pair(first + second - y, y), third));
		else
			q.push(make_pair(make_pair(0, first + second), third));

		//2)
		if (first + second > x)
			q.push(make_pair(make_pair(x, first + second - x), third));
		else
			q.push(make_pair(make_pair(first + second, 0), third));

		//3)
		if (first + third > z)
			q.push(make_pair(make_pair(first + third - z, second), z));
		else
			q.push(make_pair(make_pair(0, second), first + third));

		//4)
		if (first + third > x)
			q.push(make_pair(make_pair(x, second), first + third - x));
		else
			q.push(make_pair(make_pair(first + third, second), 0));

		//5)
		if (second + third > z)
			q.push(make_pair(make_pair(first, second + third - z), z));
		else
			q.push(make_pair(make_pair(first, 0), second + third));

		//6)
		if (second + third > y)
			q.push(make_pair(make_pair(first, y), second + third - y));
		else
			q.push(make_pair(make_pair(first, second + third), 0));

	}
}
