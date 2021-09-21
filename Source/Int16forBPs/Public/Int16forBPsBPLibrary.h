// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Int16forBPsBPLibrary.generated.h"

USTRUCT(immutable, noexport, BlueprintType)
struct FInt16_bp
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer1; //Byte
	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer2; //Byte

	FORCEINLINE constexpr FInt16_bp()
		: unsigned_integer2{ }
		, unsigned_integer1{ }
	{
	}

	FORCEINLINE constexpr FInt16_bp(uint8 a, uint8 b)
		: unsigned_integer2{ a }
		, unsigned_integer1{ b }
	{
	}

	FORCEINLINE constexpr FInt16_bp(int a)
		: unsigned_integer2{ ((uint16)a >> 8) }
		, unsigned_integer1{ (uint8((uint16)a & 0x00ff)) }
	{
	}

	FORCEINLINE FInt16_bp operator+(FInt16_bp& v)	const
	{
		return FInt16_bp
		{
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			+
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		};
	}
	FORCEINLINE FInt16_bp operator-(FInt16_bp& v)	const
	{
		return FInt16_bp
		{ 
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			- 
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1) 
		};
	}
	FORCEINLINE FInt16_bp operator*(FInt16_bp& v)	const
	{
		return FInt16_bp
		{
			(int)((unsigned_integer2 << 8) | unsigned_integer1) 
			*
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		};
	}
	FORCEINLINE FInt16_bp operator/(FInt16_bp& v)	const
	{
		if ((int)v == 0) return 0;
		return FInt16_bp
		{
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			/
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		};
	}
	FORCEINLINE FInt16_bp operator%(FInt16_bp& v)	const
	{
		if ((int)v == 0) return 0;
		return FInt16_bp
		{
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			%
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		};
	}

	FORCEINLINE operator int() 
	{
		return (int)((unsigned_integer2 << 8) | unsigned_integer1);
	}

	FORCEINLINE FInt16_bp(int a)
	{
		uint16 main_integer16 = (uint16)a;
		unsigned_integer2 = (main_integer16 >> 8);
		unsigned_integer1 = (uint8(main_integer16 & 0x00ff));
	}

	FORCEINLINE FInt16_bp(uint16 a)
	{
		unsigned_integer2 = (a >> 8);
		unsigned_integer1 = (uint8(a & 0x00ff));
	}

	FORCEINLINE FInt16_bp(float a)
	{
		uint16 main_integer16 = (uint16)a;
		unsigned_integer2 = (main_integer16 >> 8);
		unsigned_integer1 = (uint8(main_integer16 & 0x00ff));
	}
};

UCLASS()
class UInt16forBPsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static int Get16BitInt(FInt16_bp integer16);
	static void Set16BitInt(FInt16_bp& integer16, int int32ToConvert);

	#pragma region Int16 Arithmetics

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Integer16", CompactNodeTitle = "»"), Category = "Math|Int16")
	static FInt16_bp Make16BitInt(uint8 A, uint8 B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Bytes", CompactNodeTitle = "»"), Category = "Math|Int16")
	static void Make8BitInts(FInt16_bp A, uint8& O1, uint8& O2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int", CompactNodeTitle = "+", Keywords = "+ plus"), Category = "Math|Int16")
	static FInt16_bp int16plusint(FInt16_bp A, int B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int16", CompactNodeTitle = "+", Keywords = "+ plus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16plusint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int", CompactNodeTitle = "-", Keywords = "- minus"), Category = "Math|Int16")
	static FInt16_bp int16minusint(FInt16_bp A, int B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int16", CompactNodeTitle = "-", Keywords = "- minus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16minusint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int", CompactNodeTitle = "/", Keywords = "/ divide "), Category = "Math|Int16")
	static FInt16_bp int16divideint(FInt16_bp A, int B = 1);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int16", CompactNodeTitle = "/", Keywords = "/ divide ", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16divideint16(FInt16_bp A, FInt16_bp B = 1);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int", CompactNodeTitle = "*", Keywords = "* multiply times"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint(FInt16_bp A, int B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int16", CompactNodeTitle = "*", Keywords = "* multiply times", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulus(FInt16_bp A, FInt16_bp B = 1);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16 % int)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulusint(FInt16_bp A, int B = 1);

	#pragma endregion

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static int32 Conv_Int16_bpToInt(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (integer)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_IntToInt16_bp(int32 int32ToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FString Conv_Int16_bpToString(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloat (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static float Conv_Int16_bpToFloat(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToRoundInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToInt16_bp(float floatToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToCeilInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToCeilInt16_bp(float floatToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloorInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToFloorInt16_bp(float floatToConvert);
};
