#define SDL_MAIN_HANDLED

#include "Engine.h"
#include "Exceptions.h"
#include "Logger.h"

#if (defined _DEBUG) || !(defined _WIN32)
int main() {
#else
#include <Windows.h>
int WINAPI
WinMain(HINSTANCE zhInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	try {
		Engine* prueba = Engine::getInstance();
		prueba->init();
		prueba->run();
	}
	catch (const ExcepcionTAD& e) {
		Logger::getInstance()->log(e.msg(), Logger::Level::FATAL);
	}

	return 0;
}
