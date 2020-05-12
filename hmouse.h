#ifndef HMOUSE_H_INCLUDED
#define HMOUSE_H_INCLUDED


#include "hbase_input.h"


class mouse_pack : public baseinput_pack
{
    public:

        void update();

        Vector2 position = {0, 0};

};


#endif // HMOUSE_H_INCLUDED
