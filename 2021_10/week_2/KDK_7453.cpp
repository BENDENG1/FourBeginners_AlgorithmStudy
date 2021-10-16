#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long ans;
int A[4000];
int B[4000];
int C[4000];
int D[4000];
int arr1[4000 * 4000];
int arr2[4000 * 4000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i]>>C[i]>>D[i];

	//�迭�� 2���� ���δ�.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr1[n * i + j] = A[i] + B[j];
			arr2[n * i + j] = C[i] + D[j];
		}
	//�̺�Ž���� ���� ����
	sort(arr1, arr1 + n * n);
	sort(arr2, arr2 + n * n);
	
	//�̺�Ž���� �����ؼ� ������ ����. ���ڼ��°� ������ó��
	for (int i = 0; i < n * n; i++) {
		ans += upper_bound(arr2, arr2 + n * n, -arr1[i]) - lower_bound(arr2, arr2 + n * n, -arr1[i]);
	}

	cout << ans;
	return 0;
}