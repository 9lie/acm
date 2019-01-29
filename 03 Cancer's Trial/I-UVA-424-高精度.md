# Integer Inquiry

地址：https://cn.vjudge.net/problem/UVA-424

# 思路

**java，高精度**

# 代码

```java
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger res = new BigInteger("0"), a;
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            if (a.toString() == "0") break;
            res = res.add(a);
        }
        System.out.println(res.toString());
        cin.close();
    }
}
```