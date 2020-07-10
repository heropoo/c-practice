# LLVM

## LLVM工具链的使用示例
将”hello.c”编译为可执行文件:
```
clang hello.c -o hello
```

> Clang默认就像GCC一样工作。标准-S和-c参数相同（分别生成本机.s或.o文件）

将”hello.c”编译为LLVM字节码文件 
```
clang -O3 -emit-llvm hello.c -c -o hello.bc
```