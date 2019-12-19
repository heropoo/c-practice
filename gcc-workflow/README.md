# gcc工作流程

静态编译
```
gcc hello.c -o hello -static
```

查看gcc背后的工作流程--verbose选项

1. 预编译
```
gcc -E hello.c -o hello.i
```

2. 编译
```
gcc -S hello.i -o hello.s
```
编译之后产生汇编代码，语法格式是AT&T格式，若要生成intel格式使用`-masm=intel`

3. 汇编
```
gcc -c hello.s -o hello.o
```
生成可重定位目标文件，可使用gcc自带的objdump查看
```
objdump -sd hello.o
```

4. 链接
```
gcc hello.o -o hello #使用-static选项进行静态链接
```



