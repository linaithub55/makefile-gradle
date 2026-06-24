#include "ChessMath.h"
#include <cmath>
#include <algorithm>

using namespace std;

// Реализация вспомогательного метода. 
// Мы используем функции min и max, чтобы не зависеть от порядка чисел.
// Например, ладья может стоять на Y=8, а король на Y=1. Или наоборот.
bool ChessMath::isBetween(int val, int a, int b) {
    return val > min(a, b) && val < max(a, b);
}

// Реализация основной математической модели (расчет угроз)
int ChessMath::checkThreats(int KingX, int KingY, int RookX, int RookY, int BishopX, int BishopY) {
    // 1. БАЗОВЫЕ УГРОЗЫ (предполагаем, что доска пустая)
    // Ладья бьет по вертикали (совпадает X) или горизонтали (совпадает Y)
    bool baseThreatRook = (KingX == RookX) || (KingY == RookY);
    // Слон бьет по диагонали (разница между координатами по модулю должна быть равна)
    bool baseThreatBishop = (abs(KingX - BishopX) == abs(KingY - BishopY));

    // 2. БЛОКИРОВКА ЛАДЬИ СЛОНОМ
    bool rookBlocked = false;
    if (baseThreatRook) {
        // Если ладья угрожает по вертикали (одинаковый X) и слон стоит на той же вертикали
        if (KingX == RookX && BishopX == KingX) {
            // Проверяем, стоит ли слон между ними по оси Y
            rookBlocked = isBetween(BishopY, KingY, RookY);
        } 
        // Если ладья угрожает по горизонтали (одинаковый Y) и слон стоит на той же горизонтали
        else if (KingY == RookY && BishopY == KingY) {
            // Проверяем, стоит ли слон между ними по оси X
            rookBlocked = isBetween(BishopX, KingX, RookX);
        }
    }

    // 3. БЛОКИРОВКА СЛОНА ЛАДЬЕЙ
    bool bishopBlocked = false;
    if (baseThreatBishop) {
        // Проверяем, находится ли ладья на той же диагонали, что король и слон
        bool rookOnSameDiagonal = (abs(KingX - RookX) == abs(KingY - RookY));
        if (rookOnSameDiagonal) {
            // Если ладья на диагонали, проверяем, лежит ли она строго в прямоугольнике между ними
            bishopBlocked = isBetween(RookX, KingX, BishopX) && isBetween(RookY, KingY, BishopY);
        }
    }

    // 4. ИТОГОВЫЙ РАСЧЕТ УГРОЗ
    // Угроза актуальна, если она была базовая и линия НЕ заблокирована
    bool actualThreatRook = baseThreatRook && !rookBlocked;
    bool actualThreatBishop = baseThreatBishop && !bishopBlocked;

    // Возвращаем результат в виде простого кода (числа)
    if (actualThreatRook && actualThreatBishop) return 3; // Обе фигуры
    if (actualThreatRook) return 1;                       // Только ладья
    if (actualThreatBishop) return 2;                     // Только слон
    return 0;                                             // Король в безопасности
}
