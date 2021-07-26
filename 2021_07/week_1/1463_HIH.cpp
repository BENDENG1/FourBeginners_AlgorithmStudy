#include <iostream>
using namespace std;


int minimum(int x, int y) {
	if (x > y) return y;
	else return x;
}

int main(void) {
	int* DP_Array = new int[1000000];
	int value;

	cin >> value;

	DP_Array[0] = DP_Array[1] = 0;

	for (int i = 2; i <= value; i++) {
		DP_Array[i] = DP_Array[i - 1] + 1; // ���� -1�� ���

		if (i % 2 == 0) { // ���� /2 �� ���
			DP_Array[i]=minimum(DP_Array[i], DP_Array[i / 2] + 1);
		}

		if (i % 3 == 0) { // ���� /3�� ���
			DP_Array[i]=minimum(DP_Array[i], DP_Array[i / 3] + 1);
		}

		//cout << "i= " << i << "  value= "<< DP_Array[i] << endl;
	}
	cout << DP_Array[value] << endl;
	delete DP_Array;

}