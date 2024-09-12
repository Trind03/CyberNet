#include <gtest/gtest.h>
#include "client_t.h"
#include <asio.hpp>

class t_client : public ::testing::Test
{
protected:
    void SetUp() override
    {
        binding_addr = asio::ip::address_v4::from_string("127.0.0.1");
        port = 5554;
        Client = new client_t(false,std::move(binding_addr),std::move(port));

    }
    void TearDown() override
    {
        delete Client;
    }
public:
    client_t *Client;

    /* Mock properties */
    asio::ip::address_v4 binding_addr;
    unsigned int port;
};

TEST_F(t_client, Class_instance)
{
    ASSERT_NE(Client, nullptr);
}

TEST_F(t_client, Initialization)
{
    EXPECT_EQ(Client->_Binding_addr,binding_addr);
    EXPECT_EQ(Client->_Port, port);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}