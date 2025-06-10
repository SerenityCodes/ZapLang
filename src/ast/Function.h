#pragma once

#include "Argument.h"
#include <string>
#include <vector>

namespace ast {

class Function {
private:
  std::string name;
  std::string return_type;
  std::vector<Argument> args;
};

} // namespace ast
