#include "command/command.hpp"
#include "load_settings.h"
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

command cmd;
load_settings settings;

bool ping_returned(vector<string> ping);
bool wake_on_lan(int wol_index, int host_index);

int  main() {
	cmd.toggle_debug();
	settings.toggle_debug_mode();
	settings.load_config_file();
	vector<string> terminal_feedback, errors;
	while (true) {
		for (int i = 0; i < settings.get_sizeof_ips(); i++) {
			string ping = "ping -w 5 " + settings.get_ip_addr(i);
			cout << ping << endl;
			cmd.exec(ping.c_str(), terminal_feedback, errors);
			if (ping_returned(terminal_feedback) == false)
				wake_on_lan(0, i);
			usleep(60000000);	// sleep for 1 min.
		}
	}
	return 0;
}

bool ping_returned(vector<string> ping) {
	
}

bool wake_on_lan(vector<string> hosts) {
	
}
