#include "getSetting.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

std::unique_ptr<AccountMSG>
getSetting(const std::string& fileName){
    auto accountSetting = std::make_unique<AccountMSG>();

    std::ifstream settingFile{fileName};
    if(!settingFile.is_open()){
        std::cerr << "setting file open failed\n";
        exit(EXIT_FAILURE);
    }

    nlohmann::json setting;
    settingFile >> setting;
    
    try
    {
        accountSetting->AccessKeyId = setting["AccessKeyId"];
        accountSetting->AccessKeySecret = setting["AccessKeySecret"];
        accountSetting->BucketName = setting["BucketName"];
        accountSetting->Endpoint = setting["Endpoint"];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return accountSetting;
}