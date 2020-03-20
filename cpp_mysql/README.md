## cpp和mysql

> cmake的相关使用：参见github《cpp-project-template》

### mysql

mysql的下载，启动此处不表。无论哪一种方式下载mysql均有include文件夹和lib文件夹。

Cpp中使用mysql ：

- 1 添加mysql头文件 <mysql.h>

- 2 添加mysql的库文件： mysqlclient

说明： 

- 1 MySQL Server： 是mysql服务的本体
- 2 mysqlclient： 是mysql命令行模式客户端，我们通过这个客户端来操作Mysql

所以在书写的时候 mysql是客户端程序，   mysqld 是服务程序


```
## 单独的cpp编译：指定库路径和库名
g++  XX.cpp -I /usr/local/mysql/include -o  newapp  -lmysqlclient
```

注意： 

我通过brew安装mysql，brew 会将软件的 include 和 lib软连接在系统的/usr/local 的lib 和include文件内。 若你通过其他方式下载，记得做软链接：

```
## 在linux 下/usr/include 下做一个软连接
sudo ln -s  /usr/local/mysql/include mysql 
```

### cmake

在cmake的配置文件:CMakeLists中 ，将mysql的头文件(include)和lib文件添加进去。然后进行编译即可

```
## 添加库地址
link_directories(/usr/local/lib)
link_libraries(mysqlclient)

##头文件
include_directories(include)
include_directories(/usr/local/include/mysql)
```

### 其他 IDE

1 Xcode

-  1 在build Setting -》Search Paths中

分别补上： 

Header Search Paths ：   mysql头文件路径

Library  Search Paths  ：  mysql库文件路径

- 2 在build Setting -》Linking中

在Other Linker  Flags 补上：  -lmysqlclient



