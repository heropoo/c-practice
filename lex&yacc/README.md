## lex&yacc

- Ubuntu 24.04.2 LTS
- gcc 13.3.0
- lex: flex 2.6.4
- yacc: bison 3.8.2

```
# on Ubuntu 24.04.2 LTS
apt install flex bison libfl-dev libbison-dev
```

### 参考
- [lex yacc 2nd Edition - code](https://resources.oreilly.com/examples/9781565920002)

### 常见问题
- 如果 gcc-13下编译 lex.yy.c 碰到 undefined reference to `yywrap' 报错，在.l文件中加上 %option noyywrap 