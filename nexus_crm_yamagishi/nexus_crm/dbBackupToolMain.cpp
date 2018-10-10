#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

/* �g�p����֐��̃v���g�^�C�v�錾 */

int db_open();
int db_close();
int select_employee();
int file_open(string fileName);
int file_close();
void output_employee_csv(string csv_row_str);

const char *employeeCsvFile = "Employee.csv";
string strEmployeeCsvFile = string(employeeCsvFile);
string separation = "\\";

/* ���C���֐� */
int main(int argc, char* argv[])
{
	bool databaseOpenflg = false; // �f�[�^�x�[�X�̃I�[�v����ԃt���O

	/* �N���������w�肳��Ă��邩�`�F�b�N */
	if (argc <= 1) {
		MessageBox(NULL, "�o�b�N�A�b�v�t�@�C���ۊǏꏊ���w�肳��Ă��܂���B", "�G���[", MB_OK); // �N�������Ƀo�b�N�A�b�v�t�@�C���ۊǏꏊ���w�肳��Ă��Ȃ��B
		return 1; // �ُ�I��
	}

	/* �N�������̃t�H�[�}�b�g�Ɉُ킪�Ȃ����`�F�b�N */
	if (argc >= 3) {
		MessageBox(NULL, "�����̎w��Ɍ�肪����܂��B", "�G���[", MB_OK); // �N�������̃t�H�[�}�b�g�ُ�B
		return 1; // �ُ�I��
	}

	/* DB�ڑ� */
	if (db_open() == -1) {
		MessageBox(NULL, "�f�[�^�x�[�X�̐ڑ��Ɏ��s���܂����B", "�G���[", MB_OK); // �f�[�^�x�[�X�̐ڑ��Ɏ��s�B
		return 1; // �ُ�I��
	}

	databaseOpenflg = true;

	/* �t�@�C�����J�� */
	if (file_open(string(argv[1]) + separation + strEmployeeCsvFile) == EXIT_FAILURE){
		char passBuf[200];
		sprintf_s(passBuf, 200, "�o�̓t�@�C��%s�̏o�͂Ɏ��s���܂����B", employeeCsvFile);

		MessageBox(NULL, passBuf, "�G���[", MB_OK); // �o�̓t�@�C���̏o�͂Ɏ��s�B

	}
	else {
		/* �E���e�[�u��(EMPLOYEE)����������CSV�o�� */
		if (select_employee() == -1) {
			databaseOpenflg = false; // SQL�̔��s�����MySQL����f�[�^���擾�Ɏ��s�����ꍇ�f�[�^�x�[�X�͊��ɃN���[�Y���Ă���
		}
	}

	/* �t�@�C������� */
	file_close();

	/* DB�ؒf */
	if (databaseOpenflg) {
		db_close();
	}
	return 0;
}
