#ifndef LiteTasker_H
#define LiteTasker_H

#include "State.h"

#define initTaskBlock(x)	(x)->state = INITIAL;
#define startTask(x)		switch((x)->state) { case INITIAL:
#define yield(x)			(x)->state = __LINE__; break; case __LINE__:
#define endTask(x) 			}
#define yields(x)			(x)->state = __LINE__; return 1; case __LINE__:

typedef struct
{
	State state;
} TaskBlock;

void testingSwitchCase(TaskBlock *tb);

#endif // LiteTasker_H
