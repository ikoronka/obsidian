#include <objc/objc.h>
#include <objc/objc-runtime.h>
#include <CoreFoundation/CoreFoundation.h>

int main() {
    // Initialize the application (needed for the app to run properly)
    id app = objc_msgSend((id)objc_getClass("NSApplication"), sel_registerName("sharedApplication"));

    // Create an autorelease pool
    id pool = objc_msgSend((id)objc_getClass("NSAutoreleasePool"), sel_registerName("new"));

    // Create an NSAlert instance
    id alert = objc_msgSend((id)objc_getClass("NSAlert"), sel_registerName("new"));

    // Set the message text of the alert
    objc_msgSend(alert, sel_registerName("setMessageText:"), CFSTR("Hello, World!"));

    // Set the informative text of the alert
    objc_msgSend(alert, sel_registerName("setInformativeText:"), CFSTR("This is a simple dialog box in C on macOS."));

    // Display the alert
    objc_msgSend(alert, sel_registerName("runModal"));

    // Release the autorelease pool
    objc_msgSend(pool, sel_registerName("drain"));

    return 0;
}
