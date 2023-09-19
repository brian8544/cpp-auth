#pragma once
#define APP_AUTHOR "brian8544"
#define APP_COPYRIGHT "Copyright (c) Brian Oost, 2023. All rights reserved."
#define APP_LOCAL_VERSION "2.24"
#define APP_DOMAIN "https://brianoost.com"
#define APP_PATCHLIST "https://cdn.brianoost.com/brianapp/BrianApp-latest.zip"

#if defined(QT_DEBUG)
// Run as debug mode...
#define APP_NAME "BrianApp - DEVELOPMENT BUILD"
#define APP_AUTH_BYPASS 1 // default:1
// Run as release mode...
#else
#define APP_NAME "BrianApp"
#define APP_AUTH_BYPASS 0 // default:0
#endif
