#include <gtest/gtest.h>
#include "server.h"
#include "session.h"

class t_server : public ::testing::Test
{
    void SetUp() override
    {

    }

    void TearDown() override
    {

    }

};

TEST(t_server, test)
{
    EXPECT_EQ(1,1);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}