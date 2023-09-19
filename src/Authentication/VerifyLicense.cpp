#pragma once
#include "../PCH.h"
#include "VerifyLicense.h"
#include "./ui_VerifyLicense.h"
#include "Authentication.cpp"
#include "../Config.h"

VerifyLicense::VerifyLicense(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VerifyLicense)
{
    ui->setupUi(this);
    this->setWindowTitle(QString(APP_NAME));
    this->setFixedSize(350, 100);
}

VerifyLicense::~VerifyLicense()
{
    delete ui;
}

// Callback function to handle cURL response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void VerifyLicense::on_pushButton_clicked() {
    QString licenseKey = ui->licenseTextbox->text().trimmed();

    if (licenseKey.isEmpty()) {
        // Show a warning
        QMessageBox::warning(this, "Empty Input", "Please enter a valid license key.");
        return;
    }

    // Perform an HTTP POST request to the PHP script
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        std::string postData = "licenseKey=" + licenseKey.toStdString();
        curl_easy_setopt(curl, CURLOPT_URL, "https://auth.brianoost.com/verify.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

        // Response handling callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Response buffer
        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            // Check if the responseBuffer contains valid JSON
            try {
                nlohmann::json jsonResponse = nlohmann::json::parse(responseBuffer);

                if (jsonResponse["message"] == "Success") {
                    //Auth::GetUserData();
                    Auth::Accepted();
                    this->close();
                } else {
                    QMessageBox::warning(this, "Invalid Key", "Please enter a valid license key.");
                }
            } catch (const nlohmann::json::exception& e) {
                QMessageBox::critical(this, "JSON Parsing Error", e.what());

                #if defined(QT_DEBUG)
                // Print the responseBuffer for debugging
                qDebug() << "Response Content:" << responseBuffer.c_str();
                #endif
            }
        } else {
            QMessageBox::critical(this, "HTTP Error", "An error occurred while making the HTTP request");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}
