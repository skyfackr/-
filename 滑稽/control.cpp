#include"stdafx.h"
extern musicsystem music;
void on()
{
	sys("cls");
	cout << "��������\n";
	music.onu();
	return;
}
void off()
{
	sys("cls");
	cout << "������ֹ\n";
	music.stopu();
	return;
}
void musicpause()
{
	sys("cls");
	cout << "������ͣ\n";
	music.pauseu();
	return;
}
void status()
{
	cout << "�������״̬������\n";
	Sleep(50);
	music.statusu();
	return;
}