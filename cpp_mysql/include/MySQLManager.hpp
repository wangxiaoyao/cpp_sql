//
//  MySQLManager.hpp
//  C++test
//
//  Created by 王逍遥 on 2020/3/20.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#ifndef MySQLManager_hpp
#define MySQLManager_hpp

#include <stdio.h>
#include <string>
// 引入mysql头文件
#include <mysql.h>
// 连接信息
struct ConnectionInfo{
    ConnectionInfo():
        host("localhost"),
        port(3306),
        unix_socket(NULL),
        clientflag(0)
    {}
    const char* host;
    const char* user;
    const char* password;
    const char* database;
    unsigned int port;
    // unix连接表示符，以及客户端连接标志
    const char* unix_socket;
    unsigned long clientflag;
};

class MySQLManager{
public:
    //连接数据库
    bool init(ConnectionInfo &info);
    
    //释放连接
    bool freeConnect();
    
    // 查数据
    MYSQL_RES* queryData(const char*sql);
    
    // 执行sql
    bool executeSql(const char*sql);
    
    // 打印结果
    void printQueryRes();
private:
    // mysql连接
    MYSQL m_mysql;
    // 查询结果集
    MYSQL_RES *m_res;
};

#endif /* MySQLManager_hpp */
