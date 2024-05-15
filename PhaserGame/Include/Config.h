#pragma once
#include <string>

std::string getResourceDirectory()
{
#ifdef NDEBUG
    return "Assets/";
#else
    return "D:/CPP_Projects/ProjectPhaser/PhaserGame/Assets/";
#endif
}
