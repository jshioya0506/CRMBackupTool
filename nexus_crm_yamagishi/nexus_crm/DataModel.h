#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include <vector>

#include "CsvFileWriter.h"
using namespace std;

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

class DataModel
{
public:
	DataModel();
	~DataModel();

	void inDataModel( string inData[] );
	void outDataModel( int dataNum );

private:
	vector <Item> dataList;

};