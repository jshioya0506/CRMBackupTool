#include "dbBackupToolMain.h"


const char *employeeCsvFile = "Employee.csv";
string strEmployeeCsvFile = string(employeeCsvFile);
string separation = "\\";

/* �R���X�g���N�^ */
DbBackupToolMain::DbBackupToolMain()
{
}

/* �f�X�g���N�^ */
DbBackupToolMain::~DbBackupToolMain()
{
}

/* ���C���֐� */
int DbBackupToolMain:: main(char* argv)
{
	DataAccessObject dataAccessObject;
	CsvFileWriter csvFileWriter;
	bool databaseOpenflg = false; // �f�[�^�x�[�X�̃I�[�v����ԃt���O

	/* DB�ڑ� */
	if (dataAccessObject.db_open() == -1) {
		MessageBox(NULL, "�f�[�^�x�[�X�̐ڑ��Ɏ��s���܂����B", "�G���[", MB_OK); // �f�[�^�x�[�X�̐ڑ��Ɏ��s�B
		return EXIT_FAILURE; // �ُ�I��
	}

	databaseOpenflg = true;

	/* �t�@�C�����J�� */
	if (csvFileWriter.file_open( string(argv) + separation + strEmployeeCsvFile) == EXIT_FAILURE ){
		char passBuf[200];
		sprintf_s(passBuf, 200, "�o�̓t�@�C��%s�̏o�͂Ɏ��s���܂����B", employeeCsvFile);

		MessageBox(NULL, passBuf, "�G���[", MB_OK); // �o�̓t�@�C���̏o�͂Ɏ��s�B

	}
	else {
		/* �E���e�[�u��(EMPLOYEE)����������CSV�o�� */
		if (dataAccessObject.select_employee() == -1) {
			databaseOpenflg = false; // SQL�̔��s�����MySQL����f�[�^���擾�Ɏ��s�����ꍇ�f�[�^�x�[�X�͊��ɃN���[�Y���Ă���
		}
	}

	/* �t�@�C������� */
	csvFileWriter.file_close();

	/* DB�ؒf */
	if (databaseOpenflg) {
		dataAccessObject.db_close();
	}
	return EXIT_SUCCESS;
}
