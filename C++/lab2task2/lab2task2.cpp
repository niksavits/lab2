#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> nums;

    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

    // ���������, ��� ��������� ���������� ��������� ��������������� �����
    if (n <= 0) {
        cout << "������: ������� ������������ ���������� ���������." << endl;
        return 1; // ���������� ��������� ���, ����� ������� �� ������
    }

    cout << "������� �����: " << endl;;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int j = 0;
    for (auto num : nums) {
        int digitCount = 0;
        int temp = num;

        // ������������ ���������� ���� � �����
        while (temp != 0) {
            temp /= 10;
            digitCount++;
        }

        // ���� ���������� ���� ��������, ����������� �������
        if (digitCount % 2 != 0) {
            j++;
        }
    }

    cout << "���������� ����� � �������� ����������� ����: " << j << endl;

    return 0;
}
