//
//  MySQLManager.cpp
//  C++test
//
//  Created by 王逍遥 on 2020/3/20.
//  Copyright © 2020 王逍遥. All rights reserved.
//
#include <iostream>
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
bool MySQLManager::freeConnect(){
    mysql_free_result(m_res);
    mysql_close(&m_mysql);
    std::cout<< "释放成功，断开连接" <<std::endl;
    return false;
};

// 查数据
MYSQL_RES* MySQLManager::queryData(const char*sql){
    if(mysql_query(&m_mysql, sql)){
        std::cout <<"查询失败，原因："<< mysql_error(&m_mysql)<<std::endl;
    }else{
        std::cout<< "查询成功" <<std::endl;
    }
    
    m_res  = mysql_store_result(&m_mysql);
    return m_res;
};

// 执行sql:增加，删除，修改
bool MySQLManager::executeSql(const char*sql){
    if( mysql_query(&m_mysql, sql)){
        std::cout<<"执行sql语句失败，错误信息为："<< mysql_error(&m_mysql)<<std::endl;
        return false;
    }else{
        std::cout << "执行sql语句成功" <<std::endl;
    }
     return true;
};

// 遍历结果
void MySQLManager::printQueryRes(){
    if (nullptr == m_res || NULL == m_res) {
        return;
    }
    

    // 获取列数
    int columns = mysql_num_fields(m_res);
    
    // 获取字段名：两种方式 mysql_fetch_fields mysql_fetch_field
    //MYSQL_FIELD* file=nullptr;
    //char fileName[100][100];
//    for (int i =0; (file=mysql_fetch_field(m_res)) ; i++) {
//        strcpy(fileName[i] ,file->name);
//    }
//    for (int i = 0; i<columns; ++i) {
//        printf("%8s\t", fileName[i]);
//    }
    MYSQL_FIELD* file1=nullptr;
    file1 = mysql_fetch_fields(m_res);
    for (int i = 0; i<columns; ++i) {
        printf("%10s\t", file1[i].name);
    }
    std::cout<<std::endl;
    
    // 获取行
    MYSQL_ROW row;
    while ((row=mysql_fetch_row(m_res))) {
        for (int i =0; i<columns ; ++i) {
            printf("%10s\t",row[i]);
        }
        std::cout<<std::endl;
    }
    
    

};
