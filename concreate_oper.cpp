#include "concreate_oper.hpp"
#include "getSetting.hpp"

#include <alibabacloud/oss/OssClient.h>

using namespace AlibabaCloud::OSS;

OperatorForOss::OperatorForOss(std::shared_ptr<AccountMSG> account, const ClientConfiguration& conf)
  try :client{std::make_unique<OssClient>(account->Endpoint,account->AccessKeyId, 
                                        account->AccessKeySecret,account->BucketName, conf)}
{}
catch(std::exception& e){
    std::cerr << e.what() <<std::endl;
}


