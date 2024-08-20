#ifndef STAFF_H
#define STAFF_H

#include <QString>
#include <QDate>
#include <QObject>
#include <QMetaEnum>

class Staff: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(StaffType type READ getType WRITE setType)

public:
    enum StaffType {Permanent, PartTime, Contract};
    Q_ENUM(StaffType)

    Staff();
    Staff(QString n, QDate d, StaffType t);

private:
    QString name;
    QDate birthDate;
    StaffType type;

    void setName(QString n);
    void setDate(QDate d);
    void setType(StaffType t);

    QString getName() const;
    QDate getDate() const;
    StaffType getType() const;
    QString getTypeAsString() const;

};

#endif // STAFF_H
