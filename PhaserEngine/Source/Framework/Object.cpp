#include "Framework/Object.h"
#include "Framework/Core.h"

namespace ph
{
	Object::Object()
		: m_bPendingDestroy{ false }
	{
	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}

	void Object::destroy()
	{
		m_bPendingDestroy = true;
	}
}