#include "zadania.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    std::cout << "����� ������� ���������� ��������? 1 ��� 2: ";
    int x;
    std::cin >> x;

    if (x == 1) {
        zadanie1(argc, argv);
    }
    else if (x == 2) {
        zadanie2(argc, argv);
    }
    else {
        std::cout << "������ ������������ ����� �������!" << std::endl;
        return 1;
    }
    return 0;
}