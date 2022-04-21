// BASIC INCLUDES //
#include <gtest/gtest.h>
#include <stdbool.h>

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.

extern "C" bool helloWorld;
extern "C" bool func_1();
//----------------------------------------------------
TEST(Assert, empty) { GTEST_ASSERT_EQ(true, true); }

//----------------------------------------------------
TEST(tests, issueFoo){
	EXPECT_EQ(helloWorld, true);
}
TEST(tests, issueBar){
	bool returnValue = func_1;
	EXPECT_EQ(true, returnValue);
}

extern "C" int craft_main(int argc, char* argv[]);

extern "C" int getGroundedMovementSpeed(bool teleport, bool *teleportHeldLastFrame, int groundedMovementSpeed);

/// [issue](https://github.com/Team-10-But-Better/Craft/issues/9)
TEST(tests, issue9)
{
	bool teleportHeld = false;
	EXPECT_EQ(getGroundedMovementSpeed(false, &teleportHeld, 5), 5);
	teleportHeld = true;
	EXPECT_EQ(getGroundedMovementSpeed(false, &teleportHeld, 5), 5);
	teleportHeld = false;
	EXPECT_EQ(getGroundedMovementSpeed(true, &teleportHeld, 5), 600);
	teleportHeld = true;
	EXPECT_EQ(getGroundedMovementSpeed(true, &teleportHeld, 5), 5);
}

extern "C" int getCrouchingHeight(bool crouch, bool *crouchingHeldLastFrame);
extern "C" bool isCrouching(bool crouch);

/// [issue](https://github.com/Team-10-But-Better/Craft/issues/69)
TEST(test, issue69)
{

	bool crouchingHeldLastFrame = false;
	EXPECT_EQ(getCrouchingHeight(false, &crouchingHeldLastFrame), 2);
	EXPECT_EQ(crouchingHeldLastFrame, false);
	crouchingHeldLastFrame = false;
	EXPECT_EQ(getCrouchingHeight(true, &crouchingHeldLastFrame), 1);
	EXPECT_EQ(crouchingHeldLastFrame, true);
	crouchingHeldLastFrame = true;
	EXPECT_EQ(getCrouchingHeight(false, &crouchingHeldLastFrame), 2);
	EXPECT_EQ(crouchingHeldLastFrame, false);
	crouchingHeldLastFrame = true;
	EXPECT_EQ(getCrouchingHeight(true, &crouchingHeldLastFrame), 1);
	EXPECT_EQ(crouchingHeldLastFrame, true);

	EXPECT_EQ(isCrouching(true), true);
	EXPECT_EQ(isCrouching(false), false);
}

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
