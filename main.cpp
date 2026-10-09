#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("PSI says hello world!");
    label.setAlignment(Qt::AlignCenter);
    label.resize(400, 150);
    label.show();

    return app.exec();
}
