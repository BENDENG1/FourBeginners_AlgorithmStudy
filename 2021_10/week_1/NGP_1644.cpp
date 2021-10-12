/*
ó���� �Ҽ����ϴ°��� �ϳ��ϸ� ���� �ϳ�... �̷��� �ߴ��ϸ� �ð��ʰ��� ����.
�����佺�׳׽��� ü��� ���ϴ°��� �ִ��. �̰� ��������.

get_prime�� �Լ��� ���� �ʹ� ���ư���. ����.

*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> prime;
vector<bool> tf;
void get_prime(int num);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	tf.resize(n + 1, true);
	get_prime(n);

	int start = 0, end = 0, sum = 0, ans = 0;
	
	while (1) {
		if (sum >= n) {
			sum -= prime[start];
			start++;
		}
		else if (end == prime.size()) break;
		else {
			sum += prime[end];
			end++;
		}

		if (sum == n) ans++;
	}

	cout << ans;
	
	return 0;
}



void get_prime(int tmp) {

	for (int i = 2; i * i <= tmp; i++) {
		if (tf[i] == false) continue;
		for (int j = i + i; j <= tmp; j += i) {
			tf[j] = false;
		}
	}
	
	for (int i = 2; i <= tmp; i++) {
		if (tf[i]==true) 
			prime.push_back(i);
	}

}