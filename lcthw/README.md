## 笨办法学C (Learn C The Hard Way) 

### 参考
- https://www.cntofu.com/book/25/index.html
- https://github.com/wizardforcel/lcthw-zh.git

### 环境安装
 - Ubuntu
    ```sh
    sudo apt-get install build-essential
    ```
 - CentOS
    ```sh
    su -c "yum groupinstall development-tools"
    ```

### C 编译选项
- `-Wall` 告诉cc编译器要报告所有的警告（然而实际上不可能报告所有警告）
- `-g` 获取调试信息