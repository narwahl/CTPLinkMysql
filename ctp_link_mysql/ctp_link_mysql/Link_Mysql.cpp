#include "Link_Mysql.h"
#include"mysql.h"
#include<iostream>
#include<string>
using std::string;
using namespace std;

Link_Mysql::Link_Mysql() 
{
	
}

Link_Mysql::~Link_Mysql()
{

}

void Link_Mysql::mysql_connect()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1161122388SD?", "datatest", 3306, NULL, 0))
	{
		cout << "数据库连接失败" << endl;
		cout << "错误内容：" << mysql_error(&mysql) << endl;
	}
	else
	{
		cout << "数据库连接成功" << endl;
	}
}

void Link_Mysql::mysql_build()
{
	const char *build = "create table future_data(contract char(10),time datetime(6),newprice int(5),vol double,opi double,primary key(time))engine = innodb";
	const char *select = "show table like 'future_data'";
	if (mysql_real_query(&mysql, select, strlen(select)))
	{
		mysql_real_query(&mysql, build, strlen(build));
	}
	else
	{
		cout << "无法创建表，错误码：" << mysql_error(&mysql) << endl;
	}
}

void Link_Mysql::mysql_storage(string& ID)
{
	string insert;
	insert = "insert into future_data(contract,time,newprice,vol,opi) " + ID;
	const char *in = insert.c_str();
	if (0 != mysql_real_query(&mysql, in, strlen(in)))
	{
		cout << insert<< endl;
		cout << mysql_error(&mysql) << endl;
	}
}
