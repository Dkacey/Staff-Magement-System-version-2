 #ifndef STAFFLIST_H
#define STAFFLIST_H

#include "staff.h"
#include <QList>

class StaffList
{
public:
    StaffList();
    ~StaffList();
    void addStaff(Staff *s);
    QList<Staff*> getStaffList() const;

private:
    QList<Staff*> staffList;
};

#endif // STAFFLIST_H
