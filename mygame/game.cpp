#include <QApplication>
#include "Init.h"

Init *init;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    init = new Init();
    init->show();
    return a.exec();
}
