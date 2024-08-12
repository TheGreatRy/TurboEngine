#include "EString.h"

std::string ToLower(const std::string& str)
{
	std::string lowerStr;
	lowerStr.resize(str.size());

	// c/c++
	/*for (int i = 0; i < lowerStr.size(); i++)
	{
		lowerStr[i] = std::tolower(str[i]);
	}*/

	//modern c++
	std::transform(str.begin(), str.end(), lowerStr.begin(),
		[](char c)
		{
			return std::tolower(c);
		});

	//for each version (needs reserve not resize)
	/*for (auto c : str)
	{
		lowerStr.push_back(std::tolower(c));
	}*/

	return lowerStr;
}

std::string ToUpper(const std::string& str)
{
	{
		std::string upperStr;
		upperStr.resize(str.size());

		//modern c++
		std::transform(str.begin(), str.end(), upperStr.begin(),
			[](char c)
			{
				return std::toupper(c);
			});

		return upperStr;
	}
}

bool IsEqualIgnoreCase(const std::string& strOne, const std::string& strTwo)
{
	if (strOne.length() != strTwo.length()) return false;

	return std::equal(strOne.begin(), strOne.end(), strTwo.begin(),
		[](char cO, char cT)
		{
			return std::tolower(cO) == std::tolower(cT);
		}
	);
}
