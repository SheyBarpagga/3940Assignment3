#include <stddef.h>
#include <cstring>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>

#include "ConsoleAppClient.h"

//Note: compile this separately from the server. This is supposed to be a different program, and is only included here to
// have all the code in 1 place, and to more easily include it in our GitHub repo.

using std::cout;
using std::endl;
