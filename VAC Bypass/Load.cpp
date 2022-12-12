#include <Windows.h>
#include <iostream>

#include "Hooks.h"
#include "Scanner.h"

void Main(HMODULE hModule) {
	HMODULE SteamService = GetModuleHandleA("steamservice.dll");

	printf("	 _    __              ____                             ");
	printf("	| |  / /___ ______   / __ )__  ______  ____ ___________");
	printf("	| | / / __ `/ ___/  / __  / / / / __ \/ __ `/ ___/ ___/");
	printf("	| |/ / /_/ / /__   / /_/ / /_/ / /_/ / /_/ (__  |__  ) ");
	printf("	|___/\__,_/\___/  /_____/\__, / .___/\__,_/____/____/  ");
	printf("	                        /____/_/                       ");
	scanf("Enter to connect :");

	if (SteamService) {
		if (InitVACHooks((void*)SteamService))
			MessageBoxA(0, "Patched VAC. You may start CSGO.", "VAC Bypass [SUCCESS]", MB_OK);
		else
			MessageBoxA(0, "An error occured. Please close steam", "VAC Bypass [ERROR]", MB_OK);
	}
	else
		MessageBoxA(0, "Could not find steamservice.dll. Please restart steam as administrator", "VAC Bypass [ERROR]", MB_OK);

	FreeLibraryAndExitThread(hModule, 0);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPARAM lParam) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr));
	}
}
