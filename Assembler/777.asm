%include "io64.inc"

section .data
nums:    times 255 dw 0             ; Буфер для чисел
n:       equ $ - nums

section .bss
input_num resw 1                    ; Буфер для одного вводимого числа

section .text
global main
main:
    mov rbp, rsp                    ; for correct debugging

    ; Инициализация индекса и количества элементов
    xor rsi, rsi                    ; индекс для доступа к nums обнуляем перед использованием
    ; Считываем количество элементов в массиве   
    mov rdi, input_num
    GET_DEC 8, input_num
    NEWLINE
    
    movzx rcx, word [input_num]     ; количество элементов для ввода
    push rcx                        ; сохраняем количество элементов в массиве - для дальнейших вычислений

input_loop:
    mov rdi, input_num              ; адрес буфера для ввода числа
    call GET_DEC 8, input_num       ; ввод числа
    movzx rax, word [input_num]     ; загружаем введенное число
    mov [nums + rsi], ax            ; сохраняем число в массив
    add rsi, 2                      ; следующий индекс в массиве
    dec rcx                         ; уменьшаем счетчик
    jnz input_loop                  ; переходим в начало цикла, если rcx не равно 0
    ; Обработка чисел из массива
    xor rsi, rsi                    ; сброс индекса для обработки массива
    xor rbp, rbp                    ; счетчик чисел с нечетным количеством цифр
    pop rcx                         ; восстанавливаем количество элементов в мвссиве  

numsloop:
    movzx rax, word [nums + rsi]    ; Загружаем число из массива
    xor rdi, rdi                    ; Обнуляем счетчик цифр в числе

    test rax, rax
    jz zero_digit                   ; если число равно нулю, обрабатываем особо

nnn:
    inc rdi
    mov edx, 0                      ; обнуляем rdx перед делением, так как div использует dx:ax
    mov bx, 10
    div bx                          ; rax = rax / 10, rdx = rax % 10
    test rax, rax
    jne nnn                         ; продолжаем, пока не обработаем все цифры

zero_digit:
    test rdi, 1                     ; проверяем, нечетное ли количество цифр
    jz Chet                         ; если четное, переходим к Chet
    inc rbp                         ; инкрементируем счетчик нечетных чисел
Chet:
    add rsi, 2                      ; перемещаемся к следующему элементу массива
    loop numsloop                   ; продолжаем цикл по массиву

    ; Вывод результата
    mov rdi, rbp                    ; Подготавливаем значение для вывода
    NEWLINE
    PRINT_DEC 8, rdi                ; Выводим результат
    ret
