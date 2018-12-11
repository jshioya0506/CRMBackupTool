#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include "CsvFileWriter.h"
#include "DataAccessObject.h"

#include <fstream>
using namespace std;
class DbBackupToolMain
{
public:
	DbBackupToolMain();
	~DbBackupToolMain();

	int main( char* argv );

private:

};