#include <gtest/gtest.h>
#include "server.h"
#include "session.h"

class t_server : public ::testing::Test
{
    void SetUp() override
    {
        Server = new server(port,true);
    }

    void TearDown() override
    {
        delete Server;
    }
    server *Server;

    /* Mock data */
    unsigned int port = 5554;
};

TEST_F(t_server, test)
{
    EXPECT_EQ(1,1);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}