#include <MyLuaW/MyLuaW.h>

#include <iostream>

using namespace My;

int main() {
  char buffer[256];
  int error;
  LuaState L;
  L->openlibs();
  while (std::fgets(buffer, sizeof(buffer), stdin) != nullptr) {
    error = L->loadstring(buffer) || L->pcall(0, 0, 0);
    if (error) {
      std::cerr << L->tostring(-1) << std::endl;
      L->pop(1);
    }
  }
  return 0;
}
