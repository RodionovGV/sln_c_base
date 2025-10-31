/*
& // поразрядное И
| // поразрядное ИЛИ
^ // поразрядное исключающее ИЛИ
<< // сдвиг влево
>> // сдвиг вправо

[Источник](https://graphics.stanford.edu/~seander/bithacks.html)

*/
#include <iostream>
#include <cstdint>

#include <limits>

int main()
{
    std::cout << "Start work 2025.10.28!\n";
    uint32_t reg_value = 0x18805E010; // Прочитать слово из регистра
    uint32_t mask = 0;

    // Установка бита
    int bit_to_set = 4; // Номер бита, который нужно установить
    mask = 1 << bit_to_set; // Создать маску, содержащую единицу в нужном бите
    reg_value |= mask; // Установить нужный бит в слове
    std::cout <<"0x" << std::hex << reg_value << "\n";

    // Снятие бита
    int bit_to_clear = 4; // Номер бита, который нужно снять
    mask = ~(1 << bit_to_clear); // Создать инвертированную маску, содержащую ноль в нужном бите
    reg_value &= mask; // Снять нужный бит в слове
    std::cout << "0x" << std::hex << reg_value <<"\n";
}

