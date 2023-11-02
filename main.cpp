#include <QApplication>

#include "DPrincipal.h"

 int main(int argc, char *argv[])
 {
 	QApplication app(argc, argv);
 	DPrincipal * dPrincipal = new DPrincipal();
 	dPrincipal->show();
 	return app.exec();
 }
