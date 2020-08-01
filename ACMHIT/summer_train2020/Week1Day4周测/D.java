import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

public class D {

    public static void main(String[] args) {
        Map<Character, Integer > map = new HashMap<Character, Integer>();
        Map<Integer, Character > map1 = new HashMap<Integer, Character>();
        for(int i = 0; i < 10; i++) {
            map.put((char) (i + '0'), i);
            map1.put(i, (char) (i + '0'));
        }
        for(int i = 'A'; i <= 'Z'; i++) {
            map.put((char) (i), i - 55);
            map1.put(i - 55, (char) (i));
        }
        for(int i = 'a'; i <= 'z'; i++) {
            map.put((char) (i), i - 61);
            map1.put(i - 61, (char) (i));
        }
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for(int i = 1; i <= n; i++) {
            int a = cin.nextInt(), b = cin.nextInt();
            String sa = cin.next();
            System.out.println(a + " " + sa);
            String sb = "";
            if(sa.equals("0")) sb = "0";
            BigInteger base = BigInteger.valueOf(a);
            BigInteger now = BigInteger.valueOf(1);
            BigInteger sum = BigInteger.valueOf(0);
            for(int j = sa.length() - 1; j >= 0; j--) {
                int t = map.get(sa.charAt(j));
                sum = sum.add(now.multiply(BigInteger.valueOf(t)));
                now = now.multiply(base);
            }
            base = BigInteger.valueOf(b);
            while(!sum.equals(BigInteger.valueOf(0))) {
                BigInteger mo = sum.mod(base);
                int po = Integer.parseInt(mo.toString());
                sb = map1.get(po).toString().concat(sb);
                sum = sum.divide(base);
            }
             System.out.println(b + " " + sb + '\n');
            // else System.out.println(b + " " + sb);
        }
    }
}