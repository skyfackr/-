#include"stdafx.h"
using ioerr::inputerr;
#ifdef pausedebug
void pause()
{
	system("pause");
	return;
}
#endif // pausedebug
#ifndef pausedebug
 void pause()
{
	 char ch ;
	 while (_kbhit()) ch=_getch();
	while (!_kbhit()) continue;
	ch = _getch();
	Sleep(100);
	return;
}
#endif //pausedebug
 char press()
{
	 while (!_kbhit()) continue;
	char ch;
	ch = _getch();
	return ch;
	
}
 int pressint()
{
	 while (!_kbhit()) continue;
	char ch=_getch();
	if (isdigit(ch)) return ch - '0';
	throw inputerr() ;
}