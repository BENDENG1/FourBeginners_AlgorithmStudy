#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100002];
int correct[100001]; //��Ʈ�� 1�� �θ� �����ϰ� ���� �ڽĵ���� ���� �θ����� ����. ��, ������ ��.
bool visited[100002];

void dfs(int a); //a�� Ʈ���� ��Ʈ�� 1�� �ɰ� ����

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); // �ð� �ٿ��ֱ� ���ؼ� ��
    int n, a, b;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << correct[i] << "\n";
    }

    return 0;
}

void dfs(int a) {
    visited[a] = true;
    for (int i = 0; i < tree[a].size(); i++) {
        int node = tree[a][i];
        if (!visited[node]) {
            correct[node] = a;
            dfs(node);
        }
    }
}