#ifndef VERIFYLICENSE_H
#define VERIFYLICENSE_H

#include "../PCH.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VerifyLicense; }
QT_END_NAMESPACE

class VerifyLicense : public QMainWindow
{
    Q_OBJECT

public:
    VerifyLicense(QWidget *parent = nullptr);
    ~VerifyLicense();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VerifyLicense *ui;
};
#endif // VERIFYLICENSE_H
