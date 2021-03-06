#ifndef CONCREATE_OPER_HPP
#define CONCREATE_OPER_HPP
#include <memory>

namespace AlibabaCloud::OSS{
    class OssClient;
};

struct AccountMSG;

class OperatorForOss{
public:
    OperatorForOss(std::shared_ptr<AccountMSG> account, const ClientConfiguration& conf);
    void upload_file();
    void create_dir();
    void download_file();
    void delete_file();
    void iter_file_in_a_dir();
    void unknown_oper();
private:
    std::string get_filename(){
        std::string filename;
        std::cout << "please input the filename";
        std::cin >> filename;
        return filename;
    }
    std::unique_ptr<AlibabaCloud::OSS::OssClient> client;
};

#endif