#pragma once

#include <iostream>
#include <Windows.h>
#include <ostream>
#include <memory>
#include <vector>
#include <array>
#include <functional>
#include <random>
#include <istream>
#include <string>

enum class OptionType
{
	RegularOption,
	BoolOption,
	SubOption,
};

std::string OptionTypeString(OptionType type)
{
	switch (type)
	{
	case OptionType::RegularOption:
		return "RegularOption";
		break;
	case OptionType::BoolOption:
		return "BoolOption";
		break;
	case OptionType::SubOption:
		return "SubOption";
		break;
	}
}