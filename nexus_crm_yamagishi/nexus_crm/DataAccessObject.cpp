#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>

#include <fstream>
using namespace std;

void output_employee_csv(string csv_row_str); // �t�@�C���o�͂��s���K�v�����邽�߃v���g�^�C�v�錾

void inDataModel(string inData[]); // �f�[�^�i�[
void outDataModel(int dataNum); // �f�[�^�r�o


/* MySQL�p�̍\���� */
MYSQL* mysql;
MYSQL_RES* res;
MYSQL_FIELD* field;
MYSQL_ROW row;

/* �f�[�^�x�[�X��� */
const char host[] = "127.0.0.1";               /* �ڑ��� */
const char user[] = "root";                    /* ���[�U�� */
const char password[] = "kiritori";            /* �p�X���[�h */
const char dbname[] = "nexus_crm";             /* �f�[�^�x�[�X�� */
const char sqlSelect[] = "SELECT * FROM ";   /* �Q�ƌn */
const char sqlTable[] = "EMPLOYEE";   /* �Q�ƃe�[�u�� */


	/* DB���J��(�ڑ�����) */
	int db_open() {
		/* ���������� */
		mysql = mysql_init(0);

		/* MySQL�ɐڑ� */
		if (mysql_real_connect(mysql, host, user, password, dbname, MYSQL_PORT, NULL, 0) == NULL) {
			printf("%s\n", mysql_error(mysql));
			return -1;
		}
		return 0;
	}

	/* DB�����(�ؒf����) */
	int db_close() {
		/* MySQL����ؒf */
		mysql_close(mysql);
		return 0;
	}

/* �E���e�[�u��(EMPLOYEE)����������CSV�o�� */
int select_employee() {
	char sql[200];
	sprintf_s(sql, 200, "%s%s", sqlSelect, sqlTable); // �e�[�u���I�𕶂̍쐬

	/* SQL�̔��s */
	if (mysql_query(mysql, sql) != 0) {
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		return -1;
	}

	/* MySQL����f�[�^���擾 */
	res = mysql_store_result(mysql);
	if (res == NULL) {
		char tableBuf[200];
		sprintf_s(tableBuf, 200, "%s����̃f�[�^�Ǎ��Ɏ��s���܂����B", sqlTable);
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		MessageBox(NULL, tableBuf, "�G���[", MB_OK); // �e�[�u������f�[�^�̓ǂݍ��݂Ɏ��s�B
		return -1;
	}

	/* �E���e�[�u��(EMPLOYEE) �̃t�B�[���h */
	string m_employee_fields[] = { "EMPNO","EMPNO_ED","LIMTYMD","NAME","ENTRYMD","RETRYMD","PASSWORD","LOSTYMD","UPDATE"};

	///* �t�B�[���h�����擾 */
	int num_fields = sizeof m_employee_fields / sizeof m_employee_fields[0];

	int rowNNum = 0; // �s���J�E���g

	/* �f�[�^��ǂݎ���ĕ\�� */
	while (row = mysql_fetch_row(res)) {

		/* 1�t�B�[���h���̃f�[�^���i�[����o�b�t�@ */
		char buffer[50];

		string csv_row_str[20];

		/* �t�B�[���h�̐��������[�v */
		for (int i = 0; i < num_fields; i++) {
			/* 1�t�B�[���h���̃f�[�^���擾 */
			snprintf(buffer, sizeof(buffer), "%s", row[i]);
			csv_row_str[i] = buffer;
		}
		inDataModel(csv_row_str);
		rowNNum++;
	}

	string headTitle = "";

	/* �w�b�_��CSV�L�� */
	for (int j = 0; j < num_fields; j++) {
		if (j == 0) {
			headTitle = m_employee_fields[j];
		}
		else {
			headTitle = headTitle + "," + m_employee_fields[j];
		}
	}

	output_employee_csv(headTitle);

	/* �s������CSV�r�o */
	for (int index = 0; index < rowNNum; index++) {
		outDataModel(index);
	}
	return 0;
}
