#include <iostream>
#include <cstdlib>
#include "ChessMath.h" // Подключаем наш заголовочный файл с ООП-классом

using namespace std;

// Функция main теперь принимает аргументы командной строки
// argc - количество переданных параметров, argv - массив строк (сами значения)
int main(int argc, char* argv[]) {
    int KingX, KingY, RookX, RookY, BishopX, BishopY;

    // Если пользователь передал 6 координат при запуске (плюс 1 аргумент - имя программы, итого 7)
    if (argc == 7) {
        // Конвертируем строки (char*) в числа (int) с помощью встроенной функции atoi
        KingX = atoi(argv[1]);
        KingY = atoi(argv[2]);
        RookX = atoi(argv[3]);
        RookY = atoi(argv[4]);
        BishopX = atoi(argv[5]);
        BishopY = atoi(argv[6]);
        cout << "Координаты загружены из аргументов командной строки." << endl;
    } else {
        // Если программу просто запустили двойным кликом или без параметров, просим ввести вручную
        cout << "Введите координаты белого короля (X Y): ";
        cin >> KingX >> KingY;
        cout << "Введите координаты черной ладьи (X Y): ";
        cin >> RookX >> RookY;
        cout << "Введите координаты черного слона (X Y): ";
        cin >> BishopX >> BishopY;
    }

    // Лямбда-выражение для удобной проверки диапазона шахматной доски (от 1 до 8)
    auto isValid = [](int c) { return c >= 1 && c <= 8; };
    if (!isValid(KingX) || !isValid(KingY) || !isValid(RookX) || 
        !isValid(RookY) || !isValid(BishopX) || !isValid(BishopY)) {
        cout << "Ошибка: координаты должны быть от 1 до 8." << endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    // Обращаемся к нашей библиотеке (математическому классу). 
    // Поскольку методы объявлены как static, нам не нужно создавать экземпляр (писать new ChessMath).
    int result = ChessMath::checkThreats(KingX, KingY, RookX, RookY, BishopX, BishopY);

    // Анализируем числовой ответ от библиотеки и выдаем результат
    if (result == 3) {
        cout << "Угроза от обеих фигур" << endl;
    } else if (result == 1) {
        cout << "Угроза от ладьи" << endl;
    } else if (result == 2) {
        cout << "Угроза от слона" << endl;
    } else {
        cout << "Король в безопасности" << endl;
    }

    return 0; // Успешное завершение
}
