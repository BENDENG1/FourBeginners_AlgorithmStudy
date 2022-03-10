/*
2���� �迭�� �����ϸ� ���࿡  ù��° i�� �ι�° j�� ���ٸ� ���� ������ +1���ϸ鼭 
dp�� ���·� �����Ͽ� ���� �� ���� ��� �����ϰ� �ȴٸ� ���� ������?

*/

#include<iostream>
#include<string>

using namespace std;
int get_max(int a, int b) { if (a > b)return a; else return b; }
int dp[4001][4001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string one, two;

	cin >> one;
	cin >> two;
	int ans = 0;
	
	

	for (int i = 0; i < one.length(); i++) {
		for (int j = 0; j < two.length(); j++) {
			if (one[i] == two[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = get_max(ans, dp[i + 1][j + 1]);
			}
		}
	}


	cout << ans;
}