#include "Framework/Actor.h"
#include "Framework/Core.h"
#include "Framework/AssetManager.h"

namespace ph
{
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : m_owningWorld{ owningWorld }
        , m_bBegunPlay{ false }
        , m_sprite{}
        , m_texture{}
    {
        setTexture(texturePath);
    }

    Actor::~Actor()
    {
        LOG("Actor Destroyed");
    }

    void Actor::beginPlayInternal()
    {
        if (!m_bBegunPlay)
        {
            m_bBegunPlay = true;
            beginPlay();
        }
    }

    void Actor::beginPlay()
    {
    }

    void Actor::tickInternal(float deltaTime)
    {
        if (!isPendingDestroy())
        {
            tick(deltaTime);
        }
    }

    void Actor::tick(float deltaTime)
    {
    }

    void Actor::setTexture(const std::string& texturePath)
    {
        m_texture = AssetManager::get().loadTexture(texturePath);

        if (!m_texture)
        {
            return;
        }

        m_sprite.setTexture(*m_texture);
        m_sprite.setTextureRect(
            sf::IntRect{
                sf::Vector2i{},
                sf::Vector2i{ (int)m_texture->getSize().x, (int)m_texture->getSize().y }
            });
    }

    void Actor::render(sf::RenderWindow& window)
    {
        if (isPendingDestroy())
        {
            return;
        }

        window.draw(m_sprite);
    }
}