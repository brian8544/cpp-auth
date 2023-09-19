#pragma once
#include "PCH.h"

#include "Authentication/Authentication.cpp"

int main(int argc, char *argv[])
{
    qDebug() << QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ") + ("Application launch.");
    QApplication a(argc, argv); // Create the QApplication object

    Auth::Challenge();

    qDebug() << QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ") + ("Application exit.");
    return a.exec(); // Start the application event loop
	exit(0);
}
