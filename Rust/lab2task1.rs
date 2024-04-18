use std::io::{self, BufRead}; // Подключаем необходимые модули

fn main() {
    // Создаем строку с гласными буквами
    let vowels = "aeiou";

    // Ввод строки от пользователя без пробелов
    println!("Введите строку:");

    let mut input_string = String::new(); // Создаем переменную для хранения введенной строки
    io::stdin().lock().read_line(&mut input_string).expect("Ошибка при считывании строки");
    input_string.retain(|c| c != ' ' && c != '\n'); // Удаляем пробелы и символы перевода строк

    let mut quantityGlas = 0; // Переменная для хранения количества гласных букв

    // Подсчет количества гласных букв и согласных букв в строке
    for c in input_string.chars() {
        if c.is_alphabetic() { // Проверка, является ли символ буквой
            for v in vowels.chars() {
                // Проверяем, является ли символ гласной буквой
                if c.to_ascii_lowercase() == v {
                    quantityGlas += 1; // Увеличиваем количество гласных букв
                    break; // Прерываем цикл поиска гласных букв
                }
            }
        } else {
            println!("Некорректный ввод!"); // Выводим ошибку при вводе не буквенных символов
            return; // Прекращаем выполнение программы
        }
    }

    let quantitySoglas= input_string.len() - quantityGlas; // Вычисляем количество согласных букв

    // Сравниваем количество гласных и согласных букв и выводим результат
    if quantityGlas > 0 {
        if quantityGlas > quantitySoglas {
            println!("Да");
        } else if quantityGlas == quantitySoglas {
            println!("Одинаково");
        } else {
            println!("Нет");
        }
    }
}
