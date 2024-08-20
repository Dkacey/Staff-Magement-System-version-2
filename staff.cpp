#include "staff.h"

Staff::Staff()
{
}

Staff::Staff(QString n, QDate d, StaffType t): name{n}, birthDate{d}, type{t}
{
}

void Staff::setName(QString n)
{
    name = n;
}

void Staff::setDate(QDate d)
{
    birthDate = d;
}

void Staff::setType(StaffType t)
{
    type = t;
}

QString Staff::getName() const
{
    return name;
}

QDate Staff::getDate() const
{
    return birthDate;
}

Staff::StaffType Staff::getType() const
{
    return type;
}

QString Staff::getTypeAsString() const
{
    if (type == Permanent)
        return "Permanent";
    else if (type == PartTime)
        return "Part time";
    else if (type == Contract)
        return "Contract";
    return "Unknown";
}
