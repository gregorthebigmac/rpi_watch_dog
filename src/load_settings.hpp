#pragma once

#include <iostream>		// only used for debugging stuff!
#include <fstream>		// used for loading config file
#include <string>		// used for storing config stuff
#include <vector>		// used for storing multiple lines of config stuff

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
	}
	else std::cout << "ERROR: config/settings.cfg failed to open!" << std::endl;
}

void load_settings::parse_config_file() {
	
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
