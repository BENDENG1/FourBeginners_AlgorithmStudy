#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T, n;
int DP[200002][2];
int sticker[200002][2];

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> sticker[i][0];
		for (int i = 0; i < n; i++)
			cin >> sticker[i][1];

		DP[0][0] = sticker[0][0];
		DP[0][1] = sticker[0][1];

		for (int i = 1; i < n; i++)
		{
			DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + sticker[i][0]); 
			DP[i][1] = max(DP[i - 1][1], DP[i - 1][0] + sticker[i][1]);
			/* ������ �밢���� �� vs ���������� �������� �ʰ�
			���� ������ ���� ���� ��ƼĿ�� ������ ��� �� �ִ밪�� ���� �ȴ�.
			*/
		}

		cout << max(DP[n - 1][0], DP[n - 1][1]) << '\n';
		//1���� 2���� ��𿡼� ���۵Ȱ��� �� ū��?

	}

}