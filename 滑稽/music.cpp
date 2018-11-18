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
	play.dwFrom = 0;//指定开始播放的位置，单位ms
	wdd = open.wDeviceID;//wdd储存设备id
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
	mciSendCommand(wdd, MCI_RESUME, MCI_FROM, (DWORD)&play);//MCI_RESUME指定被暂停的设备继续播放
	return;
}
 void musicsystem::pauseu()
{
	mciSendCommand(wdd, MCI_PAUSE, MCI_FROM, (DWORD)&play);//MCI_PAUSE指定设备暂停播放
	return;
}
 void musicsystem::stopu()
{
	mciSendCommand(wdd, MCI_STOP, MCI_FROM, (DWORD)&play);//MCI_STOP指定设备停止播放
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
	cout << "播放状态： ";
	if (status.dwReturn == 526)
	{
		cout << "on\n";
	}
	else cout << "off\n";
	cout << "status:" << status.dwReturn << endl;
	cout << "当前时间： ";
	status.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(wdd, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)&status);
	cout << status.dwReturn << endl;
	cout << "\a";
	pause();
	sys("cls");
	return;
}
