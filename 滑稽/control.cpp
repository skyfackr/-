#include"stdafx.h"
extern musicsystem music;
void on()
{
	sys("cls");
	cout << "³¢ÊÔÆô¶¯\n";
	music.onu();
	return;
}
void off()
{
	sys("cls");
	cout << "³¢ÊÔÖÕÖ¹\n";
	music.stopu();
	return;
}
void musicpause()
{
	sys("cls");
	cout << "³¢ÊÔÔÝÍ£\n";
	music.pauseu();
	return;
}
void status()
{
	cout << "³¢ÊÔÊä³ö×´Ì¬¡£¡£¡£\n";
	Sleep(50);
	music.statusu();
	return;
}