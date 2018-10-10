#include<iostream>
#include<stdio.h>
#include<winsock2.h>
#include"Link_Mysql.h"
#include"mdspi.h"
#pragma comment(lib,"libmysql.lib")
#pragma comment (lib, "thostmduserapi.lib")
#pragma comment (lib, "thosttraderapi.lib")

using namespace std;

// ---- ȫ�ֱ��� ---- //
// ��������
TThostFtdcBrokerIDType gBrokerID = "9999";                         // ģ�⾭���̴���
TThostFtdcInvestorIDType gInvesterID = "";                         // Ͷ�����˻���
TThostFtdcPasswordType gInvesterPassword = "";                     // Ͷ��������

																   // �������
CThostFtdcMdApi *g_pMdUserApi = nullptr;                           // ����ָ��
char gMdFrontAddr[] = "tcp://180.168.146.187:10010";               // ģ������ǰ�õ�ַ
char *g_pInstrumentID[] = { "rb1901" };                            // �����Լ�����б��С��ϡ���֣��������ѡһ��
int instrumentNum = 1;                                             // �����Լ��������

int main()
{

	// �˺�����
	cout << "�������˺ţ� ";
	scanf("%s", gInvesterID);
	cout << "���������룺 ";
	scanf("%s", gInvesterPassword);

	// ��ʼ�������߳�
	cout << "��ʼ������..." << endl;
	g_pMdUserApi = CThostFtdcMdApi::CreateFtdcMdApi();   // ��������ʵ��
	CThostFtdcMdSpi *pMdUserSpi = new mdspi;       // ��������ص�ʵ��
	g_pMdUserApi->RegisterSpi(pMdUserSpi);               // ע���¼���
	g_pMdUserApi->RegisterFront(gMdFrontAddr);           // ��������ǰ�õ�ַ
	g_pMdUserApi->Init();                                // ��������

														 // �ȵ��߳��˳�
	g_pMdUserApi->Join();
	delete pMdUserSpi;
	g_pMdUserApi->Release();

	getchar();
	return 0;
}