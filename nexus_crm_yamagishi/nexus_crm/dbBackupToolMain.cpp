#include "dbBackupToolMain.h"


const char *employeeCsvFile = "Employee.csv";
string strEmployeeCsvFile = string(employeeCsvFile);
string separation = "\\";

/* コンストラクタ */
DbBackupToolMain::DbBackupToolMain()
{
}

/* デストラクタ */
DbBackupToolMain::~DbBackupToolMain()
{
}

/* メイン関数 */
int DbBackupToolMain:: main(char* argv)
{
	DataAccessObject dataAccessObject;
	CsvFileWriter csvFileWriter;
	bool databaseOpenflg = false; // データベースのオープン状態フラグ

	/* DB接続 */
	if (dataAccessObject.db_open() == -1) {
		MessageBox(NULL, "データベースの接続に失敗しました。", "エラー", MB_OK); // データベースの接続に失敗。
		return EXIT_FAILURE; // 異常終了
	}

	databaseOpenflg = true;

	/* ファイルを開く */
	if (csvFileWriter.file_open( string(argv) + separation + strEmployeeCsvFile) == EXIT_FAILURE ){
		char passBuf[200];
		sprintf_s(passBuf, 200, "出力ファイル%sの出力に失敗しました。", employeeCsvFile);

		MessageBox(NULL, passBuf, "エラー", MB_OK); // 出力ファイルの出力に失敗。

	}
	else {
		/* 職員テーブル(EMPLOYEE)を検索してCSV出力 */
		if (dataAccessObject.select_employee() == -1) {
			databaseOpenflg = false; // SQLの発行およびMySQLからデータを取得に失敗した場合データベースは既にクローズしている
		}
	}

	/* ファイルを閉じる */
	csvFileWriter.file_close();

	/* DB切断 */
	if (databaseOpenflg) {
		dataAccessObject.db_close();
	}
	return EXIT_SUCCESS;
}
