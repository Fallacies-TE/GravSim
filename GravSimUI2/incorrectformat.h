#ifndef INCORRECTFORMAT_H
#define INCORRECTFORMAT_H

#include <QDialog>

namespace Ui {
class IncorrectFormat;
}

class IncorrectFormat : public QDialog
{
    Q_OBJECT

public:
    explicit IncorrectFormat(QWidget *parent = 0);
    ~IncorrectFormat();
    void setText(QString name);

private:
    Ui::IncorrectFormat *ui;
};

#endif // INCORRECTFORMAT_H
