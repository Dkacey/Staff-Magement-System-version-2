#ifndef GUI_H
#define GUI_H

#include "stafflist.h"
#include <QWidget>

class QLineEdit;
class QCalendarWidget;
class QComboBox;
class QPushButton;

class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);
    ~Gui();

private slots:
    void enableProcessButton();
    void process();
    void writeToFile();

private:
    void setupGui();

    StaffList *staffList;

    QLineEdit *nameEdit;
    QCalendarWidget *calendar;
    QComboBox *typeCombo;
    QPushButton *processButton;
    QPushButton *writeButton;
};

#endif // GUI_H
