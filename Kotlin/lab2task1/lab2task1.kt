fun main() {
    println("Введите строку: ")
    val s = readLine()!!.filter { it != ' ' }
    val glasnye = "yaoeiu"
    var quantityGlas = 0

    for (char in s) {
        if (char in glasnye) {
            quantityGlas++
        }
    }

    val soglas = s.length - quantityGlas
    when {
        quantityGlas > soglas -> println("Да")
        quantityGlas == soglas -> println("Одинаково")
        else -> println("Нет")
    }
}
