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

///[issue]https://github.com/Team-10-But-Better/Craft/issues/11
TEST(tests, Issue11){
	#ifdef __linux__
	{
		EXPECT_TRUE(true);
		EXPECT_EQ(system("mpg321 -h > /dev/null 2>&1"),0) << "This indicates you have failed to install mpg321 package as instructed for audio. Please install this dependency";	
	}
	#else
	{
		EXPECT_TRUE(false) << "This indicates you are not running the game on a linux OS. This is not fatal, but you will also not experience audio."; 
	}
	#endif
	
	struct stat buffer;
	
	int exist = stat("../audio/background_music.mp3",&buffer);
	EXPECT_EQ(exist,0) << "This indicates and audio file is missing";
	
	exist = stat("../audio/sound_effect_fly.mp3",&buffer);
	EXPECT_EQ(exist,0) << "This indicates and audio file is missing";
	
	exist = stat("../audio/sound_effect_hit.mp3",&buffer);
	EXPECT_EQ(exist,0) << "This indicates and audio file is missing";
	
	exist = stat("../audio/sound_effect_jump.mp3",&buffer);
	EXPECT_EQ(exist,0) << "This indicates and audio file is missing";
}

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
