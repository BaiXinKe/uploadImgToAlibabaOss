#ifndef SWITCH_OPER_HPP
#define SWITCH_OPER_HPP
#include <string>

enum class Oper{
  CREATE_DIR,
  UPLOAD_FILE,
  DOWNLOAD_FILE,
  DELETE_FILE,
  ITER_FILE_IN_A_DIR,
  UNKNOWN_OPER
};

Oper switch_operator(const std::string& oper);

#endif