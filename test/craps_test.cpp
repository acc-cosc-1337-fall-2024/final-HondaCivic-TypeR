#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "shooter.h"

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