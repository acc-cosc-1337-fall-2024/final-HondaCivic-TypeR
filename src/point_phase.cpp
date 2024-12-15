#include "point_phase.h"

Point_Phase::Point_Phase(int p) : point(p) {}

RollOutcome Point_Phase::get_outcome(Roll* roll) {
    int value = roll->roll_value();
    if (value == point) {
        return RollOutcome::point;
    } else if (value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}