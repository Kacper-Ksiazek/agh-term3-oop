package reader;

import java.io.IOException;

public class Reader {
    // Wlasciwosci:
    private static char preservedCharacter = 0;
    private static boolean characterHasBeenPreserved = false;

    //--- PUBLICZNE i nie trzeba obiektu klasy aby je wywolac
    public static char getChar() {
        if (Reader.characterHasBeenPreserved) {
            Reader.characterHasBeenPreserved = false;
            return Reader.preservedCharacter;
        }

        try {
            return (char) System.in.read();
        } catch (IOException e) {
            return '\u0000';
        }
    }

    public static void ungetChar(char characterToPreserve) {
        Reader.characterHasBeenPreserved = true;
        Reader.preservedCharacter = characterToPreserve;
    }

    //

    public static int readInt() {
        int sign = Reader.getSign() ? -1 : 1;

        return sign * Reader.readNum();
    }

    public static double readDouble() {
        int sign = Reader.getSign() ? -1 : 1;

        int base = Reader.readNum();

        if (Reader.getChar() != '.') return base;

        double factor = Reader.readNum();
        factor = factor / Math.pow(10, (String.valueOf((int) factor).length()));

        return sign * (base + factor);
    }

    public static int readHex() throws IOException {
        skipSpaces();
        String prefix = Character.toString(Reader.getChar()) + Reader.getChar();

        if (!prefix.equals("0x") && !prefix.equals("0X")) {
            throw new IOException("Wrong hexadecimal prefix! Should be 0x or 0X");
        }

        char c;
        int result = 0;

        while (Reader.isHexDigit(c = Reader.getChar())) {
            result = result * 16 + Reader.charHexDigit2Int(c);
        }

        return result;
    }


    //================ P R I V A T E INTERFACE ==========================================
    private static int readNum() {
        Reader.skipSpaces();

        int result = 0;
        char c;

        while (Reader.isDecDigit(c = Reader.getChar())) {
            result = result * 10 + Reader.charDecDigit2Int(c);
        }

        ungetChar(c);

        return result;
    }

    private static boolean getSign() {
        Reader.skipSpaces();

        char c = Reader.getChar();
        if (c == '-') return true;

        Reader.ungetChar(c);
        return false;
    }

    private static void skipSpaces() {
        char c;
        while ((c = Reader.getChar()) == ' ' || c == '\t' || c == '\r' || c == '\n') continue;

        Reader.ungetChar(c);
    }

    private static boolean isDecDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    private static boolean isHexDigit(char c) {
        return Reader.isHexLetter(c) || Reader.isDecDigit(c);
    }

    private static char upperCase(char c) {
        return (c >= 'a' && c <= 'f') ? (char) (c - 32) : c;
    }

    private static boolean isHexLetter(char c) {
        return (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }

    private static int charDecDigit2Int(char c) throws ArithmeticException {
        return (int) c - 48;
    }

    private static int charHexDigit2Int(char c) {
        return Reader.isHexLetter(c) ? (int) Reader.upperCase(c) - 55 : Reader.charDecDigit2Int(c);
    }
}
