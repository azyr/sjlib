#pragma once

#include <stdint.h>
#include <cstdint>

namespace sj
{

//  Windows
#ifdef _WIN32

#include <intrin.h>
inline uint64_t rdtscp(){
	unsigned int tsc_aux;
	return __rdtscp(&tsc_aux);
}

inline uint64_t rdtscp(unsigned int* tsc_aux){
	return __rdtscp(tsc_aux);
}

inline uint64_t rdtsc(){
	return __rdtsc();
}

//  Linux/GCC
#else

//inline uint64_t rdtsc(){
//    unsigned int lo,hi;
//    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
//    return ((uint64_t)hi << 32) | lo;
//}
//
//inline uint64_t rdtscp(){
//    unsigned int lo,hi;
//    __asm__ __volatile__ ("rdtscp" : "=a" (lo), "=d" (hi));
//    return ((uint64_t)hi << 32) | lo;
//}

// use rdtsc for high-precision tick counter
inline uint64_t tick()
{
	uint32_t tmp[2];
	asm volatile ("rdtsc" : "=a" (tmp[1]), "=d" (tmp[0]) : "c" (0x10) );
	return (((uint64_t)tmp[0]) << 32) | tmp[1];
}
// use rdtscp for high-precision tick counter with pipeline stall
inline uint64_t tickp()
{
	uint32_t tmp[2];
	asm volatile ("rdtscp" : "=a" (tmp[1]), "=d" (tmp[0]) : "c" (0x10) : "memory");
	return (((uint64_t)tmp[0]) << 32) | tmp[1];
}


#endif

}