/*��ü ���� ���տ��� ���� S�� �Ǵ°͸� ���� ����������?
�ϳ� �� ���� "����� ũ�Ⱑ ����� �κм��� �߿���" */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, S;//N��, ��S
    cin >> N >> S;
    vector <int> num(N);

    int i, j, k;

    for (i = 0; i < N; i++)//�����Է�
        cin >> num[i];

    vector <int> comb;//������ �迭

    int temp, result = 0;
    for (i = 1; i <= N; i++) {//������ ����
        comb.clear();

        for (j = 1; j <= i; j++)
            comb.push_back(1); //�κм����� ũ�⸸ŭ 1
        for (k = N - j; k >= 0; k--)
            comb.push_back(0); //�̿�

        do {
            temp = 0;//�ӽð� �ʱ�ȭ
            for (int l = 0; l < N; l++) {
                if (comb[l] == 1)//�ش� �� ��츸 ���ϱ�
                    temp += num[l];
            }
            if (temp == S)//�� ���� ���� S���
                result++;//����
        } while (prev_permutation(comb.begin(), comb.end()));//������ ���� ��������
    }
    cout << result;
}

