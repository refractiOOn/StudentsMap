#include <iostream>
#include <map>

struct StudentInfo
{
	StudentInfo(std::string firstName, std::string lastName, int averageScore) :
		m_firstName(firstName),
		m_lastName(lastName),
		m_averageScore(averageScore)
	{

	}

	std::string m_firstName;
	std::string m_lastName;
	int m_averageScore;
};

int main()
{
	std::map<int, StudentInfo> students;
	StudentInfo roman("Roman", "Sotnikow", 100);
	StudentInfo alexey("Alexey", "Myheenko", 80);
	StudentInfo michael("Michael", "Litvinovich", 90);
	StudentInfo daniel("Daniel", "Yan", 85);
	students.emplace(1, roman);
	students.emplace(2, alexey);
	students.emplace(3, michael);
	students.emplace(4, daniel);
	for (auto it = students.cbegin(); it != students.cend(); std::advance(it, 1))
	{
		std::cout << it->first << " " << it->second.m_firstName << " " << it->second.m_lastName << " " << it->second.m_averageScore << std::endl;
	}
	auto result = find_if(students.cbegin(), students.cend(), [](const std::pair<const int, StudentInfo>& info)
		{
			return info.second.m_averageScore == 100;
		});
	if (result == students.end())
	{
		std::cout << "Student not found" << std::endl;
	}
	else
	{
		std::cout << "Student's name is " << result->second.m_firstName << " " << result->second.m_lastName << std::endl;
	}
}