#include "University.h"

namespace Analysis
{
	University::University() : 
		fmembers{}, wsmembers{}
	{
	}

	University::University(const University& uni) : 
		fmembers{ uni.fmembers }, wsmembers{ uni.wsmembers }
	{
	}

	University::University(University&& uni) noexcept : 
		fmembers{ uni.fmembers }, wsmembers{ uni.wsmembers }
	{
		uni.fmembers.clear();
		uni.wsmembers.clear();
	}

	University& University::operator=(const University& rUni)
	{
		fmembers = rUni.fmembers;
		wsmembers = rUni.wsmembers;
		return *this;
	}

	University& University::operator=(University&& rUni) noexcept
	{
		fmembers = rUni.fmembers;
		wsmembers = rUni.wsmembers;
		return *this;
	}

	University& University::operator+=(const University& rUni)
	{
		auto it = rUni.fmembers.begin();
		for (auto& [ name, value ] : fmembers)
		{
			if (name == (*it).first)
			{
				value += (*it).second;
				it++;
			}
		}
		return *this;
	}

	University& University::operator/=(int val)
	{
		for (auto& entry : fmembers)
		{
			if (val > 0)
			{
				entry.second /= val;
			}
		}
		return *this;
	}

	void University::BuildMembers(int index, std::wstring name, std::wstring data)
	{
		if (data.empty()) data = L"-1";
		if (std::none_of(data.begin(), data.end(), [](wchar_t x) { return isalpha(x); }))
		{
			float f = stof(data);
			fmembers.emplace_back(std::make_pair(name, f));
		}
		else if (index == 1 || index == 2)
		{
			wsmembers.emplace_back(std::make_pair(name, data));
		}
	}
} // namespace Analysis