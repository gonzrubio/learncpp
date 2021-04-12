#pragma once
#include "Patient.h"
#include <functional>
#include <string>

class Patient; 

class Doctor {
private:
	std::string m_name;
	std::vector<std::reference_wrapper<const Patient>> m_patients;
public:
	Doctor(const std::string& name) : m_name{ name } {}
	void add_patient(Patient &patient);
	const std::string& get_name() const { return m_name; }
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);
};

