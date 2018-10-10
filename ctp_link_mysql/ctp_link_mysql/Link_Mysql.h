#pragma once
#include"mysql.h"
#include<string>
#include<iostream>
using std::string;

class Link_Mysql
{
public:
	Link_Mysql();
	~Link_Mysql();
	void mysql_connect();
	void mysql_build();
	void mysql_storage(string& ID);

private:
	MYSQL  mysql;
};

