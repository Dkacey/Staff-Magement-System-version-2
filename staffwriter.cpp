#include "staffwriter.h"
#include <QFile>
#include <QTextStream>

StaffWriter::StaffWriter(StaffList *sl): staffList{sl}
{
}

bool StaffWriter::writeToFile() const
{
    QFile file("staffFile.txt");
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QTextStream toFile(&file);

    QList<Staff*> list = staffList->getStaffList();

    foreach(Staff *s, list)
    {
        const QMetaObject *meta = s->metaObject();

        QString result;

        for (int count=meta->propertyOffset(); count<meta->propertyCount(); count++)
        {
            const QMetaProperty prop = meta->property(count);
            QString name = prop.name();
            QVariant value = prop.read(s);
            QString valueString = value.toString();
            result += QString(name + ": " + valueString + "; ");
        }
        toFile << result << '\n';
    }

    file.close();

    return true;
}
