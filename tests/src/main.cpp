#include <iostream>

#include <gtest/gtest.h>

extern "C" 
{
#include "../../include/math/sum.h"
}

TEST(sum, ok)
{
	ASSERT_EQ(sum(1,2), 3);
}

TEST(sum2, ok)
{
	ASSERT_EQ(sum2(1.5, 1.5), 3.0);
}


int main(int argc, char *argv[])
{

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
