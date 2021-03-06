#ifndef __GETSETTING_HPP
#define __GETSETTING_HPP
#include <string>
#include <memory>

struct AccountMSG{
    std::string AccessKeyId;
    std::string AccessKeySecret;
    std::string Endpoint;
    std::string BucketName;
};

std::unique_ptr<AccountMSG> 
getSetting(const std::string& fileName = "account_msg.json");

#endif