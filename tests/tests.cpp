// BASIC INCLUDES //
#include <gtest/gtest.h>
#include <stdbool.h>

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.


// EXTERNS //
extern "C" bool helloWorld;
extern "C" bool func_1();
extern "C" int valueOfMovementSpeed;
extern "C" bool valueOfAllowNextRunKeyPress;
extern "C" bool valueOfIsRunning;

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


///[issue]https://github.com/Team-10-But-Better/Craft/issues/5
TEST(tests, Issue5)
{
	EXPECT_EQ(valueOfMovementSpeed,5) << "The movement speed has been changed. This is not a fatal error, but may cause confusion for the player.";
	
	EXPECT_EQ(valueOfAllowNextRunKeyPress,true) << "Running behavior has been modified. This will cause players running ability to not perform as expected.";
	EXPECT_EQ(valueOfIsRunning,false) << "Running behavior has been modified. This will cause players running ability to not perform as expected.";
}

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
