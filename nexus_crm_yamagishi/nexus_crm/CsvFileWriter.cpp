#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

/* �t�@�C���X�g���[�� */
fstream m_fs;

/* �t�@�C�����J�� */
int file_open(string fileName) {

	m_fs.open(fileName, ios::out);
	if (!m_fs.is_open()) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* �t�@�C������� */
int file_close() {
	m_fs.close();
	return EXIT_SUCCESS;
}

/* �t�@�C���o�� */
void output_employee_csv(string csv_row_str) {

	/* �e�[�u����1���R�[�h���̓��e���J���}��؂��CSV�o�� */
	m_fs << csv_row_str << endl;
}