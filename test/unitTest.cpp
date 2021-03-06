#include <gtest/gtest.h>
#include "../getSetting.hpp"

// TEST(getSettingTest, accountMSGTest){
//     auto account = getSetting("account_msg.json");
//     EXPECT_EQ(account->AccessKeyId ,"AccessKeyId");
//     EXPECT_EQ(account->AccessKeySecret, "AccessKeySecret");
//     EXPECT_EQ(account->Endpoint, "Endpoint");
//     EXPECT_EQ(account->BucketName,"BucketName");
// }



int main(int argc, char **argv){
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}