#include "Doctor.h"
#include <iostream>

void Doctor::add_patient(Patient& patient) {
	m_patients.push_back(patient);

	// The patient should also add the doctor.
	patient.add_doctor(*this);
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
