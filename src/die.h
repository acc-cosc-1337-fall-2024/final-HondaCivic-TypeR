#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>

class Die
{
public:
    Die(){std::srand(std::time(0));}
    int roll();
    
private:
    int sides{6}; 
};

#endif