#ifndef GANASTE_H
#define GANASTE_H

#include <QDialog>

namespace Ui {
class ganaste;
}

class ganaste : public QDialog
{
    Q_OBJECT

public:
    explicit ganaste(QWidget *parent = nullptr);
    ~ganaste();

private:
    Ui::ganaste *ui;
};

#endif // GANASTE_H
