#include <QCoreApplication>
#include <QDebug>

#include "Preliminaries/preliminariesdemo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Running DPL demos...\n";

    DPL::PreliminariesDemo::RunSingleResponsibilityPrincipleDemo();

    return a.exec();
}
