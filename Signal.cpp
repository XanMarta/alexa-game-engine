#include "Signal.h"


void SignalPack::emit()
{
    for (int i = 0; i < _func.size(); i++)
    {
        _func[i]();
    }
}

void SignalPack::connect(void (*func)())
{
    _func.push_back(func);
}
