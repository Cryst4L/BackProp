#pragma once
#include <unistd.h>
#include <sys/time.h>

namespace Backprop
{
class Timer
{
  private:

	struct timeval t0, t1;

  public:

	Timer() { reset(); }

	void reset() 
	{ 
		gettimeofday(&t0, NULL); 
	}

	float getTimeMS() 
	{
		gettimeofday(&t1, NULL);
		double time = (t1.tv_sec  - t0.tv_sec)  * 1e3 +
			          (t1.tv_usec - t0.tv_usec) / 1e3;
		return time;
	}

	float getTimeSec() 
	{
		return 1e-3 * getTimeMS();
	}
};
}

