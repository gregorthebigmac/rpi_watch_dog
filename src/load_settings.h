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


load_settings::load_settings() {
	_debug_mode = false;
}
load_settings::~load_settings() {}

void load_settings::load_config_file() {
	std::ifstream fin;
	if (_debug_mode) { std::cout << "Opening settings.cfg... "; }
	fin.open("config/settings.cfg");
	if (fin.is_open()) {
		if (_debug_mode) { std::cout << "[OK]" << std::endl; }
		while(!fin.eof()) {
			std::string temp;
			getline(fin, temp);
			m_file_lines.push_back(temp);
			if (_debug_mode) { std::cout << "temp = [" << temp << "]" << std::endl; }
		}
		if (_debug_mode) { dump_file_lines(); }
		fin.close();
		// purging blank lines
		for (int i = 0; i < m_file_lines.size(); i++) {
			std::string temp = m_file_lines[i];
			if (temp[0] == NULL) {
				m_file_lines.erase(m_file_lines.begin()+i);
			}
		}
		if (_debug_mode) { dump_file_lines(); }
	}
	else std::cout << "ERROR: config/settings.cfg failed to open!" << std::endl;
	parse_config_file();
}

void load_settings::parse_config_file() {
	if (_debug_mode) { std::cout << "Entering parse_config_file..." << std::endl; }
	std::vector<std::string> temp_vec_st;
	for (int i = 0; i < m_file_lines.size(); i++) {
		std::string temp = m_file_lines[i];
		if (_debug_mode) { std::cout << "temp = [" << temp << "]" << std::endl; }
		std::size_t found1 = temp.find('\t');
		if (found1 != std::string::npos) {
			std::string temp2 = temp.substr(0, found1);
			if (temp2 == "iface") {
				temp_vec_st.push_back(temp2);
				temp.erase(0, found1);
				if (_debug_mode) { std::cout << "found interface! " << temp2 << std::endl; }
			}
			else if (temp2 == "host") {
				temp_vec_st.push_back(temp2);
				temp.erase(0, found1);
				if (_debug_mode) { std::cout << "found host! " << temp2 << std::endl; }
			}
			else {
				if (temp[0] == '#')
					continue;
				else {
				std::cout << "ERROR: Garbage info in line " << i << " of settings.cfg" << std::endl;
				std::cout << "bad entry: " << temp2 << std::endl;
				continue;
				}
			}
		}
		if (_debug_mode) { std::cout << "Entering while erase white space..." << std::endl; }
		while (isspace(temp[0])) {
			std::cout << "Found whitespace character! Purging..." << std::endl;
			temp.erase(0, 1);
			std::cout << "temp = " << temp << std::endl;
		}
		found1 = temp.find('\t');
		if (found1 != std::string::npos) {
			std::string temp2 = temp.substr(0, found1);
			if (temp_vec_st[0] == "iface") {
				temp_vec_st.push_back(temp2);
				temp.erase(0, found1);
			}
			else if (temp_vec_st[0] == "host") {
				temp_vec_st.push_back(temp2);
				temp.erase(0, found1);
			}
			else std::cout << "Garbage data. Moving on..." << std::endl;
		}
		if (_debug_mode) { std::cout << "Entering while erase white space..." << std::endl; }
		while (isspace(temp[0])) {
			std::cout << "Found whitespace character! Purging..." << std::endl;
			temp.erase(0, 1);
			std::cout << "temp = " << temp << std::endl;
		}
		temp_vec_st.push_back(temp);
		if (temp_vec_st[0] == "iface") {
			if (_debug_mode) { std::cout << "adding " << temp_vec_st[1] << " to interfaces" << std::endl; }
			m_interfaces.push_back(temp_vec_st[1]);
			if (_debug_mode) { std::cout << "adding " << temp_vec_st[2] << " to mac addresses" << std::endl; }
			m_mac_addr.push_back(temp_vec_st[2]);
		}
		else if (temp_vec_st[0] == "host") {
			if (_debug_mode) { std::cout << "adding " << temp_vec_st[1] << " to hosts" << std::endl; }
			m_hosts.push_back(temp_vec_st[1]);
			if (_debug_mode) { std::cout << "adding " << temp_vec_st[2] << " to ip addresses" << std::endl; }
			m_ip_addr.push_back(temp_vec_st[2]);
		}
		temp_vec_st.clear();
	}
	dump_all();
}

////////////////////////////////////////////////////////////////////////////////
// 								DEBUG FUNCTIONS								  //
////////////////////////////////////////////////////////////////////////////////
void load_settings::dump_file_lines() {
	std::cout << "Dumping contents of m_file_lines..." << std::endl;
	for (int i = 0; i < m_file_lines.size(); i++) {
		std::cout << "[" << i << "] " << m_file_lines[i] << std::endl;
	}
}

void load_settings::dump_interfaces() {
	std::cout << "Dumping contents of m_interfaces..." << std::endl;
	for (int i = 0; i < m_interfaces.size(); i++) {
		std::cout << "[" << i << "] " << m_interfaces[i] << std::endl;
	}
}

void load_settings::dump_mac_addr() {
	std::cout << "Dumping contents of m_mac_addr..." << std::endl;
	for (int i = 0; i < m_mac_addr.size(); i++) {
		std::cout << "[" << i << "] " << m_mac_addr[i] << std::endl;
	}
}

void load_settings::dump_hosts() {
	std::cout << "Dumping contents of m_hosts..." << std::endl;
	for (int i = 0; i < m_hosts.size(); i++) {
		std::cout << "[" << i << "] " << m_hosts[i] << std::endl;
	}
}

void load_settings::dump_ip_addr() {
	std::cout << "Dumping contents of m_ip_addr..." << std::endl;
	for (int i = 0; i < m_ip_addr.size(); i++) {
		std::cout << "[" << i << "] " << m_ip_addr[i] << std::endl;
	}
}

void load_settings::dump_all() {
	dump_file_lines();
	dump_interfaces();
	dump_mac_addr();
	dump_hosts();
	dump_ip_addr();
}
