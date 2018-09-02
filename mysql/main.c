#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "db_config.h"

int main()
{
	int ret = 0;
	MYSQL   mysql;
    MYSQL   *con = NULL;

    //MYSQL *mysql_init(MYSQL *mysql)　　
    con = mysql_init(&mysql);
    if (con == NULL)
    {
        ret = mysql_errno(&mysql);
        printf("func mysql_init() err :%d\n", ret);
        return ret;
    }

    printf("func mysql_init() OK\n");

    //printf("CLIENT_FOUND_ROWS=%d\n", CLIENT_FOUND_ROWS);

    //连接mysql服务器
    //MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
    con = mysql_real_connect(&mysql, DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME, DB_PORT, NULL, 0); //CLIENT_FOUND_ROWS=2
    if (con == NULL)
    {
        ret = mysql_errno(&mysql);
        printf("func mysql_real_connect() err :%d\n", ret);
        return ret;
    }
    
    printf("func mysql_real_connect() OK\n");

    const char *query_sql = "show tables";  //查询语句

    MYSQL_RES *result;  //保存结果集的
    MYSQL_ROW row;      //代表的是结果集中的一行

    if(mysql_query(&mysql, query_sql) != 0)
    {
        ret = mysql_errno(&mysql);
        printf("func mysql_query() err :%d\n", ret);
        return ret;
    }

    if((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果 
    {
        ret = mysql_errno(&mysql);
        printf("func mysql_store_result() err :%d\n", ret);
        return ret;
    }

    while((row = mysql_fetch_row(result)) != NULL)  // 获取一行
    {
        printf("--------------------------------\n");
        printf("%s\t", row[0]);
        printf("\n--------------------------------\n");
    }

    mysql_free_result(result); //释放结果集 
    
    printf("Close mysql link ...\n");
    mysql_close(&mysql);

    return ret;
}