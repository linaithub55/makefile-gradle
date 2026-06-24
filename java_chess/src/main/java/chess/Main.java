package chess;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int KingX, KingY, RookX, RookY, BishopX, BishopY;

        if (args.length == 6) {
            try {
                KingX = Integer.parseInt(args[0]);
                KingY = Integer.parseInt(args[1]);
                RookX = Integer.parseInt(args[2]);
                RookY = Integer.parseInt(args[3]);
                BishopX = Integer.parseInt(args[4]);
                BishopY = Integer.parseInt(args[5]);
                System.out.println("Координаты загружены из аргументов командной строки.");
            } catch (NumberFormatException e) {
                System.out.println("Ошибка: аргументы должны быть целыми числами.");
                return;
            }
        } else {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Введите координаты белого короля (X Y): ");
            KingX = scanner.nextInt();
            KingY = scanner.nextInt();
            System.out.print("Введите координаты черной ладьи (X Y): ");
            RookX = scanner.nextInt();
            RookY = scanner.nextInt();
            System.out.print("Введите координаты черного слона (X Y): ");
            BishopX = scanner.nextInt();
            BishopY = scanner.nextInt();
            scanner.close();
        }

        if (!isValid(KingX) || !isValid(KingY) || !isValid(RookX) || 
            !isValid(RookY) || !isValid(BishopX) || !isValid(BishopY)) {
            System.out.println("Ошибка: координаты должны быть от 1 до 8.");
            return;
        }

        int result = ChessMath.checkThreats(KingX, KingY, RookX, RookY, BishopX, BishopY);

        if (result == 3) {
            System.out.println("Угроза от обеих фигур");
        } else if (result == 1) {
            System.out.println("Угроза от ладьи");
        } else if (result == 2) {
            System.out.println("Угроза от слона");
        } else {
            System.out.println("Король в безопасности");
        }
    }

    private static boolean isValid(int c) {
        return c >= 1 && c <= 8;
    }
}
