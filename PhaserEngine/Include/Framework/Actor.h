#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"
#include "Framework/Object.h"

namespace ph
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();
		void beginPlayInternal();
		virtual void beginPlay();
		void tickInternal(float deltaTime);
		virtual void tick(float deltaTime);
		void setTexture(const std::string& texturePath);
		void render(sf::RenderWindow& window);

	private:
		World* m_owningWorld;
		bool m_bBegunPlay;
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	};
}