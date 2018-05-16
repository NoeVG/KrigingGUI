#include <gtkmm/application.h>

#include "WindowGUI.h"
int main(int argc, char **argv)
{
	Gtk::Main kit(argc, argv);
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	
	WindowGUI kGUI("Kriging GUI",700,700);
	return app->run(kGUI);
	
}
