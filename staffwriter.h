#ifndef STAFFWRITER_H
#define STAFFWRITER_H

#include "stafflist.h"

class StaffWriter
{
public:
    StaffWriter(StaffList *sl);
    bool writeToFile() const;

private:
    StaffList *staffList;
};

#endif // STAFFWRITER_H
