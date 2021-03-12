#include <iostream>
#include <alibabacloud/oss/OssClient.h>
#include "getSetting.hpp"
#include "switch_oper.hpp"
#include "concreate_oper.hpp"
#include "getSetting.hpp"

void setConfiguration(AlibabaCloud::OSS::ClientConfiguration& conf){

}

int main(int argc, char **argv){

    std::string switchOperString;
    AlibabaCloud::OSS::ClientConfiguration conf;
    setConfiguration(conf);
    Oper oper;
    OperatorForOss operatorForOss{std::make_shared<AccountMSG>(getSetting("account_msg.json")), conf};
    while(true){
        std::cout << "Please choice an operation : (upload_file, delete_file, create_dir or ls_dir)\n";
        std::cin >> switchOperString;
        oper = switch_operator(switchOperString);
        switch(oper){
        case Oper::UPLOAD_FILE:
        operatorForOss.upload_file();
        break;
        case Oper::CREATE_DIR:
        break;
        case Oper::DELETE_FILE:
        break;
        case Oper::DOWNLOAD_FILE:
        break;
        case Oper::ITER_FILE_IN_A_DIR:
        break;
        case Oper::UNKNOWN_OPER:
        operatorForOss.unknown_oper();
        break;
        }
    }
}