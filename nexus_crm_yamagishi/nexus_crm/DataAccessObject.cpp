#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

void output_employee_csv(string csv_row_str); // ファイル出力を行う必要があるためプロトタイプ宣言

void inDataModel(string inData[]); // データ格納
void outDataModel(int dataNum); // データ排出


/* MySQL用の構造体 */
MYSQL* mysql;
MYSQL_RES* res;
MYSQL_FIELD* field;
MYSQL_ROW row;

/* データベース情報 */
const char host[] = "127.0.0.1";               /* 接続先 */
const char user[] = "root";                    /* ユーザ名 */
const char password[] = "kiritori";            /* パスワード */
const char dbname[] = "nexus_crm";             /* データベース名 */
const char sqlSelect[] = "SELECT * FROM ";   /* 参照系 */
const char sqlTable[] = "EMPLOYEE";   /* 参照テーブル */


	/* DBを開く(接続する) */
	int db_open() {
		/* 初期化処理 */
		mysql = mysql_init(0);

		/* MySQLに接続 */
		if (mysql_real_connect(mysql, host, user, password, dbname, MYSQL_PORT, NULL, 0) == NULL) {
			printf("%s\n", mysql_error(mysql));
			return -1;
		}
		return 0;
	}

	/* DBを閉じる(切断する) */
	int db_close() {
		/* MySQLから切断 */
		mysql_close(mysql);
		return 0;
	}

/* 職員テーブル(EMPLOYEE)を検索してCSV出力 */
int select_employee() {
	char sql[200];
	sprintf_s(sql, 200, "%s%s", sqlSelect, sqlTable); // テーブル選択文の作成

	/* SQLの発行 */
	if (mysql_query(mysql, sql) != 0) {
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		return -1;
	}

	/* MySQLからデータを取得 */
	res = mysql_store_result(mysql);
	if (res == NULL) {
		char tableBuf[200];
		sprintf_s(tableBuf, 200, "%sからのデータ読込に失敗しました。", sqlTable);
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		MessageBox(NULL, tableBuf, "エラー", MB_OK); // テーブルからデータの読み込みに失敗。
		return -1;
	}

	/* 職員テーブル(EMPLOYEE) のフィールド */
	string m_employee_fields[] = { "EMPNO","EMPNO_ED","LIMTYMD","NAME","ENTRYMD","RETRYMD","PASSWORD","LOSTYMD","UPDATE"};

	///* フィールド数を取得 */
	int num_fields = sizeof m_employee_fields / sizeof m_employee_fields[0];

	int rowNNum = 0; // 行数カウント

	/* データを読み取って表示 */
	while (row = mysql_fetch_row(res)) {

		/* 1フィールド分のデータを格納するバッファ */
		char buffer[50];

		string csv_row_str[20];

		/* フィールドの数だけループ */
		for (int i = 0; i < num_fields; i++) {
			/* 1フィールド分のデータを取得 */
			snprintf(buffer, sizeof(buffer), "%s", row[i]);
			csv_row_str[i] = buffer;
		}
		inDataModel(csv_row_str);
		rowNNum++;
	}

	string headTitle = "";

	/* ヘッダ部CSV記入 */
	for (int j = 0; j < num_fields; j++) {
		if (j == 0) {
			headTitle = m_employee_fields[j];
		}
		else {
			headTitle = headTitle + "," + m_employee_fields[j];
		}
	}

	output_employee_csv(headTitle);

	/* 行数だけCSV排出 */
	for (int index = 0; index < rowNNum; index++) {
		outDataModel(index);
	}
	return 0;
}
