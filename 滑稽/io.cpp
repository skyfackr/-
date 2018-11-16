#include"stdafx.h"
inline void pause()
{
	while (!_kbhit()) continue;
	return;
}

inline char press()
{
	pause();
	char ch;
	ch = _getch();
	if (isdigit(ch)) return ch - '0';
	if (islower(ch)) return ch - 'a';
	if (isupper(ch)) return ch - 'A';
	throw("unknowninputtype");
}