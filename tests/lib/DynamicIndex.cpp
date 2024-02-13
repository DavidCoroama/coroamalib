#include <gtest/gtest.h>

#include <coroama/dynamic/dynidx.h>

dynidx_t array;

TEST(DynamicIndexTest, CanCreateDynamicIndex) {
    array = dynidx_new();

    ASSERT_FALSE(is_dynidx_null(&array));
}

TEST(DynamicIndexTest, CanPushNewIndex) {
    ASSERT_TRUE(dynidx_push(&array, 10));
    ASSERT_TRUE(dynidx_push(&array, 11));
    ASSERT_TRUE(dynidx_push(&array, 12));

    ASSERT_EQ(dynidx_last(&array), 12);
}

TEST(DynamicIndexTest, CanPopLastIndex) {
    size_t index0;
    size_t index1;
    size_t index2;

    dynidx_pop(&array, &index2);
    dynidx_pop(&array, &index1);
    dynidx_pop(&array, &index0);

    ASSERT_EQ(index2, 12);
    ASSERT_EQ(index1, 11);
    ASSERT_EQ(index0, 10);
    ASSERT_EQ(array.index, 0);
}

TEST(DynamicIndexTest, DoesBlockProperlyResize) {
    ASSERT_TRUE(dynidx_push(&array, 10));
    ASSERT_TRUE(dynidx_push(&array, 11));
    ASSERT_TRUE(dynidx_push(&array, 12));
    ASSERT_TRUE(dynidx_push(&array, 13));
    ASSERT_TRUE(dynidx_push(&array, 14));

    ASSERT_EQ(array.size, 8);
    ASSERT_EQ(array.index, 5);
    ASSERT_EQ(array.next_size, 12);
}

TEST(DynamicIndexTest, CanFreeDynamicIndex) {
    dynidx_free(&array);

    ASSERT_EQ(array.block, (size_t*)NULL);
}