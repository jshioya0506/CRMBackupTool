#include "stdafx.h"
#include "dbBackupToolMain.h"

int main(int argc, char *argv[])
{
	/* �N���������w�肳��Ă��邩�`�F�b�N */
	if (argc <= 1) {
		MessageBox(NULL, "�o�b�N�A�b�v�t�@�C���ۊǏꏊ���w�肳��Ă��܂���B", "�G���[", MB_OK); // �N�������Ƀo�b�N�A�b�v�t�@�C���ۊǏꏊ���w�肳��Ă��Ȃ��B
		return EXIT_FAILURE; // �ُ�I��
	}

	/* �N�������̃t�H�[�}�b�g�Ɉُ킪�Ȃ����`�F�b�N */
	if (argc >= 3) {
		MessageBox(NULL, "�����̎w��Ɍ�肪����܂��B", "�G���[", MB_OK); // �N�������̃t�H�[�}�b�g�ُ�B
		return EXIT_FAILURE; // �ُ�I��
	}

	DbBackupToolMain dbBackupToolMain;
	dbBackupToolMain.main(argv[1]);

	return 0;
}
