#ifndef STRUCT_H
#define STRUCT_H

struct Vector2
{
	float x, y;
};

struct Vector3
{
	float x, y, z;
};

struct Vector4
{
	float x, y, z, w;
};

struct SLocalPlayer
{
	BYTE s1[0xEF];
	int Team;
	BYTE s2[0x8];
	int health;
	BYTE Flags;
	BYTE s3[0x32];
	Vector3 Origin;
	BYTE s4[0xA1C6];
	float FlashDuration;
};

#endif