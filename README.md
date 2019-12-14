# c-practice
c practice

## docker
```
docker build -t heropoo/gcc-ubuntu .
docker run -ti -v $PWD:/root/c-practice heropoo/gcc-ubuntu bash
```

查看动态链接库
linux
```
ldd hello
```

mac
```
otool -L hello
```
