#include"std.h"
#pragma once
#ifndef _____huaji__music
#define _____huaji__music

class mcimusic
{
	private:
		MCI_OPEN_PARMS open;
		string name;
		inline void namegetu(string s);
//		inline void playmusic();
		inline void openfileu(string s);
		UINT wdd;
		MCI_PLAY_PARMS play;
		inline void idgetu();
//		inline void getstatus();
		MCI_SEEK_PARMS SeekParms;
		bool isplayed = false;
	public:
		inline void loadu(string s);
		inline void onu();
		inline void pauseu();
		inline void stopu();
		inline void skipstartu();
		inline void skipu(int h,int m);
		inline void skipstopu();
		inline void statusu();
};

#endif // !_____huaji__music
