#pragma once

#include "cpu.hpp"

namespace sj
{

	class timer_rdtscp
	{
	public:
		timer_rdtscp(const double &cpuspeed) : frequency(cpuspeed) 
		{ 
			this->s_ticks = 0;
			this->accumulated = 0;
		};
		void start()
		{
			this->s_ticks = rdtscp();
		}
		inline void stop()
		{
			uint64_t now = rdtscp();

			if (!running())
				return;

			this->accumulated += now - this->s_ticks;
			this->s_ticks = 0;
		}
		void restart()
		{
			this->s_ticks = rdtscp();
			this->accumulated = 0;
		}
		inline bool running()
		{
			return this->s_ticks != 0;
		}
		inline uint64_t elapsed()
		{
			uint64_t now = rdtscp();

			if (!running())
				return this->accumulated;

			return this->accumulated + now - this->s_ticks;
		}
		inline double elapsed_ns()
		{
			auto elapsed = this->elapsed();
			return elapsed / frequency * 1e9;
		}
		inline double elapsed_us()
		{
			auto elapsed = this->elapsed();
			return elapsed / frequency * 1e6;
		}
		inline double elapsed_ms()
		{
			auto elapsed = this->elapsed();
			return elapsed / frequency * 1e3;
		}
		inline double elapsed_s()
		{
			auto elapsed = this->elapsed();
			return elapsed / frequency;
		}
	private:
		double frequency;
		uint64_t s_ticks;
		uint64_t accumulated;
	};


}
