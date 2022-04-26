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

/// [issue](https://github.com/Team-10-But-Better/Craft/issues/6)
/// This function returns the direction the character should move (-1 for forwards, 1 for backwards, or 0 for not at all).
///
///\param forward : whether moving forwards is desired
///\param backward : whether moving backwards is desired
extern "C" float setJump(int megaJump, float dy);
TEST(tests, issue_6){
	static float returnValue1 =  setJump(1, 0);
	static float returnValue2 = setJump(0, 0);
	static float returnValue3 = setJump(0, 1);
	static float returnValue4 = setJump(1, 1);

	EXPECT_FLOAT_EQ(returnValue1, 40);
	EXPECT_FLOAT_EQ(returnValue2, 8);
	EXPECT_FLOAT_EQ(returnValue3, 1);
	EXPECT_FLOAT_EQ(returnValue4, 1);
}

extern "C" int chooseTree(int choice);
TEST(tests, issue_32)
{
	EXPECT_EQ(chooseTree(0), 10);
	EXPECT_EQ(chooseTree(1), 0);
	EXPECT_EQ(chooseTree(2), 0);
}

//----------------------------------------------------
int main(int argc, char *argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
