#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

namespace Analysis
{
	class University
	{
	public:
		University();
		University(const University&);
		University(University&&) noexcept;
		~University() {};
		University& operator=(const University&);
		University& operator=(University&&) noexcept;

		University& operator+=(const University& rUni);
		University& operator/=(int val);

		void BuildMembers(int, std::wstring, std::wstring);
		bool Empty() const;

		friend std::wostream& operator<<(std::wostream& stream, const University uni);

	private:
		std::vector<std::pair<std::wstring, std::wstring>> wsmembers;  // String members.
		std::vector<std::pair<std::wstring, float>> fmembers;  // Floating-point members.
	};
} // namespace Analysis