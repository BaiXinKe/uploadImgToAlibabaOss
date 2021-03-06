#include <iostream>
#include "getSetting.hpp"
#include "switch_oper.hpp"


int main(int argc, char **argv){
    std::string switchOperString;
    Oper oper;
    while(true){
        std::cout << "Please choice an operation : (upload_file, delete_file, create_dir or ls_dir)\n";
        std::cin >> switchOperString;
        oper = switch_operator(switchOperString);
        switch(oper){
        case Oper::UPLOAD_FILE:
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
        break;
        }
    }
}