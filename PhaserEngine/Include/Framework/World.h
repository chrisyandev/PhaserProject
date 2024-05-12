#pragma once
#include "Framework/Core.h"

namespace ph
{
	class Application;
	class Actor;

	class World
	{
	public:
		World(Application* owningApp);
		virtual ~World();
		void beginPlayInternal();
		void tickInternal(float deltaTime);

		template<typename ActorType>
		TWeakPtr<ActorType> SpawnActor()
		{
			TSharedPtr<ActorType> newActor{ new ActorType{this} };
			m_pendingActors.push_back(newActor);
			return newActor;
		}

	private:
		void beginPlay();
		void tick(float deltaTime);
		Application* m_owningApp;
		bool m_bBegunPlay;
		TArray<TSharedPtr<Actor>> m_actors;
		TArray<TSharedPtr<Actor>> m_pendingActors;
	};
}