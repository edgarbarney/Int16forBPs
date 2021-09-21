// Copyright Epic Games, Inc. All Rights Reserved.

#include "Int16forBPsBPLibrary.h"
#include "Int16forBPs.h"

#include <iostream>
#include <sstream>

#pragma region Int16

int UInt16forBPsBPLibrary::Get16BitInt(FInt16_bp integer16)
{
	//return int(259U*unsigned_integer1+unsigned_integer2);
	return (int)((integer16.unsigned_integer2 << 8) | integer16.unsigned_integer1);
}

void UInt16forBPsBPLibrary::Set16BitInt(FInt16_bp& integer16, int int32ToConvert)
{
	uint16 main_integer16 = (uint16)int32ToConvert;
	integer16.unsigned_integer2 = main_integer16 >> 8;
	integer16.unsigned_integer1 = uint8(main_integer16 & 0x00ff);
}

int32 UInt16forBPsBPLibrary::Conv_Int16_bpToInt(FInt16_bp integer16)
{
	return (int)integer16;
}

FString UInt16forBPsBPLibrary::Conv_Int16_bpToString(FInt16_bp integer16)
{
	return FString::FromInt(integer16);
}

float UInt16forBPsBPLibrary::Conv_Int16_bpToFloat(FInt16_bp integer16)
{
	return (float)integer16;
}

FInt16_bp UInt16forBPsBPLibrary::Conv_FloatToInt16_bp(float floatToConvert)
{
	return (FInt16_bp)std::roundf(floatToConvert);
}

FInt16_bp UInt16forBPsBPLibrary::Conv_FloatToCeilInt16_bp(float floatToConvert)
{
	return (FInt16_bp)std::ceilf(floatToConvert);
}

FInt16_bp UInt16forBPsBPLibrary::Conv_FloatToFloorInt16_bp(float floatToConvert)
{
	return (FInt16_bp)std::floorf(floatToConvert);
}

FInt16_bp UInt16forBPsBPLibrary::Conv_IntToInt16_bp(int int32ToConvert)
{
	return (FInt16_bp)int32ToConvert;
}

FInt16_bp UInt16forBPsBPLibrary::Make16BitInt(uint8 A, uint8 B)
{
	return FInt16_bp{ A , B };
}

void UInt16forBPsBPLibrary::Make8BitInts(FInt16_bp A, uint8& O1, uint8& O2)
{
	O1 = A.unsigned_integer1;
	O2 = A.unsigned_integer2;
}

FInt16_bp UInt16forBPsBPLibrary::int16plusint(FInt16_bp A, int B)
{
	return A + (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16plusint16(FInt16_bp A, FInt16_bp B)
{
	return A + B;
}

FInt16_bp UInt16forBPsBPLibrary::int16minusint(FInt16_bp A, int B)
{
	return A - (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16minusint16(FInt16_bp A, FInt16_bp B)
{
	return A - B;
}

FInt16_bp UInt16forBPsBPLibrary::int16divideint(FInt16_bp A, int B)
{
	if (B == 0) return 0;
	else return A / (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16divideint16(FInt16_bp A, FInt16_bp B)
{
	if (B == 0) return 0;
	else return A / B;
}

FInt16_bp UInt16forBPsBPLibrary::int16multiplyint(FInt16_bp A, int B)
{
	return A * (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16multiplyint16(FInt16_bp A, FInt16_bp B)
{
	return A * B;
}

FInt16_bp UInt16forBPsBPLibrary::int16modulus(FInt16_bp A, FInt16_bp B)
{
	if (B == 0) return 0;
	else return A % B;
}

FInt16_bp UInt16forBPsBPLibrary::int16modulusint(FInt16_bp A, int B)
{
	if (B == 0) return 0;
	else return A % (FInt16_bp)B;
}

#pragma endregion
