#include "Doctor.h"
#include <iostream>

void Doctor::add_patient(const Patient& patient) {
	m_patients.push_back(patient);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
	if (doctor.m_patients.empty()) {
		out << doctor.m_name << " has no patients right now.";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patients) {
		out << patient.get().get_name() << ' ';
	}
	return out;
}
