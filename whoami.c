#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "_.h"

Integer main(Integer arity, Byte *arguments[arity])
{
	Byte *login = getlogin();
	Byte *user = getenv("USER");
	debug(login);
	debug(user);
	// free(user);
	return 0;
}
