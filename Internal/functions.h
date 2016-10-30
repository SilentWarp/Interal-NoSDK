#ifndef FUNC_H
#define FUNC_H

namespace Hacks
{
	void BunnyHop(BYTE x)
	{
		if (x & (1 >> 0) && GetAsyncKeyState(VK_SPACE) & 0x8000)
			*(int*)(Client + Offset->ForceJump) = 6;
	}

	void NoFlash(float x)
	{
		if (x > 0)
			*(float*)(*LocalPlayer + Offset->FlashDuration) = 0;
	}
}

namespace Utils
{

}

#endif