// BASIC INCLUDES //
#include <gtest/gtest.h>
#include <stdbool.h>
#include <math.h>

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.

extern "C" bool helloWorld;
extern "C" bool func_1();

/// Externals used for testing [Issue #7]: https://github.com/Team-10-But-Better/Craft/issues/7
extern "C" double mouseDPIMultiplier;
extern "C" double keyDPIMultiplier;
extern "C" void incrementDPI();
extern "C" void decrementDPI();
extern "C" void setDefaultDPI();

/// Externals used for testing [Issue #41]: https://github.com/Team-10-But-Better/Craft/issues/41
extern "C" int isDefinedCraftKey(char *str, int start, int end);

/// Externals used for testing [Issue: #66]: https://github.com/Team-10-But-Better/Craft/issues/66
/// playerStatus is also used for testing [Issue #72]: https://github.com/Team-10-But-Better/Craft/issues/72
typedef struct
{
	double health;
	double hunger;
	double enchant;
} SurvivalStatus;
extern "C" SurvivalStatus playerStatus;
extern "C" void takeFallDamage(int damage);
extern "C" void initializeSurvivalStatus();

//----------------------------------------------------
TEST(Assert, empty)
{
	GTEST_ASSERT_EQ(true, true);
}

//----------------------------------------------------
TEST(tests, issueFoo)
{
	EXPECT_EQ(helloWorld, true);
}

TEST(tests, issueBar)
{
	bool returnValue = func_1;
	EXPECT_EQ(true, returnValue);
}

TEST(tests, issue7)
{
	setDefaultDPI();

	// Creation of variables used for comparison
	double initialMouseDPIMultiplier = mouseDPIMultiplier;
	double initialKeyDPIMultiplier = keyDPIMultiplier;

	// Testing of incrementation of DPI
	// Test one incrementation
	incrementDPI();
	EXPECT_EQ(initialMouseDPIMultiplier + .0001, mouseDPIMultiplier) << "Issue 7 Testing Error 1: mouseDPIMultiplier was not incremented by .0001\n";
	EXPECT_EQ(initialKeyDPIMultiplier + .1, keyDPIMultiplier) << "Issue 7 Testing Error 2: keyDPIMultiplier was not incremented by .1\n";

	// Testing max incrementations
	for (int i = 0; i < 10; i++)
		incrementDPI();
	EXPECT_EQ(round(initialMouseDPIMultiplier + .0009), round(mouseDPIMultiplier)) << "Issue 7 Testing Error 3: mouseDPIMultiplier was not equal to 1\n";
	EXPECT_EQ(round(initialKeyDPIMultiplier + .9), round(keyDPIMultiplier)) << "Issue 7 Testing Error 4: keyDPIMultiplier was not equal to 2\n";

	// Testing resetting DPIs to default values
	setDefaultDPI();
	EXPECT_EQ(initialMouseDPIMultiplier, mouseDPIMultiplier) << "Issue 7 Testing Error 5: mouseDPIMultiplier was not equal to .0001\n";
	EXPECT_EQ(initialKeyDPIMultiplier, keyDPIMultiplier) << "Issue 7 Testing Error 6: keyDPIMultiplier was not equal to .1\n";

	// Testing one decrementation
	decrementDPI();
	EXPECT_EQ(initialMouseDPIMultiplier - .0001, mouseDPIMultiplier) << "Issue 7 Testing Error 7: mouseDPIMultiplier was not decremented by .0001\n";
	EXPECT_EQ(initialKeyDPIMultiplier - .1, keyDPIMultiplier) << "Issue 7 Testing Error 8: keyDPIMultiplier was not decremented by .1\n";

	// Testing max decrementation
	decrementDPI();
	EXPECT_EQ(initialMouseDPIMultiplier - .0001, mouseDPIMultiplier) << "Issue 7 Testing Error 9: mouseDPIMultiplier was not equal to 0\n";
	EXPECT_EQ(initialKeyDPIMultiplier - .1, keyDPIMultiplier) << "Issue 7 Testing Error 10: keyDPIMultiplier was not equal to 1\n";
}

TEST(tests, issue41)
{
	// Testing a line of text that does not define a CRAFT keybind
	EXPECT_EQ(isDefinedCraftKey("This is not a defined craft key", 8, 13), 0) << "Issue 41 Testing Error 1: test found string to be a defined CRAFT keybind\n";

	// Testing a line of text that does define a CRAFT keybind
	EXPECT_EQ(isDefinedCraftKey("#define CRAFT_KEY_TESTING_ISSUE_41", 8, 13), 1) << "Issue 41 Testing Error 2: test found string to not be a defined CRAFT keybind\n";
}

/// As a part of [Issue #66]: https://github.com/Team-10-But-Better/Craft/issues/66
/// Add a test to show that a player has a measure of health
TEST(tests, issue66health)
{
	initializeSurvivalStatus();
	EXPECT_EQ(playerStatus.health, 10) << "Issue 66 Testing Health Error 1: Health was not initialized to 10.\n";
}


/// As a part of [Issue #66]: https://github.com/Team-10-But-Better/Craft/issues/66
/// Add a test to show that a player can take fall damage
TEST(tests, issue66fallDamage)
{
	EXPECT_EQ(playerStatus.health, 10) << "Issue 66 Testing Fall Damage Error 1: Player's health was not set to 10.\n";
	takeFallDamage(1);
	EXPECT_EQ(playerStatus.health, 9) << "Issue 66 Testing Fall Damage Error 2: Player's health was not decremented by 1.\n";
	takeFallDamage(10);
	EXPECT_EQ(playerStatus.health, 0) << "Issue 66 Testing Fall Damage Error 3: Player's health was not decremented to the minimum: 0.\n";
}

/// As a part of [Issue #72]: https://github.com/Team-10-But-Better/Craft/issues/72
/// Add a test to show that a player's hunger can be measured
TEST(tests, issue77hunger)
{
	EXPECT_EQ(playerStatus.hunger, 10) << "Issue 72 Testing Hunger Error 1: Player's hunger was not set to 10.\n";
	int time = 0;
	for (int i = 0; i <= 1001; i++)
	{
		time++;
	}
	if (time > 1000)
	{
		playerStatus.hunger--;
		time = 0;
	}
	EXPECT_EQ(playerStatus.hunger, 9) << "Issue 72 Testing Hunger Error 2: Player's hunger was not 9 after first time period.\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= 1001; j++)
		{
			time++;
		}
		if (time > 1000)
		{
			if (playerStatus.hunger > 0)
				playerStatus.hunger--;
			time = 0;
		}
	}
	EXPECT_EQ(playerStatus.hunger, 0) << "Issue 72 Testing Hunger Error 3: Player's hunger was not 0 after max time periods.\n";
}
extern "C" int craft_main(int argc, char *argv[]);

//----------------------------------------------------
int main(int argc, char *argv[])
{
	craft_main(argc, argv);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
