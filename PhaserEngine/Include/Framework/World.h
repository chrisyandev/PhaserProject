#pragma once

namespace ph
{
	class Application;

	class World
	{
	public:
		World(Application* owningApp);
		virtual ~World();
		void beginPlayInternal();
		void tickInternal(float deltaTime);

	private:
		void beginPlay();
		void tick(float deltaTime);
		Application* m_owningApp;
		bool m_bBegunPlay;
	};
}