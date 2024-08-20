#include "gui.h"
#include "staffwriter.h"

#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

Gui::Gui(QWidget *parent)
    : QWidget{parent},
      nameEdit{new QLineEdit},
      calendar{new QCalendarWidget},
      typeCombo{new QComboBox},
      processButton{new QPushButton("Process")},
      writeButton{new QPushButton("Write to file")},
      staffList{new StaffList}
{
    setupGui();
    typeCombo->addItem("Permanent");
    typeCombo->addItem("Part-time");
    typeCombo->addItem("Contract");

    connect(nameEdit, &QLineEdit::textChanged, this, &Gui::enableProcessButton);
    connect(processButton, &QPushButton::clicked, this, &Gui::process);
    connect(writeButton, &QPushButton::clicked, this, &Gui::writeToFile);
}

Gui::~Gui()
{
    delete staffList;
}

void Gui::enableProcessButton()
{
    if (nameEdit->text().size()!=0)
    {
            processButton->setEnabled(true);
    }
}

void Gui::process()
{
    QString name{nameEdit->text()};
    QDate date{calendar->selectedDate()};
    int typeIndex{typeCombo->currentIndex()};

    Staff::StaffType type{static_cast<Staff::StaffType>(typeIndex)};

    Staff *staff{new Staff{name, date, type}};
    staffList->addStaff(staff);

    nameEdit->clear();
    nameEdit->setFocus();
    calendar->setSelectedDate(QDate::currentDate());
    typeCombo->setCurrentIndex(0);
    processButton->setEnabled(false);
    writeButton->setEnabled(true);
    QMessageBox::information(this, "Staff detail", "Staff detail added");
}

void Gui::writeToFile()
{
    StaffWriter writer(staffList);
    if (writer.writeToFile())
    {
        QMessageBox::information(this, "Output", "Staff detail saved and written to file");
    }
    else
    {
        QMessageBox::information(this, "Output", "Staff detail saved and not written to file");
    }
}


void Gui::setupGui()
{
    setWindowTitle("Staff");

    QLabel* nameLabel{new QLabel("Name")};
    QLabel* dateLabel{new QLabel("Birth date")};
    QLabel* typeLabel{new QLabel("Staff type")};

    QGridLayout* layout{new QGridLayout(this)};
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameEdit, 0, 1);
    layout->addWidget(dateLabel, 1, 0);
    layout->addWidget(calendar, 1, 1);
    layout->addWidget(typeLabel, 2, 0);
    layout->addWidget(typeCombo, 2, 1);
    layout->addWidget(processButton, 3, 0, 1, 2);
    layout->addWidget(writeButton, 4, 0, 1, 2);

    processButton->setEnabled(false);
    writeButton->setEnabled(false);
    this->setLayout(layout);
    this->adjustSize();
}
