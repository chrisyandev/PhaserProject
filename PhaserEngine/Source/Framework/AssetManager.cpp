#include "Framework/AssetManager.h"

namespace ph
{
    TUniquePtr<AssetManager> AssetManager::s_assetManager{ nullptr };

    AssetManager& AssetManager::get()
    {
        if (!s_assetManager)
        {
            s_assetManager = TUniquePtr<AssetManager>{ new AssetManager };
        }

        return *s_assetManager;
    }

    TSharedPtr<sf::Texture> AssetManager::loadTexture(const std::string& path)
    {
        auto found = m_loadedTextureMap.find(path);
        if (found != m_loadedTextureMap.end())
        {
            return found->second;
        }

        TSharedPtr<sf::Texture> newTexture{ new sf::Texture };
        if (newTexture->loadFromFile(path))
        {
            m_loadedTextureMap.insert({ path, newTexture });
            return newTexture;
        }

        return TSharedPtr<sf::Texture>{ nullptr };
    }

    AssetManager::AssetManager()
    {
    }
}