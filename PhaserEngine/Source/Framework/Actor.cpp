#include "Framework/Actor.h"
#include "Framework/Core.h"
#include "Framework/AssetManager.h"
#include "Framework/MathUtility.h"

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

        centerPivot();
    }

    void Actor::render(sf::RenderWindow& window)
    {
        if (isPendingDestroy())
        {
            return;
        }

        window.draw(m_sprite);
    }

    sf::Vector2f Actor::getActorLocation() const
    {
        return m_sprite.getPosition();
    }

    float Actor::getActorRotation() const
    {
        return m_sprite.getRotation();
    }

    void Actor::setActorLocation(const sf::Vector2f& newLocation)
    {
        m_sprite.setPosition(newLocation);
    }

    void Actor::setActorRotation(float newRotation)
    {
        m_sprite.setRotation(newRotation);
    }

    void Actor::addActorLocationOffset(const sf::Vector2f& offsetAmount)
    {
        setActorLocation(getActorLocation() + offsetAmount);
    }

    void Actor::addActorRotationOffset(float offsetAmount)
    {
        setActorRotation(getActorRotation() + offsetAmount);
    }

    sf::Vector2f Actor::getActorForwardVector()
    {
        return rotationToVector(getActorRotation());
    }

    sf::Vector2f Actor::getActorRightVector()
    {
        return rotationToVector(getActorRotation() + 90.f);
    }

    void Actor::centerPivot()
    {
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    }
}