//ȿ�������� ��� ����
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].size()))
                answer = false;
        }
    }

    return answer;
}


/*
�ٸ� ������� �ڵ带 �����ߴ�.
string�̱� ������ ������ ������ ��� ���������� ������ �ȴٴ� ���̴�.
���������� ������ �ǹǷ� ���� ���Ҹ� �񱳸� �ϸ� �ȴٴ� ���̴�.
*/


#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            answer = false;
    }

    return answer;
}