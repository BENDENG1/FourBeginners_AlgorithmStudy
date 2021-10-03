/*
�̹����� �׳� ������ �Ѱ��̻� ������ �ΰ��̻��϶� ��ͷ� ��Ÿ���� ���ϴ�.
������ Ž���ϸ鼭 ���ĵ� ������ �迭���� ��¸��ϸ� �Ǵ°��̶�� �����Ѵ�
���� ���ǿ��� ������ �Ѱ��� �ִٸ� ���� �����ǿ��� ������ �����ϰ� �ַ��..
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int l, c;
char arr[16];
string str;
void dfs(int pos, string str, int con, int vow);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);

	dfs(0, "", 0, 0);

}

void dfs(int pos,string str,int con, int vow) {
	if (str.size() == l) {
		if (con >= 1 && vow >= 2)
			cout << str << "\n";
		return;
	}
	for (int i = pos; i < c; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			dfs(i + 1, str + arr[i], con + 1, vow);
		}
		else
			dfs(i + 1, str + arr[i], con, vow + 1);
	}
}
