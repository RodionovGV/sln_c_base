/*
& // ����������� �
| // ����������� ���
^ // ����������� ����������� ���
<< // ����� �����
>> // ����� ������

[��������](https://graphics.stanford.edu/~seander/bithacks.html)

*/
#include <iostream>
#include <cstdint>

#include <limits>

int main()
{
    std::cout << "Start work 2025.10.28!\n";
    uint32_t reg_value = 0x18805E010; // ��������� ����� �� ��������
    uint32_t mask = 0;

    // ��������� ����
    int bit_to_set = 4; // ����� ����, ������� ����� ����������
    mask = 1 << bit_to_set; // ������� �����, ���������� ������� � ������ ����
    reg_value |= mask; // ���������� ������ ��� � �����
    std::cout <<"0x" << std::hex << reg_value << "\n";

    // ������ ����
    int bit_to_clear = 4; // ����� ����, ������� ����� �����
    mask = ~(1 << bit_to_clear); // ������� ��������������� �����, ���������� ���� � ������ ����
    reg_value &= mask; // ����� ������ ��� � �����
    std::cout << "0x" << std::hex << reg_value <<"\n";
}

