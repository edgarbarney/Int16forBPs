// Copyright FranticDreamer. All Rights Reserved.

#include "Int16forBPsBPLibrary.h"
#include "Int16forBPs.h"

#include <iostream>
#include <sstream>

#pragma region Conversion Nodes

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

FInt16_bp UInt16forBPsBPLibrary::Conv_IntToInt16_bp(int32 int32ToConvert)
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

#pragma endregion

#pragma region Arithmetic Nodes

FInt16_bp UInt16forBPsBPLibrary::int16plusint(FInt16_bp A, int32 B)
{
	return A + (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16plusint16(FInt16_bp A, FInt16_bp B)
{
	return A + B;
}

FInt16_bp UInt16forBPsBPLibrary::int16minusint(FInt16_bp A, int32 B)
{
	return A - (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16minusint16(FInt16_bp A, FInt16_bp B)
{
	return A - B;
}

FInt16_bp UInt16forBPsBPLibrary::int16divideint(FInt16_bp A, int32 B)
{
	if (B == 0) return 0;
	else return A / (FInt16_bp)B;
}

FInt16_bp UInt16forBPsBPLibrary::int16divideint16(FInt16_bp A, FInt16_bp B)
{
	if (B == 0) return 0;
	else return A / B;
}

FInt16_bp UInt16forBPsBPLibrary::int16multiplyint(FInt16_bp A, int32 B)
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

FInt16_bp UInt16forBPsBPLibrary::int16modulusint(FInt16_bp A, int32 B)
{
	if (B == 0) return 0;
	else return A % (FInt16_bp)B;
}

bool UInt16forBPsBPLibrary::Less_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A < B;
}

bool UInt16forBPsBPLibrary::Greater_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A > B;
}

bool UInt16forBPsBPLibrary::LessEqual_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A <= B;
}

bool UInt16forBPsBPLibrary::GreaterEqual_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A >= B;
}

bool UInt16forBPsBPLibrary::EqualEqual_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A == B;
}

bool UInt16forBPsBPLibrary::NotEqual_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A != B;
}

bool UInt16forBPsBPLibrary::InRange_Int16Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max, bool InclusiveMin = true, bool InclusiveMax = true)
{
	return ((InclusiveMin ? (Value >= Min) : (Value > Min)) && (InclusiveMax ? (Value <= Max) : (Value < Max)));
}

FInt16_bp UInt16forBPsBPLibrary::And_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A & B;
}

FInt16_bp UInt16forBPsBPLibrary::Xor_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A ^ B;
}

FInt16_bp UInt16forBPsBPLibrary::Or_Int16Int16(FInt16_bp A, FInt16_bp B)
{
	return A | B;
}

FInt16_bp UInt16forBPsBPLibrary::Not_Int16(FInt16_bp A)
{
	return ~A;
}

FInt16_bp UInt16forBPsBPLibrary::RandomInt16(FInt16_bp A)
{
	return FMath::RandHelper(A);
}

FInt16_bp UInt16forBPsBPLibrary::RandomInt16InRange(FInt16_bp Min, FInt16_bp Max)
{
	return FMath::RandRange(Min, Max);
}

FInt16_bp UInt16forBPsBPLibrary::Min_Int16(FInt16_bp A, FInt16_bp B)
{
	return FMath::Min(A, B);
}

FInt16_bp UInt16forBPsBPLibrary::Max_Int16(FInt16_bp A, FInt16_bp B)
{
	return FMath::Max(A, B);
}

FInt16_bp UInt16forBPsBPLibrary::Clamp_Int16(FInt16_bp V, FInt16_bp A, FInt16_bp B)
{
	return FMath::Clamp(V, A, B);
}

FInt16_bp UInt16forBPsBPLibrary::Wrap_Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max)
{
	return FMath::Wrap(Value, Min, Max);
}

FInt16_bp UInt16forBPsBPLibrary::Abs_Int16(FInt16_bp A)
{
	return FMath::Abs(A);
}

#pragma endregion


