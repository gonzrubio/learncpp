#pragma once
#include "Doctor.h"
#include <functional>
#include <vector>

class Patient {
private:
	std::string m_name;
	std::vector<std::reference_wrapper<const Doctor>> m_doctors;
	// We're going to make add_doctor private because we don't want the public to use it.
	// They should use Doctor::add_patient() instead, which is publicly exposed
	void add_doctor(const Doctor& doctor);
public:
	Patient(const std::string& name) : m_name{ name } {}
	const std::string& get_name() const { return m_name; }
	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
	// We will make this a friend function so Doctor::add_patient can access the 
	// private member function Patiend::add_doctor().
	friend void Doctor::add_patient(const Patient& patient);
};

