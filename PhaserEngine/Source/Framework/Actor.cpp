#include "Framework/Actor.h"
#include "Framework/Core.h"
#include "Framework/AssetManager.h"
#include "Framework/MathUtility.h"
#include "Framework/World.h"

namespace ph
{
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : m_owningWorld{ owningWorld }
        , m_bBegunPlay{ false }
        , m_sprite{}
        , m_texture{}
        , m_actorLocation{}
        , m_actorRotation{}
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
        fixSpriteRotation();
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
        return m_actorLocation;
    }

    float Actor::getActorRotation() const
    {
        return m_actorRotation;
    }

    void Actor::setActorLocation(const sf::Vector2f& newLocation)
    {
        sf::Vector2f locationDelta = newLocation - m_actorLocation;
        m_sprite.move(locationDelta); // sprite transform is relative to actor
        m_actorLocation = newLocation;
    }

    void Actor::setActorRotation(float newRotation)
    {
        float rotationDelta = newRotation - m_actorRotation;
        m_sprite.rotate(rotationDelta); // sprite transform is relative to actor
        m_actorRotation = newRotation;
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

    sf::Vector2f Actor::getWindowSize() const
    {
        return m_owningWorld->getWindowSize();
    }

    sf::FloatRect Actor::getActorGlobalBounds() const
    {
        return m_sprite.getGlobalBounds();
    }

    bool Actor::isActorOutOfWindowBounds() const
    {
        sf::Vector2f windowSize = getOwningWorld()->getWindowSize();
        sf::FloatRect actorBounds = getActorGlobalBounds();
        sf::Vector2f actorLocation = getActorLocation();

        if (actorLocation.x + (actorBounds.width / 2) < 0) // if completely outside of window left side
        {
            return true;
        }
        if (actorLocation.x - (actorBounds.width / 2) > windowSize.x) // if completely outside of window right side
        {
            return true;
        }
        if (actorLocation.y + (actorBounds.height / 2) < 0) // if completely outside of window top side
        {
            return true;
        }
        if (actorLocation.y - (actorBounds.height / 2) > windowSize.y) // if completely outside of window bottom side
        {
            return true;
        }

        return false;
    }

    void Actor::centerPivot()
    {
        sf::FloatRect bounds = m_sprite.getLocalBounds(); // using globalBounds causes deviation when setTexture is called multiple times because the sprite gets rotated
        m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    }

    void Actor::fixSpriteRotation()
    {
        m_sprite.setRotation(m_actorRotation + 90.f); // compensate for image pointing up instead of right
    }
}