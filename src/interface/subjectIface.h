#ifndef _SUBJECT_IFACE_H_e8df9395_f086_42ef_af0e_a799f8539ff2_
#define _SUBJECT_IFACE_H_e8df9395_f086_42ef_af0e_a799f8539ff2_

#include "./src/interface/observerIface.h"

class SubjectIface {
private:

public:
	virtual void addObserver(ObserverIface& observer) = 0;
	virtual void removeObserver(ObserverIface& observer) = 0;
	virtual void notifyObservers() = 0;
};

#endif
