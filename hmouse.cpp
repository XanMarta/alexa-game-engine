#include "hmouse.h"


void mouse_pack::update()
{
    _update(event.type == SDL_MOUSEBUTTONDOWN);
    position.x = event.motion.x;
    position.y = event.motion.y;
}
