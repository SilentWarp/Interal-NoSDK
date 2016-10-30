#ifndef CLASS_H
#define CLASS_H

class COffsets
{
public:
	DWORD LocalPlayer = 0xA8F53C;
	DWORD ClientState = 0x5C22C4;
	DWORD ForceJump   = 0x4F47A34;

	DWORD FlashDuration = 0xA308;
};

SLocalPlayer LocalData;
COffsets*    Offset;

#endif