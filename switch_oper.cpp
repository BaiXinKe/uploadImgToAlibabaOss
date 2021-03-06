#include "switch_oper.hpp"

Oper switch_operator(const std::string& oper){
    if(oper == "upload_file"){
        return Oper::UPLOAD_FILE;
    }else if(oper == "delete_file"){
        return Oper::DELETE_FILE;
    }else if(oper == "create_dir"){
        return Oper::CREATE_DIR;
    }else if(oper == "ls_dir"){
        return Oper::ITER_FILE_IN_A_DIR;
    }
    return Oper::UNKNOWN_OPER;
}