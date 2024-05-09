#pragma once
#include <SFML/Graphics.hpp>

namespace ph
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		sf::RenderWindow m_window;
	};
}