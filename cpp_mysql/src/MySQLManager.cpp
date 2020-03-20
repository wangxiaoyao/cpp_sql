//
//  MySQLManager.cpp
//  C++test
//
//  Created by 王逍遥 on 2020/3/20.
//  Copyright © 2020 王逍遥. All rights reserved.
//
#include "MySQLManager.hpp"
//连接数据库
bool MySQLManager::init(ConnectionInfo &info){
    mysql_init(&m_mysql);
    if(!(mysql_real_connect(&m_mysql, info.host, info.user, info.password, info.database, info.port, info.unix_socket, info.clientflag))) {
        printf("连接失败");
        return false;
    }
    printf("连接成功");
    return true;
}

//释放连接
bool freeConnect();

// 增加数据
bool insertData(const char*sql);

// 删除数据
bool deleteData(const char*sql);

// 修改数据
bool alterData(const char*sql);

// 查数据
MYSQL_RES* queryData(const char*sql);

// 执行sql
bool executeSql(const char*sql);

// 打印结果
void printQueryRes();
