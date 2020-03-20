//
//  main.cpp
//  C++test
//
//  Created by 王逍遥 on 2020/2/1.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#include <iostream>
#include "MySQLManager.hpp"

using namespace std;

int main(void){
    MySQLManager mysql;
    ConnectionInfo info;
    // 填充ConnectionInfo这个结构体，项目中一般从配置文件这读取
    info.user = "root";
    info.password = "root";
    info.database = "shoptest";
    
    mysql.init(info);
    
    
    
    return EXIT_SUCCESS;
    
};
