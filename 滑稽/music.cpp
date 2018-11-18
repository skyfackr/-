#include"stdafx.h"
#include<random>
#include<time.h>
 void musicsystem::openfileu(LPCWSTR s)
{
	open.lpstrDeviceType = NULL;
//	open.lpstrElementName = L s;
	open.lpstrElementName = s;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&open);
}
 void musicsystem::namegetu(string s)
{
	name.clear();
	name = s;
	return;
}
 void musicsystem::loadu(LPCWSTR s)
{
//	namegetu(s);
	openfileu(s);
	isplayed = false;
		idgetu();
	
	return;
}
 void musicsystem::idgetu()
{
	play.dwFrom = 0;//ָ����ʼ���ŵ�λ�ã���λms
	wdd = open.wDeviceID;//wdd�����豸id
//	mciSendCommand(wdd, MCI_PLAY, MCI_FROM, (DWORD)&PLAY);
}
 void musicsystem::onu()
{
	if (!isplayed)
	{
		isplayed = true;
		mciSendCommand(wdd, MCI_PLAY, MCI_FROM, (DWORD)&play);
		return;
	}
	mciSendCommand(wdd, MCI_RESUME, MCI_FROM, (DWORD)&play);//MCI_RESUMEָ������ͣ���豸��������
	return;
}
 void musicsystem::pauseu()
{
	mciSendCommand(wdd, MCI_PAUSE, MCI_FROM, (DWORD)&play);//MCI_PAUSEָ���豸��ͣ����
	return;
}
 void musicsystem::stopu()
{
	mciSendCommand(wdd, MCI_STOP, MCI_FROM, (DWORD)&play);//MCI_STOPָ���豸ֹͣ����
	return;
}
 void musicsystem::skipstartu()
{
	mciSendCommand(wdd, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	return;
}
 void musicsystem::skipu(int h, int m)
{
	SeekParms.dwTo = (h * 60 + m) * 1000;
	mciSendCommand(wdd, MCI_SEEK, MCI_TO | MCI_WAIT, (DWORD)(LPVOID)&SeekParms);
	return;
}
 void musicsystem::skipstopu()
{
	mciSendCommand(wdd, MCI_SEEK, MCI_SEEK_TO_END, NULL);
	return;
}

 void musicsystem::statusu()
{
	sys("cls");
	MCI_STATUS_PARMS status;
	status.dwItem = MCI_STATUS_MODE;
	mciSendCommand(wdd, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)&status);
	cout << "����״̬�� ";
	if (status.dwReturn == 526)
	{
		cout << "on\n";
	}
	else cout << "off\n";
	cout << "status:" << status.dwReturn << endl;
	cout << "��ǰʱ�䣺 ";
	status.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(wdd, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)&status);
	cout << status.dwReturn << endl;
	cout << "\a";
	pause();
	sys("cls");
	return;
}
