#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <fstream>

using namespace std;

class CsvFileWriter
{
public:
	CsvFileWriter();
	~CsvFileWriter();

	int file_open(string fileName);
	int file_close(void);
	void output_employee_csv(string csv_row_str);

	/* ファイルストリーム */
	fstream m_fs;
};
