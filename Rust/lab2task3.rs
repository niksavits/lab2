use std::io::{self, BufRead};

fn main() {
    // Создаем вектор для хранения перевернутых чисел
    let mut nums: Vec<i32> = Vec::new();

    // Запрашиваем количество чисел, которое пользователь хочет ввести
    println!("Введите количество символов: ");
    let mut input = String::new();
    io::stdin().lock().read_line(&mut input).expect("Ошибка при считывании строки");

    // Удаляем пробелы из вводимой строки
    let input = input.replace(" ", "");

    // Преобразуем введенное значение в число
    let n: i32 = input.trim().parse().expect("Ошибка при преобразовании числа");

    // Проверяем, что введено корректное количество символов
    if n <= 0 {
        println!("Ошибка: введено некорректное количество символов.");
        return; // Завершаем программу
    }

    // Ввод и обработка каждого элемента
    for _ in 0..n {
        println!("Элемент: ");
        let mut input_elem = String::new();
        io::stdin().lock().read_line(&mut input_elem).expect("Ошибка при считывании строки");

        // Преобразуем введенный элемент в число
        let elem: i32 = input_elem.trim().parse().expect("Ошибка при преобразовании числа");

        let mut rev_elem = 0;
        // Переворачиваем число
        let mut num = elem;
        while num > 0 {
            rev_elem = rev_elem * 10 + num % 10;
            num = num / 10;
        }
        
        nums.push(rev_elem); // Добавляем перевернутое число в вектор
    }

    // Выводим перевернутые числа
    for elem in nums {
        print!("{} ", elem);
    }
}
