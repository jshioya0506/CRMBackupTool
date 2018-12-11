#include "CsvFileWriter.h"

/* コンストラクタ */
CsvFileWriter::CsvFileWriter()
{
}

/* デストラクタ */
CsvFileWriter::~CsvFileWriter()
{
}

/* ファイルオープン関数 */
int CsvFileWriter::file_open(string fileName) {

	m_fs.open(fileName, ios::out);
	if (!m_fs.is_open()) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* ファイルクローズ関数 */
int CsvFileWriter:: file_close() {
	m_fs.close();
	return EXIT_SUCCESS;
}

/* ファイル出力関数 */
void CsvFileWriter:: output_employee_csv(string csv_row_str) {

	/* テーブルの1レコード分の内容をカンマ区切りでCSV出力 */
	m_fs << csv_row_str << endl;
}