#pragma once;

#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

namespace sj
{
	class synchronizer_b
	{
	public:
		synchronizer_b()
		{
		}
		void wait()
		{
			boost::unique_lock<boost::mutex> lk(m);
			cv.wait(lk);
		}
		void signal()
		{
			cv.notify_all();
		}
	private:
		boost::mutex m;
		boost::condition_variable cv;
	};
}