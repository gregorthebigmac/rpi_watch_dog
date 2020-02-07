#include "command/command.hpp"
#include "load_settings.hpp"

using std::cout;
using std::endl;
using std::string;

command cmd;
load_settings settings;

int  main() {
    settings.toggle_debug_mode();
    settings.load_config_file();
    return 0;
}
