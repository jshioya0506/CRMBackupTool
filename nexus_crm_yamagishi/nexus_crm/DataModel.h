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