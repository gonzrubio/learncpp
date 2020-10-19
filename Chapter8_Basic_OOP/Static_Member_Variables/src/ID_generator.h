#pragma once
#ifndef ID
#define ID

class ID_generator {
private:
	static int id_generator; // This "counter" is shared amongst all instances.
	int m_id;

public:
	ID_generator() { m_id = id_generator++; } // The constructor assignts the next value in the counter to the object.
	int getId() const;
};

#endif // !ID

