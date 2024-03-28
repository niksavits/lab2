#include <iostream>
#include <vector>
using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
vector <int> nums;
int n;
cout << "Введите количество символов: ";
cin >> n;
for (int i = 0; i < n; i++) {
    int elem;
    cout << "Элемент: ";
    cin >> elem;
    int revElem = 0;
    while (elem > 0) {
        revElem = revElem * 10 + elem % 10;
        elem = elem / 10;
    }
    nums.push_back(revElem);
}
    for (auto elems : nums) {
    cout << elems << " ";
    }
return 0;
}
