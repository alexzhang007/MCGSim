// -------------------------------------------------------------------------
// File:    cTimer
// Desc:    a simple timer (start-stop watch)
//
// Author:  Tomas Akenine-Möller
// History: March, 2000 (started)
//          July 2002, rewrote for PCs
// -------------------------------------------------------------------------

#include "timer.h"

#include "mmgr/mmgr.h"

cTimer::cTimer()
{
   mTotalTime=0.0;
#ifdef WIN32
   QueryPerformanceFrequency(&mFrequency);
#else 
   void *dummy=NULL;
   gettimeofday(&mFrequency,NULL);
#endif
}

void cTimer::start(void)
{
#ifdef WIN32
	QueryPerformanceCounter(&mStartTime);
#else 
   void *dummy=NULL;
   gettimeofday(&mStartTime,NULL);
#endif
}


void cTimer::stop(void)
{
#ifdef WIN32
	LARGE_INTEGER end_time;
	QueryPerformanceCounter(&end_time);
	mTotalTime+=double(end_time.LowPart-mStartTime.LowPart)/mFrequency.LowPart;	
#else 
    void *dummy=NULL;
    struct timeval end_time;
    gettimeofday(&end_time,NULL);
    mTotalTime+=(((double)end_time.tv_sec*1000000.0+end_time.tv_usec)-((double)mStartTime.tv_sec*1000000.0+mStartTime.tv_usec))/1000000.0;
#endif

}


void cTimer::reset(void)
{
   mTotalTime=0.0;
}

double cTimer::getTime(void)  // in seconds
{
   return mTotalTime;
}
