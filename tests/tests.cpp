// BASIC INCLUDES //
#include <gtest/gtest.h>
#include <stdbool.h>

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.

extern "C" bool helloWorld;
extern "C" bool func_1();
extern "C" bool allow_binocular_mode_keyPress;
extern "C" bool binocular_mode_enabled;
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

///[issue]https://github.com/Team-10-But-Better/Craft/issues/64
TEST(tests, issue64){
	EXPECT_EQ(allow_binocular_mode_keyPress, true);
	EXPECT_EQ(binocular_mode_enabled, false);
}

extern "C" int craft_main(int argc, char* argv[]);

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
