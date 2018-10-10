#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

/* 使用する関数のプロトタイプ宣言 */

int db_open();
int db_close();
int select_employee();
int file_open(string fileName);
int file_close();
void output_employee_csv(string csv_row_str);

const char *employeeCsvFile = "Employee.csv";
string strEmployeeCsvFile = string(employeeCsvFile);
string separation = "\\";

/* メイン関数 */
int main(int argc, char* argv[])
{
	bool databaseOpenflg = false; // データベースのオープン状態フラグ

	/* 起動引数が指定されているかチェック */
	if (argc <= 1) {
		MessageBox(NULL, "バックアップファイル保管場所が指定されていません。", "エラー", MB_OK); // 起動引数にバックアップファイル保管場所が指定されていない。
		return 1; // 異常終了
	}

	/* 起動引数のフォーマットに異常がないかチェック */
	if (argc >= 3) {
		MessageBox(NULL, "引数の指定に誤りがあります。", "エラー", MB_OK); // 起動引数のフォーマット異常。
		return 1; // 異常終了
	}

	/* DB接続 */
	if (db_open() == -1) {
		MessageBox(NULL, "データベースの接続に失敗しました。", "エラー", MB_OK); // データベースの接続に失敗。
		return 1; // 異常終了
	}

	databaseOpenflg = true;

	/* ファイルを開く */
	if (file_open(string(argv[1]) + separation + strEmployeeCsvFile) == EXIT_FAILURE){
		char passBuf[200];
		sprintf_s(passBuf, 200, "出力ファイル%sの出力に失敗しました。", employeeCsvFile);

		MessageBox(NULL, passBuf, "エラー", MB_OK); // 出力ファイルの出力に失敗。

	}
	else {
		/* 職員テーブル(EMPLOYEE)を検索してCSV出力 */
		if (select_employee() == -1) {
			databaseOpenflg = false; // SQLの発行およびMySQLからデータを取得に失敗した場合データベースは既にクローズしている
		}
	}

	/* ファイルを閉じる */
	file_close();

	/* DB切断 */
	if (databaseOpenflg) {
		db_close();
	}
	return 0;
}
