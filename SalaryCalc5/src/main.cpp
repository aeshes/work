#include <QtCore/QCoreApplication>

#include "gmock\gmock.h"
#include "database.h"
#include "composite.h"

#pragma comment(lib, "gmock.lib")


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	DBConnection::connect();

	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();

	return a.exec();
}
