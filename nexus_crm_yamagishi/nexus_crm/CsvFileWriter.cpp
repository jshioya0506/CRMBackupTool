#include "CsvFileWriter.h"

/* �R���X�g���N�^ */
CsvFileWriter::CsvFileWriter()
{
}

/* �f�X�g���N�^ */
CsvFileWriter::~CsvFileWriter()
{
}

/* �t�@�C���I�[�v���֐� */
int CsvFileWriter::file_open(string fileName) {

	m_fs.open(fileName, ios::out);
	if (!m_fs.is_open()) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* �t�@�C���N���[�Y�֐� */
int CsvFileWriter:: file_close() {
	m_fs.close();
	return EXIT_SUCCESS;
}

/* �t�@�C���o�͊֐� */
void CsvFileWriter:: output_employee_csv(string csv_row_str) {

	/* �e�[�u����1���R�[�h���̓��e���J���}��؂��CSV�o�� */
	m_fs << csv_row_str << endl;
}