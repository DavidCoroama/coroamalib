#include <gtest/gtest.h>

#include <coroama/types.h>

TEST(TypesTest, TypeIsSpecificSize) {
    ASSERT_EQ(sizeof(i8),  1);
    ASSERT_EQ(sizeof(i16), 2);
    ASSERT_EQ(sizeof(i32), 4);
    ASSERT_EQ(sizeof(i64), 8);

    ASSERT_EQ(sizeof(u8),  1);
    ASSERT_EQ(sizeof(u16), 2);
    ASSERT_EQ(sizeof(u32), 4);
    ASSERT_EQ(sizeof(u64), 8);
    
    #ifdef i128
        ASSERT_EQ(sizeof(i128), 16);
    #endif//i128

    #ifdef u128
        ASSERT_EQ(sizeof(u128), 16);
    #endif//u128
}