// BASIC INCLUDES //
#include "../src/ring.c"
#include "../src/ring.h"
#include <gtest/gtest.h>
#include <stdbool.h>
//  /home/user/issue85/Craft/src/ring.h

//never include c files, you can rename main.c to craftma
//TESTING FILE INCLUDES //
//#include "../src/deleteme.c"
//#include "../src/main.c" <--- SO MANY ERRORS!!!!!!!!!!!!!.

extern "C" bool helloWorld;
extern "C" int autoWalkGlobal;
//----------------------------------------------------
TEST(Assert, empty) { GTEST_ASSERT_EQ(true, true); }

//----------------------------------------------------
TEST(tests, issue3){
	EXPECT_EQ(autoWalkGlobal, 0);
}


/*extern "C" void ring_alloc(Ring *ring, int capacity);
extern "C" void ring_free(Ring *ring);
extern "C" int ring_empty(Ring *ring);
extern "C" int ring_full(Ring *ring);
extern "C" int ring_size(Ring *ring);
extern "C" void ring_grow(Ring *ring);
extern "C" void ring_put(Ring *ring, RingEntry *entry);
extern "C" void ring_put_block(Ring *ring, int p, int q, int x, int y, int z, int w);
extern "C" void ring_put_light(Ring *ring, int p, int q, int x, int y, int z, int w);
extern "C" void ring_put_key(Ring *ring, int p, int q, int key);
extern "C" void ring_put_commit(Ring *ring);ring
extern "C" void ring_put_exit(Ring *ring);
extern "C" int ring_get(Ring *ring, RingEntry *entry);*/

/// [issue](https://github.com/Team-10-But-Better/Craft/issues/85)
/// The implementation in the original project seems to create off-by-one errors, which causes tests to fail.
/// Since the purpose of this task is to only write tests (but not code), I will not be fixing them currently.

TEST(tests, issue85)
{
    Ring r;
    ring_alloc(&r, 4);
    EXPECT_EQ(ring_size(&r), 0);
    EXPECT_EQ(ring_empty(&r), 1);
    EXPECT_EQ(ring_full(&r), 0);
    ring_put_block(&r, 1, 1, 1, 1, 1, 1);
    EXPECT_EQ(ring_size(&r), 1);
    EXPECT_EQ(ring_empty(&r), 0);
    EXPECT_EQ(ring_full(&r), 0);
    ring_put_block(&r, 2, 2, 2, 2, 2, 2);
    EXPECT_EQ(ring_size(&r), 2);
    EXPECT_EQ(ring_empty(&r), 0);
    EXPECT_EQ(ring_full(&r), 0);
    ring_put_block(&r, 3, 3, 3, 3, 3, 3);
    EXPECT_EQ(ring_size(&r), 3);
    EXPECT_EQ(ring_empty(&r), 0);
    EXPECT_EQ(ring_full(&r), 0);
    RingEntry re;
    re.type = BLOCK;
    re.p = 4;
    re.q = 4;
    re.w = 4;
    re.x = 4;
    re.y = 4;
    re.z = 4;
    RingEntry re2;
    ring_put(&r, &re);
    EXPECT_EQ(ring_size(&r), 4);
    EXPECT_EQ(ring_empty(&r), 0);
    EXPECT_EQ(ring_full(&r), 1);
    EXPECT_EQ(ring_get(&r, &re2), 1);
    EXPECT_EQ(re2.p, 1);
}

extern "C" int craft_main(int argc, char *argv[]);

//----------------------------------------------------
int main(int argc, char* argv[])
{
	craft_main(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
