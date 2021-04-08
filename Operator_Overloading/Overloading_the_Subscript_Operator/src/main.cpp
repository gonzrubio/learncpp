/*
The subscript operator helps us access elements of an array at a specific index. The subscript
operator must be implemented as a member function.

Overloading the subscript operator allows us to do bounds checking when attempting to access and element.

Make sure you are not trying to call an overloaded subscript operator on a pointer to an object.
*/

#include <algorithm>
#include <cassert> // for assert()
#include <iostream>
#include <map>
#include <vector>

class IntList {
private:
	int m_list[10]{};
public:
	// Returning the value by reference allows to directly get and set values.
	int& operator[] (int index);
	// const version for const objects. Can only be used for access, not for assignment.
	const int& operator[] (int index) const;
};

int& IntList::operator[] (int index) {
	assert(index <= 0 && index < 10);
	return m_list[index];
}

const int& IntList::operator[] (int index) const {
	assert(index <= 0 && index < 10);
	return m_list[index];
}

void examples() {
	IntList array;
	array[0] = 69;
	std::cout << array[0] << std::endl;

	const IntList const_array;
	// const_array[0] = 69; // compile error
	std::cout << const_array[0] << std::endl;
	// std::cout << const_array[100] << std::endl; // invalid from bouds checking.
}

struct StudentGrade {
	std::string name;
	char grade;
};

class GradeMap {
private:
	std::vector<StudentGrade> m_map;
public:
	char& operator[] (const std::string &name) {
		// See if student's name already exists.
		auto exists{ std::find_if(m_map.begin(), m_map.end(),
					  [&](const auto& student) {return student.name == name; }) };

		if (exists != m_map.end()) {
			return exists->grade;
		}

		// Otherwise, create a new student and add a grade for the new student.
		m_map.push_back(StudentGrade{ name });
		return m_map.back().grade;
	}
};

void Q1() {
	// a) Write a struct StudentGrade that contains
	// the student’s name (as a std::string) and grade (as a char).

	// b) Add a class GradeMap that contains a std::vector of StudentGrade named m_map.

	// c) Write an overloaded [] for this class. The following should run:
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	/*
	// std::map can be initialized
	std::map<std::string, char> grades{
		{ "Joe", 'A' },
		{ "Frank", 'B' }
	};

	// and assigned
	grades["Susan"] = 'C';
	grades["Tom"] = 'D';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	*/
}

int main() {
	examples();
	Q1();

}