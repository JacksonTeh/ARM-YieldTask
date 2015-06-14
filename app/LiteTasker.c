#include "LiteTasker.h"

void testingSwitchCase(TaskBlock *tb)
{
	static int here = 0;

	//The following code in this line will executed on
	//every entry on this function
	//e.g doSomething();

	startTask(tb);

	while(1)
	{
		here = 1;
		yield(tb);
		here = 2;
		yield(tb);
		here = 3;
		break;
	}

	endTask(tb);

	//The following code in this line will executed on
	//every exit on this function
	//e.g cleanUp();
}
