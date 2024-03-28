#include <iostream>
#include <vector>
using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
string glasnye = "yaoeiu";
cout << "Введите строку: ";
string s;
char c;
cin.get(c);
while (c != '\n') {
    if (c != ' ') {
        s += c;
    }
    cin.get(c);
}

int quantityGlas = 0;

for (int i = 0; i < s.size(); i++) {
    for ( int j = 0; j < glasnye.size(); j++) {
        if (s[i] == glasnye[j]) {
            quantityGlas++;
        }
    }
}
int soglas = s.size() - quantityGlas;
if (quantityGlas > soglas) {
    cout << "Да";
} else if (quantityGlas == soglas) {
    cout << "Одинаково";
} else {
    cout << "Нет";
}
return 0;
}
