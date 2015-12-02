#pragma once

/*
Node�� ����
 - name : ��������� �̸�
 - desc : �ο�����
 - freq : ���õ� �󵵼�
*/
typedef struct LunchPlaceInfo {
	char* name;
	char* desc;
	int freq;
	LunchPlaceInfo* pNext;
}LunchPlaceInfo;

class Place
{
public:
	Place();
	~Place();
	char* getName();
	char* getDesc();
	int getFreq();

private:
	char* mName;
	char* mDesc;
	int mFreq;

private:

};