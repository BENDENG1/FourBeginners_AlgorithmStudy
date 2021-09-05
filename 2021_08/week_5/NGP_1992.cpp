#include<iostream>
using namespace std;

int arr[64][64];
//bool issame(int size, int y, int x);
void Quadtree(int size, int y, int x);
int n,ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s; //�������� 1111111' ' �̷��� �����ֳ�
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
			//scanf_s("%1d",&arr[i][j]);
		}
	}
	Quadtree(n, 0, 0);

}

void Quadtree(int size, int y, int x) {
	ans = arr[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] != ans) { //�ٸ��� �� ���� ��и����� ���� �� //2,1,4,3�и� ����
				cout << "(";
				Quadtree(size / 2, y, x);
				Quadtree(size / 2, y, x + size / 2);
				Quadtree(size / 2, y + size / 2, x);
				Quadtree(size / 2, y + size / 2, x + size / 2);
				cout << ")";
				return;
			}
		}
	}
	//���������� �������
	cout << ans;
}


/*
bool issame(int size, int y, int x) {
	for (int i = 0; i < y+size; i++) {
		for (int j = 0; j < x+size; j++) {
			if (arr[y][x] != arr[i][j])
				return false;
		}
	}
	return true;
}

void Quadtree(int size, int y, int x) {
	if (size == 1) {
		cout << arr[y][x];
		return;
	}
	
	if (issame(size, y, x)) {
		cout << arr[y][x];
		return;
	}else {
		cout << "(";
		//2,1,4,3�и��
		Quadtree(size / 2, y, x);
		Quadtree(size / 2, y, x + size / 2);
		Quadtree(size / 2, y + size / 2, x);
		Quadtree(size / 2, y + size / 2, x + size / 2);
		cout << ")";
	}
}
*/