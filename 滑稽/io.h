
#ifndef ___huaji__io_h
#define ___huaji__io_h

namespace ioerr
{
	class inputerr:public exception
	{
	public:inputerr()
		{
			exception("ioerr::inputerr");
		}
	};
}
 void pause();
 char press();
 int pressint();
#endif // !___huaji__io_h

