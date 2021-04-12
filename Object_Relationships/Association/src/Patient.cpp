#include "Patient.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
	out << patient.m_name << " is seeing doctors:";
	for (const auto& doc : patient.m_doctors) {
		out << " " << doc.get().get_name();
	}
	return out;
}

void Patient::add_doctor(const Doctor& doctor) {
	m_doctors.push_back(doctor);
}
