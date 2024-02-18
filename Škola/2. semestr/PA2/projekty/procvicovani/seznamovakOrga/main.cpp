#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create and display a message box
    QMessageBox::information(nullptr, "Dialog Title", "This is a simple dialog box.");

    return app.exec();
}
