//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//vector <pair<int, int>> vec[10001];
//bool visit[10001] = { false, };
//int dist = 0;
//int endNode;
//
//void dfs(int start, int cost) {
//    if (visit[start]) return;
//    visit[start] = true;
//
//    if (dist < cost) {
//        dist = cost;
//        endNode = start;
//    }
//
//    for (int i = 0; i < vec[start].size(); i++) {
//        dfs(vec[start][i].first, cost + vec[start][i].second);
//    }
//}
//
//int main() {
//	int y = 0, x = 0;
//	int current_node = 0;
//	int linked_node = 0;
//	int num = 0;
//	int first = 0;
//
//	cin >> V;
//	visit = vector<bool>(V + 1, 0);
//
//	for (y = 1; y <= V; ++y) {
//		cin >> current_node;
//		while (1) {
//			cin >> linked_node;
//			if (linked_node == -1) break;
//			cin >> num;
//			tree[current_node].push_back({ linked_node,num });
//		}
//		if (tree[current_node].size() == 1) first = current_node;
//	}
//    dfs(1, 0);
//    dist = 0;
//    memset(visit, false, sizeof(visit));
//    //������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�,
//    //�θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�
//    dfs(endNode, 0);
//
//    cout << dist << endl;
//}


