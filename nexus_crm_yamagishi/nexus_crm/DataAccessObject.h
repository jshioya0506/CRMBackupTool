#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <fstream>

#include "DataModel.h"
#include "CsvFileWriter.h"
using namespace std;

class DataAccessObject
{
public:
	DataAccessObject();
	~DataAccessObject();

	int db_open( void );
	int db_close( void );
	int select_employee();

private:

	/* MySQLópÇÃç\ë¢ëÃ */
	MYSQL* mysql;
	MYSQL_RES* res;
	MYSQL_FIELD* field;
	MYSQL_ROW row;
};
