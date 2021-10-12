/*
������ �����ϴ�.
��� ���� Ž���ϴ� ����� ä���ߴ�. (�θ�Ʈ~~)
ù�����϶� �ι�° ���ҵ��̻��� ���յ��� ��� ���� ���ؼ� ť�� �����Ѵ�.
�ι�°�϶��� ����° �̻��� ���ҵ���� ���յ�� ť�� ����
->���⼭ �ߺ��� �Ǹ� �ȵǹǷ� ��¥����.
�׷��� ������ ������ �� find ��� �Լ����� q�� �ϳ��� ��������鼭 ���ڰ� �ִ��� Ȯ��.
������ ó���� 0�̶�� 0�� push�ǹǷ� 0�ϰ�쿡�� ans-1�� ���� �ƴҰ�쿡�� ans ���
*/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, s, ans = 0;
int arr[20];
void add(int tmp, int num);
void find(int num);
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	add(0,0);
	find(0);

	return 0;
}

void add(int tmp,int num) {
	q.push(num);

	for (int i = tmp; i < n; i++) {
		add(i+1,num+arr[i]);
	}
}

void find(int num) {
	while (!q.empty()) {
		if (q.front() == s)
			ans++;
		q.pop();
	}
	if (s == 0)
		cout << ans - 1;
	else
		cout << ans;
}