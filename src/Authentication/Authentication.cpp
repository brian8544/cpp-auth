#pragma once
#include "../PCH.h"
#include "../Config.h"
#include "VerifyLicense.h"

namespace Auth
{
static void GenerateLicense()
{
    // Create file.
    std::ofstream LicenseFile("license.lic");

    // Generate characters.
    //LicenseFile << GenerateRandom() << std::endl;

    // Double whiteline space.
    LicenseFile << std::endl << std::endl;

    // Write to license.lic
    //LicenseFile << "License generated on version: " << APP_LOCAL_VERSION << " for " APP_NAME << std::endl << APP_COPYRIGHT << " @ " << std::chrono::system_clock::now() << "." << std::endl;

    // Close, save the file.
    LicenseFile.close();
    return;
}

static void Accepted()
{
    // Ownership verified, continuing.
    QString UserName = QDir::home().dirName();

    QMessageBox::warning(nullptr, "Key accepted", "Thank you for supporting " + QString(APP_NAME) + ", " + UserName + ".");

    GenerateLicense();

    QMessageBox::information(nullptr, "Secure", "Replace this with your custom functions.");
}

static void Challenge()
{
    // Start authentication challenge, if debug flags are found; it will be skipped all-together.
    if (APP_AUTH_BYPASS == 1)
    {
        QMessageBox::information(nullptr, "Secure", "Replace this with your custom functions.");
    }
    // If license has been found, that means it's verified, so we can continue to main application.
    else if (std::filesystem::exists("license.lic"))
    {
        QMessageBox::information(nullptr, "Secure", "Replace this with your custom functions.");
    }
    else
    {
        // No license found, so prompt user to verify ownership.
        VerifyLicense* VerifyLicenseForm = new VerifyLicense;
        VerifyLicenseForm->show();
        QApplication::exec();
    }
}
}
