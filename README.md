# cpp-auth - Simple Key/License Check System

## Overview

cpp-auth is a simple key/license check system written in C++ and PHP. It allows you to verify license keys and manage user authentication for your application. This repository consists of both server-side and client-side code.

## Features

- **Server-Side (PHP):**
  - Provides a PHP script (`verify.php`) for verifying license keys.
  - Handles HTTP POST requests to validate license keys against a database.
  - Responds with JSON messages indicating success or failure.

- **Client-Side (C++):**
  - Contains C++ code for license management and user authentication.
  - Generates license files (`license.lic`) with relevant information.
  - Prompts users to verify ownership and enter license keys.
  - Uses cURL to perform HTTP POST requests to the server-side script.
  - Handles server responses, allowing access to the application upon successful license verification.

## Why Reverse Engineering Protection Is Important

Adding reverse engineering protection to your application is crucial to safeguard your intellectual property and prevent unauthorized access or distribution. Consider using tools like VMProtect or Themida to:

- **Protect Against Decompilation:** Prevent reverse engineers from easily decompiling and analyzing your C++ code.

- **Obfuscate Your Code:** Make it challenging for attackers to understand and modify your code, reducing the risk of cracks and hacks.

- **Secure Sensitive Data:** Protect sensitive information, such as license keys or encryption keys, from being extracted or tampered with.

- **Deter Unauthorized Distribution:** Make it difficult for unauthorized users to distribute cracked versions of your software.

## How to Use

### Server-Side (PHP)

1. Place the `verify.php` script on your server.

2. Configure the script by including a `config.php` file, which likely contains your database connection settings.

3. Set up your database to store license keys and other relevant information.

### Client-Side (C++)

1. Include the necessary headers and source files in your C++ project.

2. Use the provided functions from `Authentication.cpp` for license management and user authentication.

3. Modify the code to integrate with your application, replacing the placeholder functions with your custom functionality.

4. Implement reverse engineering protection mechanisms using tools like VMProtect or Themida to enhance security.

5. Build and run your C++ application.

## License

This code is provided under an open-source license. Please review the `LICENSE` file for details.

## Disclaimer

This repository serves as a basic example of a key/license check system and is intended for educational purposes. It may require customization to meet your specific requirements and security considerations. Incorporating reverse engineering protection is strongly recommended to enhance the security of your application.

## Contributions

Contributions are welcome! Feel free to submit issues, feature requests, or pull requests to improve this project.

---

For more information, visit [https://brianoost.com/](https://brianoost.com/).
