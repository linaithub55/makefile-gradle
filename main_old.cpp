#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для проверки, находится ли значение val строго между a и b
bool isBetween(int val, int a, int b) {
    return val > min(a, b) && val < max(a, b);
}

int main() {
    int KingX, KingY, RookX, RookY, BishopX, BishopY;

    cout << "Введите координаты белого короля (X Y): ";
    cin >> KingX >> KingY;
    cout << "Введите координаты черной ладьи (X Y): ";
    cin >> RookX >> RookY;
    cout << "Введите координаты черного слона (X Y): ";
    cin >> BishopX >> BishopY;

    // Валидация координат
    auto isValid = [](int c) { return c >= 1 && c <= 8; };
    if (!isValid(KingX) || !isValid(KingY) || !isValid(RookX) || 
        !isValid(RookY) || !isValid(BishopX) || !isValid(BishopY)) {
        cout << "Ошибка: координаты должны быть от 1 до 8." << endl;
        return 1;
    }

    // 1. Базовые угрозы (без учета перекрытий)
    bool baseThreatRook = (KingX == RookX) || (KingY == RookY);
    bool baseThreatBishop = (abs(KingX - BishopX) == abs(KingY - BishopY));

    // 2. Проверка блокировки ладьи слоном
    bool rookBlocked = false;
    if (baseThreatRook) {
        if (KingX == RookX && BishopX == KingX) {
            rookBlocked = isBetween(BishopY, KingY, RookY);
        } else if (KingY == RookY && BishopY == KingY) {
            rookBlocked = isBetween(BishopX, KingX, RookX);
        }
    }

    // 3. Проверка блокировки слона ладьей
    bool bishopBlocked = false;
    if (baseThreatBishop) {
        bool rookOnSameDiagonal = (abs(KingX - RookX) == abs(KingY - RookY));
        if (rookOnSameDiagonal) {
            bishopBlocked = isBetween(RookX, KingX, BishopX) && isBetween(RookY, KingY, BishopY);
        }
    }

    // 4. Итоговые угрозы
    bool actualThreatRook = baseThreatRook && !rookBlocked;
    bool actualThreatBishop = baseThreatBishop && !bishopBlocked;

    // 5. Вывод результата
    if (actualThreatRook && actualThreatBishop) {
        cout << "Угроза от обеих фигур" << endl;
    } else if (actualThreatRook) {
        cout << "Угроза от ладьи" << endl;
    } else if (actualThreatBishop) {
        cout << "Угроза от слона" << endl;
    } else {
        cout << "Король в безопасности" << endl;
    }

    return 0;
}
