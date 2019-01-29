# java 入门

## 原因

java在高精度和进制转换这两方面有着独有的优势，学习java是很有必要的

## 基础框架

```java
import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // coding here
    }
}
```

## 输入输出

```java
import java.util.*;

Scanner cin = new Scanner(System.in);

while (cin.hasNext()) { // while (cin >> a)
    int a = cin.nextInt(); //cin >> a;
    String str = cin.nextLine();
    double b = cin.nextDouble();
}

System.out.println(a); // cout << a << endl;
System.out.print(str); // cout << str;
System.out.printf("%lf", b); // printf()
cin.close();
```

## BigInteger

```java
import java.math.*;

BigInteger a = cin.nextBigInteger();
BigInteger b = cin.nextBigInteger();

System.out.println(a.toString() + " + " + b.toString() + " + " + a.add(b).toString());
```

除此之外，还有

```java
a.subtract(b) // -
a.multiply(b) // *
a.divide(b) // /
a.mod(b) // %

int c = 6；
a = BigInteger.valueOf(c); // =
```

## BigDecimal

和上面类似，但因为是小数，有额外的格式化输出要注意

```java

a.setScale(1); // 保留小数点后1位，四舍五入
a.setScale(1, BigDecimal.ROUND_DOWN) // 向下取
a.setScale(1, BigDecimal.ROUND_UP) // 向上取

a.stripTrailingZeros().toPlainString(); // 去除多余的0，然后不要使用科学计数法输出
```
