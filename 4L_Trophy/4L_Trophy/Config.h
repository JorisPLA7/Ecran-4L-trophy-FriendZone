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

protected:
	std::vector<std::string> music_extention;
};


#endif // !DEFINE_CONFIG
