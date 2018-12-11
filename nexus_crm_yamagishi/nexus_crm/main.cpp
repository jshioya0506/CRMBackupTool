#include "stdafx.h"
#include "dbBackupToolMain.h"

int main(int argc, char *argv[])
{
	/* 起動引数が指定されているかチェック */
	if (argc <= 1) {
		MessageBox(NULL, "バックアップファイル保管場所が指定されていません。", "エラー", MB_OK); // 起動引数にバックアップファイル保管場所が指定されていない。
		return EXIT_FAILURE; // 異常終了
	}

	/* 起動引数のフォーマットに異常がないかチェック */
	if (argc >= 3) {
		MessageBox(NULL, "引数の指定に誤りがあります。", "エラー", MB_OK); // 起動引数のフォーマット異常。
		return EXIT_FAILURE; // 異常終了
	}

	DbBackupToolMain dbBackupToolMain;
	dbBackupToolMain.main(argv[1]);

	return 0;
}
