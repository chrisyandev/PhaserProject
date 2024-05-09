#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main()
{
	std::unique_ptr<ph::Application> app = std::make_unique<ph::Application>();
	app->Run();
}