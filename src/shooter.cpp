#include "shooter.h"

using std::cout;

Shooter::Shooter() {}

Roll* Shooter::throw_dice(Die& d1, Die& d2)
{
    Roll* roll = new Roll(d1, d2);
    roll->roll_dice();
    rolls.push_back(roll);

    return roll;
}

void Shooter::display_rolled_values() const
{
    for(Roll* roll : rolls)
    {
        cout<<roll->roll_value()<< "\n";
    }
}

Shooter::~Shooter()
{
    for(Roll* roll : rolls)
    {
        delete roll;
    }
} 