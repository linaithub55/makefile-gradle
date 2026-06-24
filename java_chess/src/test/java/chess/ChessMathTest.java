package chess;

import org.junit.Assert;
import org.junit.Test;

public class ChessMathTest {

    @Test
    public void testRookThreat() {
        // King(1,1), Rook(1,5), Bishop(2,3) -> Угроза от ладьи
        int result = ChessMath.checkThreats(1, 1, 1, 5, 2, 3);
        Assert.assertEquals("Должна быть угроза от ладьи (1)", 1, result);
    }

    @Test
    public void testBishopThreat() {
        // King(2,2), Rook(4,5), Bishop(5,5) -> Угроза от слона
        int result = ChessMath.checkThreats(2, 2, 4, 5, 5, 5);
        Assert.assertEquals("Должна быть угроза от слона (2)", 2, result);
    }

    @Test
    public void testBothThreat() {
        // King(4,4), Rook(4,8), Bishop(1,1) -> Угроза от обеих фигур
        int result = ChessMath.checkThreats(4, 4, 4, 8, 1, 1);
        Assert.assertEquals("Должна быть угроза от обеих фигур (3)", 3, result);
    }

    @Test
    public void testSafetyWithBlockRook() {
        // King(1,1), Rook(1,8), Bishop(1,4)
        // Ладья угрожает, но слон перекрывает линию -> безопасность
        int result = ChessMath.checkThreats(1, 1, 1, 8, 1, 4);
        Assert.assertEquals("Король должен быть в безопасности из-за перекрытия ладьи (0)", 0, result);
    }

    @Test
    public void testSafetyWithBlockBishop() {
        // King(1,1), Bishop(5,5), Rook(3,3)
        // Слон угрожает, но ладья перекрывает диагональ -> безопасность
        int result = ChessMath.checkThreats(1, 1, 3, 3, 5, 5);
        Assert.assertEquals("Король должен быть в безопасности из-за перекрытия слона (0)", 0, result);
    }
}
