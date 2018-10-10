#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

/* ファイルストリーム */
fstream m_fs;

/* ファイルを開く */
int file_open(string fileName) {

	m_fs.open(fileName, ios::out);
	if (!m_fs.is_open()) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* ファイルを閉じる */
int file_close() {
	m_fs.close();
	return EXIT_SUCCESS;
}

/* ファイル出力 */
void output_employee_csv(string csv_row_str) {

	/* テーブルの1レコード分の内容をカンマ区切りでCSV出力 */
	m_fs << csv_row_str << endl;
}