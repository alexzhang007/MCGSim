// -------------------------------------------------------------------------
// File:    cTimer
// Desc:    a simple timer (start-stop watch)
//
// Author:  Tomas Akenine-Möller
// History: March, 2000 (started)
//          July 2002, rewrote for PCs
// -------------------------------------------------------------------------

#ifndef C_TIMER_H
#define	C_TIMER_H
#ifdef WIN32
#include <windows.h>
#else 
#include <unistd.h>
#include <sys/time.h>
#endif

class cTimer
{
protected:
#ifdef WIN32
	LARGE_INTEGER mStartTime, mFrequency;
#else 
    struct timeval mStartTime;
    struct timeval mFrequency;
#endif
	double mTotalTime;
public:
	cTimer();
	void start(void);					// starts the watch
	void stop(void);					// adds the time from start() to an internal time variable
	void reset(void);					// resets the internal time variable
	double getTime(void);				// in seconds 
};

#endif

