#include <iostream>

#define SHOWDEF_STR(x)   #x
#define SHOW_DEFINE(x) printf("%s=%s\n",\
	#x, SHOWDEF_STR(x)); std::cout.flush();
