#include <mainwindow.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	run_stuff obj(argc, argv);
	return obj.run_func();
}