import java.util.Scanner
import java.util.ArrayList

fun main() {
    // Создаем объект Scanner для ввода с консоли
    val input = Scanner(System.`in`)
    // Создаем список для хранения обратных чисел
    val nums = ArrayList<Int>()

    // Запрашиваем количество чисел у пользователя
    print("Введите количество чисел: ")
    // Считываем количество чисел
    val n = input.nextInt()

    // Цикл для ввода чисел и вычисления обратных чисел
    for (i in 0 until n) {
        // Запрашиваем у пользователя ввод числа
        print("Число $i: ")
        // Считываем введенное число
        var elem = input.nextInt()
        // Переменная для хранения обратного числа
        var revElem = 0

        // Цикл для вычисления обратного числа
        while (elem > 0) {
            revElem = revElem * 10 + elem % 10
            elem /= 10
        }

        // Добавляем обратное число в список
        nums.add(revElem)
    }

    // Выводим обратные числа
    for (elem in nums) {
        print("$elem ")
    }

}
