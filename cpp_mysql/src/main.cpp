//
//  main.cpp
//  CppMysql
//
//  Created by 王逍遥 on 2020/3/20.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#include <iostream>
#include "MySQLManager.hpp"

int main(int argc, const char * argv[]) {

    MySQLManager mysql;
    ConnectionInfo info;
    // 填充ConnectionInfo这个结构体，项目中一般从配置文件这读取
    info.user = "root";
    info.password = "root";
    info.database = "shoptest";
    
    mysql.init(info);
    
    // 增加测试
    std:: string sql1 = "insert into Shopinfo VALUES ('0011', '辛巴克杯子','杯子','2020-03-12',100,30,10,NULL)";
//    mysql.executeSql(sql1.c_str());
    
    //删除测试
    std:: string sql2 = "DELETE from Shopinfo WHERE good_id='0011'";
    mysql.executeSql(sql2.c_str());
    
    //修改测试
    std:: string sql3 = "UPDATE Shopinfo set  lens=77,stock_price=80 WHERE good_id='0010'";
    mysql.executeSql(sql3.c_str());
    // 查询测试
    std::string sql4 = "select * from Shopinfo WHERE good_id>'0008' ORDER BY sold_out_price";
    mysql.queryData(sql4.c_str());
    mysql.printQueryRes();

    
    mysql.freeConnect();
    return 0;
}
