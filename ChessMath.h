#ifndef CHESSMATH_H
#define CHESSMATH_H

// Класс ChessMath инкапсулирует (скрывает) в себе всю математическую логику 
// для работы с шахматными координатами, реализуя принципы ООП.
class ChessMath {
public:
    // Вспомогательный метод. Проверяет, находится ли значение val строго между a и b.
    // Это нужно для того, чтобы понять, стоит ли одна фигура между двумя другими на одной линии.
    static bool isBetween(int val, int a, int b);
    
    // Главный метод логики. Принимает координаты трех фигур.
    // Возвращает числовой код: 0 - безопасности, 1 - угроза от ладьи, 2 - от слона, 3 - от обеих.
    static int checkThreats(int KingX, int KingY, int RookX, int RookY, int BishopX, int BishopY);
};

#endif
