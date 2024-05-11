#include "EntryPoint.h"
#include "Framework/Application.h"

int main()
{
	ph::Application* app = GetApplication();
	app->run();
	delete app;
}