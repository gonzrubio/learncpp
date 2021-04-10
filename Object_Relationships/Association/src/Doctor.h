#pragma once
#include "Patient.h"
#include <functional>
#include <string>

class Doctor {
private:
	std::string m_name;
	std::vector<std::reference_wrapper<const Patient>> m_patients;
public:
	Doctor(const std::string& name) : m_name{ name } {}
	void add_patient(const Patient &patient);
	const std::string& get_name() { return m_name; }
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);
};

