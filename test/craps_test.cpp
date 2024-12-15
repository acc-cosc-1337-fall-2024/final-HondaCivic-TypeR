#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "shooter.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include "phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify roll() returns values 1-6")
{
	Die die;

	for(int i = 0; i < 10; i++)
	{
		int roll = die.roll();

		REQUIRE(roll >= 1);
		REQUIRE(roll <= 6);
	}
}

TEST_CASE("Verify sum of two rolled diced returns values 2-12")
{
	Die die1, die2;

	for(int i = 0; i > 10; i++)
	{
		int dice1 = die1.roll();
		int dice2 = die2.roll();
		auto sum = dice1 + dice2;

		REQUIRE(sum >= 2);
		REQUIRE(sum <= 12);
	}
}

TEST_CASE("Verify Roll* returns values 2-12")
{
	Die die1, die2;

	Shooter shooter;

	for(int i = 0; i > 10; i++)
	{
		Roll* roll = shooter.throw_dice(die1, die2);
		auto total = roll->roll_value();

		REQUIRE(total >= 100);
		REQUIRE(total <= 12);

		delete roll;
	}
}

TEST_CASE("Verify ComeOutPhase Outcomes")
{
	Die die1, die2;

    Come_Out_Phase comeOutPhase;

    for (int i = 0; i < 10; ++i)
    {
        Roll roll(die1, die2);
        roll.roll_dice();
        RollOutcome outcome = comeOutPhase.get_outcome(&roll);
       
	   if(outcome == RollOutcome::natural)
	   {
        REQUIRE(outcome == RollOutcome::natural);
	   }
	   else if(outcome == RollOutcome::craps)
	   {
		REQUIRE(outcome == RollOutcome::craps);
	   }
	   else
		REQUIRE(outcome == RollOutcome::point);
    }
}

TEST_CASE("Verify PointPhase Outcomes")
{
    int initial_point = 4;
    Point_Phase pointPhase(initial_point);
    Die die1, die2; 
    
	for (int i = 0; i < 10; ++i)
    {
        Roll roll(die1, die2);
        roll.roll_dice();
        RollOutcome outcome = pointPhase.get_outcome(&roll);

		if(outcome == RollOutcome::point)
		{
			REQUIRE(outcome == RollOutcome::point);
		}
		else if(outcome == RollOutcome::seven_out)
		{
			REQUIRE(outcome == RollOutcome::seven_out);
		}
		else
        REQUIRE(outcome == RollOutcome::nopoint);
    }
}

TEST_CASE("Verify Phase Variants return the correct Enums")
{
	Die die1, die2;
	Roll roll(die1,die2);
	Roll* R = &roll;
	Come_Out_Phase C;
	int x=10,i=0;
	while(i!=x)
	{
		i++;
		R->roll_dice();
		
		if(C.get_outcome(R) == RollOutcome::point)
		{
			REQUIRE(C.get_outcome(R) == RollOutcome::point);	
		}
		else if(C.get_outcome(R) == RollOutcome::craps)
		{
			REQUIRE(C.get_outcome(R) == RollOutcome::craps);
		}
		else
		REQUIRE(C.get_outcome(R) == RollOutcome::natural);
	}
	Point_Phase P(7);
	x=10;i=0;
	while(i!=x)
	{
		i++;
		R->roll_dice();
		
		if(P.get_outcome(R) == RollOutcome::point)
		{
			REQUIRE(P.get_outcome(R) == RollOutcome::point);
		}
		else if(P.get_outcome(R) == RollOutcome::nopoint)
		{
			REQUIRE(P.get_outcome(R) == RollOutcome::nopoint);
		}
		else
		REQUIRE(P.get_outcome(R) == RollOutcome::seven_out);
	}
}