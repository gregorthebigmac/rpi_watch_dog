#pragma once

#include <iostream>		// only used for debugging stuff!
#include <fstream>		// used for loading config file
#include <string>		// used for storing config stuff
#include <vector>		// used for storing multiple lines of config stuff
#include <cctype>		// used for purging white space from config file

class load_settings {
public:
	load_settings();
	virtual ~load_settings();
	
	// getters
	std::vector<std::string> get_hosts() { return m_hosts; }
	std::vector<std::string> get_ips() { return m_ip_addr; }
	
	void load_config_file();
	void parse_config_file();
	int find_first_whitespace_char(std::string str);
	
	// debug stuff
	void toggle_debug_mode() { _debug_mode = !_debug_mode; }

private:
	std::vector<std::string> m_file_lines;
	std::vector<std::string> m_interfaces;
	std::vector<std::string> m_mac_addr;
	std::vector<std::string> m_hosts;
	std::vector<std::string> m_ip_addr;
	
	// debug stuff
	bool _debug_mode;
	void dump_file_lines();
	void dump_interfaces();
	void dump_mac_addr();
	void dump_hosts();
	void dump_ip_addr();
	void dump_all();
};
