## mysql

### requirement
```
apt install mysql-server libmysqlclient-dev
```

### complie
* 编译
```
gcc main.c -I /usr/include/mysql/ -L /lib/ -l mysqlclient -o main
```

* 分步编译
```
gcc -c -I /usr/include/mysql/ main.c -o main.o
gcc -L /lib/ -l mysqlclient main.o -o main
```

