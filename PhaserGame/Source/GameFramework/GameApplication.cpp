#include "GameFramework/GameApplication.h"

ph::Application* GetApplication()
{
	return new ph::GameApplication{};
}

namespace ph
{

}