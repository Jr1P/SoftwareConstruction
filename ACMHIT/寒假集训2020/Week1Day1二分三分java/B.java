import java.util.*;
import java.math.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigDecimal a = BigDecimal.valueOf(0);
        BigDecimal ans = BigDecimal.valueOf(0);
        while (cin.hasNext())
        {
            a = cin.nextBigDecimal();
            ans = ans.add(a);
        }
           
        System.out.println(ans);
    }
}