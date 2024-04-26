#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string glasnye = "yaoeiu";
    cout << "������� ������: ";
    string s;
    char c;
    cin.get(c);

    while (c != '\n') {
        if (isalpha(c)) {
            s += c;
        }
        cin.get(c);
    }

    // ���������, ��� ��������� ������ �� ������
    if (s.size() == 0) {
        cout << "������!" << endl;
        return 1; // ���������� ��������� ���, ����� ������� �� ������
    }

    int quantityGlas = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < glasnye.size(); j++) {
            if (tolower(s[i]) == glasnye[j]) {
                quantityGlas++;
            }
        }
    }

    int soglas = s.size() - quantityGlas;

    if (quantityGlas > soglas) {
        cout << "��";
    } else if (quantityGlas == soglas) {
        cout << "���������";
    } else {
        cout << "���";
    }

    return 0;
}
