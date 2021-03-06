#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <vector>

#include <fstream>

using namespace std;

void output_employee_csv(string csv_row_str); // ファイル出力を行う必要があるためプロトタイプ宣言

typedef struct Item {
	string EMPNO;       //int型のEMPNO
	string EMPNO_ED;       //int型のEMPNO_ED
	string LIMTYMD;       //int型のLIMTYMD
	string NAME;       //char型のNAME
	string ENTRYMD;       //int型のENTRYMD
	string RETRYMD;       //int型のRETRYMD
	string PASSWORD;       //char型のPASSWORD
	string LOSTYMD;       //int型のLOSTYMD
	string UPDATEMD;       //int型のUPDATEMD
} Item;

vector<Item>dataList;

 void inDataModel(string inData[]){ // データ格納
	
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

 void outDataModel(int dataNum) { // データ排出

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