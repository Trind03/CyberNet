#include <gtest/gtest.h>
#include "client_t.h"
#include <asio.hpp>

class t_client : public ::testing::Test
{
protected:
    void SetUp() override
    {
        binding_addr = asio::ip::address_v4::from_string("127.0.0.1");
        Client = new client_t(false,std::move(binding_addr),std::move(5554));

    }
    void TearDown() override
    {
        delete Client;
    }
public:
    client_t *Client;
private:
    /* Mock properties */
    unsigned int _Port;
    asio::ip::address_v4 binding_addr;
};

TEST_F(t_client, Class_instance)
{
    ASSERT_NE(Client, nullptr);
}

TEST_F(t_client, Initialization)
{
    ASSERT_EQ(Client->get_Binding_addr(),asio::ip::address_v4::from_string("127.0.0.1"));
    ASSERT_EQ(Client->get_Port(), 5554);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}