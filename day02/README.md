## 数据类型

### sizeof
|    type     | size |
| :---------- | ---: |
| int         |  4   |
| short int   |  2   |
| long int    |  8   |
| unsigned int|  4   |
| char        |  1   |
| float       |  4   |
| double      |  8   |
| long double |  16  |

### printf
> * %lu 为 32 位无符号整数
> * %E 为以指数形式输出单、双精度实数

### 二进制表示
> * float 	单精度浮点值。单精度是这样的格式，1位符号，8位指数，23位小数。
> * double 	双精度浮点值。双精度是1位符号，11位指数，52位小数。

### 整数常量
整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：`0x`或`0X`表示十六进制`0`表示八进制，不带前缀则默认表示十进制。整数常量也可以带一个后缀，后缀是`U`和`L`的组合，`U`表示无符号整数（unsigned），`L`表示长整数（long）。后缀可以是大写，也可以是小写，`U`和`L`的顺序任意。

各种类型的整数常量的实例：
```c
85         /* 十进制 */
0213       /* 八进制 */
0x4b       /* 十六进制 */
30         /* 整数 */
30u        /* 无符号整数 */
30l        /* 长整数 */
30ul       /* 无符号长整数 */
```

## C 存储类
> * auto
> * register
> * static
> * extern

