// 滑稽.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
musicsystem music;

int main()
{
	cout << "尝试作死\n";
	music.loadu(L"MEGALOVANIA.mp3");
	pause();
	cout << "尝试启动\n";
	music.onu();
	pause();
	cout << "尝试输出状态。。。\n";
	music.statusu();
	pause();
	cout << "尝试暂停\n";
	music.pauseu();
	pause();
	cout << "尝试输出状态。。。\n";
	music.statusu();
	pause();
	cout << "尝试启动\n";
	music.onu();
	pause();
	cout << "尝试输出状态。。。\n";
	music.statusu();
	pause();
	cout << "溜了\a";
	music.stopu();
	return 0;
}

