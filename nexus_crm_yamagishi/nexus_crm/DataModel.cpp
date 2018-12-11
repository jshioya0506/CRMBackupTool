#include "DataModel.h"

/* コンストラクタ */
DataModel::DataModel()
{
}

/* デストラクタ */
DataModel::~DataModel()
{
}

 void DataModel::inDataModel(string inData[]){ // データ格納
	
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

 void DataModel::outDataModel(int dataNum) { // データ排出

	 CsvFileWriter csvFileWriter;
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

	 csvFileWriter.output_employee_csv(csvData);

	 return ;
 }