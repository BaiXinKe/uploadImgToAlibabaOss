#include "concreate_oper.hpp"
#include "getSetting.hpp"
#include <alibabacloud/oss/OssClient.h>

using namespace AlibabaCloud::OSS;

OperatorForOss::OperatorForOss(std::shared_ptr<AccountMSG> account, const AlibabaCloud::OSS::ClientConfiguration& conf)
  :client(new AlibabaCloud::OSS::OssClient(account->Endpoint, account->AccessKeyId, account->AccessKeySecret, conf)), 
  accountMsg{account}
{
  InitializeSdk();
}

bool OperatorForOss::isConnect() const{
  return client != nullptr;
}

void OperatorForOss::upload_file(){
  auto file_name = get_filename();
  std::cout << "Please input the remote name for the file: ";
  std::string remoteObject;
  std::cin >> remoteObject;
  auto outcome = client->PutObject(accountMsg->BucketName, remoteObject, file_name);
  if (!outcome.isSuccess()) {
        /* 异常处理 */
        std::cout << "PutObject fail" <<
        ",code:" << outcome.error().Code() <<
        ",message:" << outcome.error().Message() <<
        ",requestId:" << outcome.error().RequestId() << std::endl;
        ShutdownSdk();
        exit(-1);
  }
  std::cout << "file load is: " << "https://chauncy-pic.oss-cn-beijing.aliyuncs.com/" + remoteObject <<std::endl;
}


void OperatorForOss::create_dir(){}
void OperatorForOss::delete_file(){}
void OperatorForOss::download_file(){}
void OperatorForOss::iter_file_in_a_dir(){}
void OperatorForOss::unknown_oper(){
  std::cout << "unknown operator: please choice a new operatin: ";
}

#define __MAIN__
#ifdef __MAIN__

int main(int argc, char** argv){
  auto accountMsg{std::make_shared<AccountMSG>()};
  accountMsg = getSetting();
  AlibabaCloud::OSS::ClientConfiguration conf;
  OperatorForOss operatorForOss{accountMsg, conf};
  operatorForOss.upload_file();
}

#endif