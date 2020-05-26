#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED

#include <vector>
using namespace std;


class SignalPack
{
    public:

        void emit();
        void connect(void (*func)());

    private:

        vector<void(*)()> _func;
};


#endif // SIGNAL_H_INCLUDED
