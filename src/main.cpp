#include <iostream>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    std::srand(std::time(0));
    Die die1, die2;
    Shooter shooter;
 
    Roll* roll = shooter.throw_dice(die1, die2);
    std::cout << "Rolled " << roll->roll_value() << ". Start of point phase." << std::endl;
    int point = roll->roll_value();
    std::cout << "Roll until " << point << " or a 7 is rolled" << std::endl;
  
    Point_Phase point_phase(point);

    while (true) 
	{
        roll = shooter.throw_dice(die1, die2);
        int rolled_value = roll->roll_value();
        std::cout << "Rolled " << rolled_value << ". ";
        RollOutcome outcome = point_phase.get_outcome(roll);
        if (outcome == RollOutcome::point) {
            std::cout << "Point matched!" << std::endl;
            break;
        } else if (outcome == RollOutcome::seven_out) {
            std::cout << "End of point phase." << std::endl;
            break;
        } else {
            std::cout << "Roll again!" << std::endl;
        }
    }
    shooter.display_rolled_values();
    
    return 0;
}