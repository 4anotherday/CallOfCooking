#define SDL_MAIN_HANDLED

#include "Engine.h"
#include "Exceptions.h"
#include "Logger.h"
#include "PrefabLoader.h"

#if (defined _DEBUG) || !(defined _WIN32)
int main() {
#else
#include <Windows.h>
int WINAPI
WinMain(HINSTANCE zhInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	try {
		Engine::CreateInstance();
		Engine* prueba = Engine::getInstance();
		PrefabLoader::CreateInstance();

		prueba->init("Assets/Resources.cfg", "Assets/Levels");
		prueba->changeScene("Menu.lua");
		prueba->run();
	}
	catch (const ExcepcionTAD& e) {
		Logger::getInstance()->log(e.msg(), Logger::Level::FATAL);
	}

	return 0;
}