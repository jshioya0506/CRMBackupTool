#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <vector>

#include <fstream>

using namespace std;

void output_employee_csv(string csv_row_str); // ÉtÉ@ÉCÉãèoóÕÇçsÇ§ïKóvÇ™Ç†ÇÈÇΩÇﬂÉvÉçÉgÉ^ÉCÉvêÈåæ

typedef struct Item {
	string EMPNO;       //intå^ÇÃEMPNO
	string EMPNO_ED;       //intå^ÇÃEMPNO_ED
	string LIMTYMD;       //intå^ÇÃLIMTYMD
	string NAME;       //charå^ÇÃNAME
	string ENTRYMD;       //intå^ÇÃENTRYMD
	string RETRYMD;       //intå^ÇÃRETRYMD
	string PASSWORD;       //charå^ÇÃPASSWORD
	string LOSTYMD;       //intå^ÇÃLOSTYMD
	string UPDATEMD;       //intå^ÇÃUPDATEMD
} Item;

vector<Item>dataList;

 void inDataModel(string inData[]){ // ÉfÅ[É^äiî[
	
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

 void outDataModel(int dataNum) { // ÉfÅ[É^îrèo

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