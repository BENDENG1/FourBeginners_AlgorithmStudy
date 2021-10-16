/*
�� �������� 1208���� ������ ���� �����ߴ�
���࿡ 4000����� 4000^4=>������ ū ���ڸ� �ʷ��ϰ� �ȴ�.
�̷��ٿ��� �׳� ����a,b���̶� ������ c,d�鳢�� ���� ���س��� �������ؼ� ���� �Ѵٸ�
(4000^2)*(4000^2)�̹Ƿ� �� �پ���� ������ �ʹ�.
�׸��� ab�� ���������� �����ϰ� cd�� ū������ ������ �ϰ� �����ϸ� �� ������ �����ҵ�?

�׷��� ���� 0�ϰ�쿡�� abnum�� �÷����Ѵ�.
�ű⼭ ���࿡ ���� �����ϰ��� ��� ������ �ؼ� �������� ã�´�.
�̰Ŵ� ab���� cd�� �׷��� �ؼ� abtmp*cdtmp�� ans���� ��� �����ش�.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long arr[4000][4];
long long ans = 0;
vector<int> ab, cd;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(arr[i][0] + arr[j][1]);
			cd.push_back(arr[i][2] + arr[j][3]);
		}
	}
	
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	

	int abnum = 0;
	int cdnum = n * n - 1;
	int sumsize = n * n;

	while (abnum < sumsize && cdnum >= 0) {
		int sum = ab[abnum] + cd[cdnum];

		if (sum == 0) {
			int abnext = ab[abnum++];
			int cdnext = cd[cdnum--];
			long long abtmp = 1; //���� 4000���� �� ������ �����͵� ������ long long
			long long cdtmp = 1;

			while (ab[abnum] == abnext && abnum < sumsize) {
				abtmp++;
				abnum++;
			}
			while (cd[cdnum] == cdnext && cdnum >= 0) {
				cdtmp++;
				cdnum--;
			}
			ans += (abtmp * cdtmp);
		}
		else if (sum > 0) {
			cdnum--;
		}
		else { 
			abnum++;
		}
	}

	cout << ans;


}