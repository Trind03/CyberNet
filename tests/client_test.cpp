#include <gtest/gtest.h>
#include "client.h"

class t_client : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};


TEST(t_client, test)
{
    EXPECT_EQ(1,2);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}