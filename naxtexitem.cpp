#include "navtexitem.h"


QList<NAVTEXITEM *> navtexitemlist;
static int pos=0;

void setpos(int i)
{
    pos=i;
}

int getpos()
{
    return pos;
}

