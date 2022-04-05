// BASIC INCLUDES //
#include <gtest/gtest.h>
#include <stdbool.h>

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.

extern "C" bool helloWorld;
extern "C" bool func_1();
extern "C" bool allow_auto_camera_keyPress;
extern "C" bool camera_auto_enabled;
	//----------------------------------------------------
	TEST(Assert, empty)
{
	GTEST_ASSERT_EQ(true, true);
}

//----------------------------------------------------
TEST(tests, issueFoo){
	EXPECT_EQ(helloWorld, true);
}
TEST(tests, issueBar){
	bool returnValue = func_1;
	EXPECT_EQ(true, returnValue);
}

///[issue]https://github.com/Team-10-But-Better/Craft/issues/10
TEST(tests, issue10){
	EXPECT_EQ(allow_auto_camera_keyPress, true);
	EXPECT_EQ(camera_auto_enabled, false);
}

extern "C" int craft_main(int argc, char* argv[]);

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
