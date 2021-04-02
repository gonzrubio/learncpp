#include "ID_generator.h"

// Note that we are defining and initializing the private static member variable even though
// it is protected (private). We can do so since the dfinition it is not subject to acess controls.
// The definition and initialization is done outside the class definition in the global namespace.
int ID_generator::id_generator{ 1 };

int ID_generator::getId() const {
	return m_id;
}
