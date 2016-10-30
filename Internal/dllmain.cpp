// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

#include "structures.h"
#include "dllmain.h"
#include "classes.h"
#include "functions.h"

DWORD WINAPI Update()
{
	while (true)
	{
		if (*LocalPlayer)
			LocalData = *(SLocalPlayer*)(*LocalPlayer);
		Sleep(1);
	}
}
 
DWORD WINAPI Func()
{
	while (true)
	{
		if (*LocalPlayer)
		{
			Hacks::BunnyHop (LocalData.Flags);
			Hacks::NoFlash  (LocalData.FlashDuration);
		}
		Sleep(1);
	}
}

DWORD WINAPI Init()
{
	while (!GetModuleHandle(L"csgo.exe"))   { Sleep(10); }
	while (!GetModuleHandle(L"client.dll")) { Sleep(10); }
	while (!GetModuleHandle(L"engine.dll")) { Sleep(10); }
	while (!GetModuleHandle(L"server.dll")) { Sleep(10); }

	CSBase = (DWORD)GetModuleHandle(L"csgo.exe");
	Client = (DWORD)GetModuleHandle(L"client.dll");
	Engine = (DWORD)GetModuleHandle(L"engine.dll");
	Server = (DWORD)GetModuleHandle(L"server.dll");

	Offset = new COffsets;

	LocalPlayer = (uintptr_t*)(Client + Offset->LocalPlayer);
	ClientState = (uintptr_t*)(Engine + Offset->ClientState);

	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Update, NULL, NULL, NULL);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Func, NULL, NULL, NULL);

	return (NULL);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);
		DisableThreadLibraryCalls(hModule);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

