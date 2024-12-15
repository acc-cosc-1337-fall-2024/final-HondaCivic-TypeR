#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <vector>
#include <iostream>

class Shooter
{
public:
    Shooter();
    Roll* throw_dice(Die& d1, Die& d2);
    void display_rolled_values() const;
    ~Shooter();

private:
    std::vector<Roll*> rolls;
};

#endif