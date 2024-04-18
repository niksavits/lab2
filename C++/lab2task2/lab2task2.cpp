#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> nums;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    // Проверяем, что введенное количество элементов неотрицательное число
    if (n <= 0) {
        cout << "Ошибка: введено некорректное количество элементов." << endl;
        return 1; // Возвращаем ненулевой код, чтобы указать на ошибку
    }

    cout << "Введите числа: " << endl;;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int j = 0;
    for (auto num : nums) {
        int digitCount = 0;
        int temp = num;

        // Подсчитываем количество цифр в числе
        while (temp != 0) {
            temp /= 10;
            digitCount++;
        }

        // Если количество цифр нечетное, увеличиваем счетчик
        if (digitCount % 2 != 0) {
            j++;
        }
    }

    cout << "Количество чисел с нечетным количеством цифр: " << j << endl;

    return 0;
}
