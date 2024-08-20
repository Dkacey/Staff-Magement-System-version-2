#include "stafflist.h"

StaffList::StaffList()
{
}

StaffList::~StaffList()
{
    qDeleteAll(staffList);
}

void StaffList::addStaff(Staff *s)
{
    staffList.append(s);
}

QList<Staff*> StaffList::getStaffList() const
{
    return staffList;
}
