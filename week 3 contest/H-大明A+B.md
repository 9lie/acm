# G-大明A+B

来源：HDU - 1753

地址：https://cn.vjudge.net/problem/HDU-1753

# 思路

高精度，java

# 代码

```java
import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            // BigInteger a = cin.nextBigInteger();
            // BigInteger b = cin.nextBigInteger();
            // BigInteger c =  a.add(b);
            BigDecimal a = cin.nextBigDecimal();
            BigDecimal b = cin.nextBigDecimal();
            BigDecimal c = a.add(b);
            System.out.println(c.stripTrailingZeros().toPlainString());
            // 去除多余的0，然后输出的时候不用科学计数法输出
        }
        cin.close();
    }
}
```