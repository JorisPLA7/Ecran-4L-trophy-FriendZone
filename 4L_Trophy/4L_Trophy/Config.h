#pragma once
#ifndef DEFINE_CONFIG

#define DEFINE_CONFIG


#include <vector>
#include <string>
#include <initializer_list>

class Config
{
public:
	Config();
	~Config();
	std::string base_path() const { return m_base_path; }
	std::vector<std::string> music_extention() const { return m_music_extention; }

protected:
	std::vector<std::string> m_music_extention;
	std::string m_base_path;
};


#endif // !DEFINE_CONFIG
