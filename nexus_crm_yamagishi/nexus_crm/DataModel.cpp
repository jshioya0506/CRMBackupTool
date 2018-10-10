#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <vector>

#include <fstream>

using namespace std;

void output_employee_csv(string csv_row_str); // �t�@�C���o�͂��s���K�v�����邽�߃v���g�^�C�v�錾

typedef struct Item {
	string EMPNO;       //int�^��EMPNO
	string EMPNO_ED;       //int�^��EMPNO_ED
	string LIMTYMD;       //int�^��LIMTYMD
	string NAME;       //char�^��NAME
	string ENTRYMD;       //int�^��ENTRYMD
	string RETRYMD;       //int�^��RETRYMD
	string PASSWORD;       //char�^��PASSWORD
	string LOSTYMD;       //int�^��LOSTYMD
	string UPDATEMD;       //int�^��UPDATEMD
} Item;

vector<Item>dataList;

 void inDataModel(string inData[]){ // �f�[�^�i�[
	
	Item a;

	a.EMPNO = inData[0];
	a.EMPNO_ED = inData[1];
	a.LIMTYMD = inData[2];
	a.NAME = inData[3];
	a.ENTRYMD = inData[4];
	a.RETRYMD = inData[5];
	a.PASSWORD = inData[6];
	a.LOSTYMD = inData[7];
	a.UPDATEMD = inData[8];

	dataList.push_back(a);

	return ;
}

 void outDataModel(int dataNum) { // �f�[�^�r�o

	 string csvData = "";

	 csvData = dataList[dataNum].EMPNO;
	 csvData = csvData + "," + dataList[dataNum].EMPNO_ED;
	 csvData = csvData + "," + dataList[dataNum].LIMTYMD;
	 csvData = csvData + "," + dataList[dataNum].NAME;
	 csvData = csvData + "," + dataList[dataNum].ENTRYMD;
	 csvData = csvData + "," + dataList[dataNum].RETRYMD;
	 csvData = csvData + "," + dataList[dataNum].PASSWORD;
	 csvData = csvData + "," + dataList[dataNum].LOSTYMD;
	 csvData = csvData + "," + dataList[dataNum].UPDATEMD;

	 output_employee_csv(csvData);

	 return ;
 }