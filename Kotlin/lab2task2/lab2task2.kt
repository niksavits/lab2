import java.util.Scanner

fun main() {
    // Создаем сканнер для ввода данных
    val scanner = Scanner(System.`in`)

    // Запрашиваем количество элементов у пользователя
    print("Введите количество элементов: ")
    val n = scanner.nextInt()

    // Создаем список для хранения чисел
    val nums = mutableListOf<Int>()

    // Запрашиваем числа у пользователя
    println("Введите числа:")
    repeat(n) {
        val num = scanner.nextInt()
        nums.add(num)
    }

    // Переменная для подсчета чисел с нечетным количеством цифр
    var count = 0

    // Проходим по каждому числу в списке
    for (num in nums) {
        var digitCount = 0
        var temp = num

        // Подсчитываем количество цифр в числе
        while (temp != 0) {
            temp /= 10
            digitCount++
        }

        // Если количество цифр нечетное, увеличиваем счетчик
        if (digitCount % 2 != 0) {
            count++
        }
    }

    // Выводим количество чисел с нечетным количеством цифр
    println("Количество чисел с нечетным количеством цифр: $count")
}
