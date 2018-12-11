#include "DataAccessObject.h"

/* データベース情報 */
const char host[] = "127.0.0.1";			/* 接続先 */
const char user[] = "root";					/* ユーザ名 */
const char password[] = "kiritori";			/* パスワード */
const char dbname[] = "nexus_crm";			/* データベース名 */
const char sqlSelect[] = "SELECT * FROM ";	/* 参照系 */
const char sqlTable[] = "EMPLOYEE";			/* 参照テーブル */

/* 職員テーブル(EMPLOYEE) のフィールド */
string m_employee_fields[] = { "EMPNO","EMPNO_ED","LIMTYMD","NAME","ENTRYMD","RETRYMD","PASSWORD","LOSTYMD","UPDATE" };

/* コンストラクタ */
DataAccessObject::DataAccessObject()
{
}

/* デストラクタ */
DataAccessObject::~DataAccessObject()
{
}

/* DBオープン関数 */
int DataAccessObject::db_open() {
	/* 初期化処理 */
	mysql = mysql_init(0);

	/* MySQLに接続 */
	if (mysql_real_connect(mysql, host, user, password, dbname, MYSQL_PORT, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(mysql));
		return -1;
	}
	return 0;
}

/* DBクローズ関数 */
int DataAccessObject :: db_close() {
	/* MySQLから切断 */
	mysql_close(mysql);
	return 0;
}

/* 職員テーブル(EMPLOYEE)を検索してCSV出力 */
int DataAccessObject:: select_employee() {
	char sql[200];
	sprintf_s(sql, 200, "%s%s", sqlSelect, sqlTable); // テーブル選択文の作成

	CsvFileWriter csvFileWriter;
	DataModel dataModel;

	/* SQLの発行 */
	if (mysql_query(mysql, sql) != 0) {
		mysql_close(mysql);
		return EXIT_FAILURE;
	}

	/* MySQLからデータを取得 */
	res = mysql_store_result(mysql);

	if (res == NULL) {
		char tableBuf[200];
		sprintf_s(tableBuf, 200, "%sからのデータ読込に失敗しました。", sqlTable);
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		MessageBox(NULL, tableBuf, "エラー", MB_OK); // テーブルからデータの読み込みに失敗。
		return EXIT_FAILURE;
	}

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
		dataModel.inDataModel(csv_row_str);
		rowNNum++;
	}

	string headTitle = "";

	/* ヘッダ部CSV記入 */
	for (int j = 0; j < num_fields; j++) {
		if (0 == j) {
			headTitle = m_employee_fields[j];
		}
		else {
			headTitle = headTitle + "," + m_employee_fields[j];
		}
	}

	csvFileWriter.output_employee_csv(headTitle);

	/* 行数だけCSV排出 */
	for (int index = 0; index < rowNNum; index++) {
		dataModel.outDataModel(index);
	}

	return EXIT_SUCCESS;
}
