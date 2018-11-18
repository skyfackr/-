
#ifndef _____huaji__music
#define _____huaji__music
#include"std.h"

class musicsystem
{
	private:
		MCI_OPEN_PARMS open;
		string name;
		 void namegetu(string s);
//		 void playmusic();
		 void openfileu(LPCWSTR s);
		UINT wdd;
		MCI_PLAY_PARMS play;
		 void idgetu();
//		 void getstatus();
		MCI_SEEK_PARMS SeekParms;
		bool isplayed = false;
	public:
		 void loadu(LPCWSTR s);
		 void onu();
		 void pauseu();
		 void stopu();
		 void skipstartu();
		 void skipu(int h,int m);
		 void skipstopu();
		 void statusu();
};

#endif // !_____huaji__music
