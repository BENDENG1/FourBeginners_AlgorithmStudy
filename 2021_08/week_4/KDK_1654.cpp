//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//
//using namespace std;
//
//long long arr[10001];
//
//long long cnt = 0;
//long long k, n, high, low = 1, middle = 0, result = 0;
//
//
//int main() {
//	cin >> k >> n;
//
//	for (int i = 0; i < k; i++) {
//		cin >> arr[i];
//		high = max(high, arr[i]);
//	}
//	while (low <= high) {
//		result = 0;
//		middle = (low + high) / 2;                       //�߾Ӱ� ����� 1+high �� ��
//
//		for (int i = 0; i < k; i++)
//			result += arr[i] / middle;                   //�Է¹��� ���� �߾Ӱ����� ������.
//
//		if (result >= n) {                              //���� ��� ���� ������ �������� ���ٸ�
//			low = middle + 1;                          //���� ���� ���� �߾Ӱ��� ����
//			if (middle > cnt) {                        // cnt ���� �̵麸�� ũ�� (0���� ũ��?)
//				cnt = middle;                         //ī��Ʈ�� ��!
//			}
//		}
//		else {
//			high = middle - 1;                       //�׿��� ����� �߾Ӱ��� �ְ��� �ȴ�.
//		}
//
//	}                                                  //low ���� high ���� �ɋ����� �ݺ�
//	        
//	cout << cnt << endl;
//
//	return 0;
//}