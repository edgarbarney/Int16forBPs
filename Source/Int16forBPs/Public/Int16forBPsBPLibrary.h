// Copyright FranticDreamer. All Rights Reserved.

#pragma once

#include "Net/UnrealNetwork.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/GameEngine.h"
#include "Int16forBPsBPLibrary.generated.h"

#define DEBUG(x) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x); }

USTRUCT(BlueprintType, DisplayName = "Integer16")
struct FInt16_bp
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer1; //Byte
	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer2; //Byte

	/* --	Consturctors	-- */
	FORCEINLINE FInt16_bp()
	{
		unsigned_integer2 = 0;
		unsigned_integer1 = 0;
	}

	FORCEINLINE FInt16_bp(uint8 a, uint8 b)
	{
		unsigned_integer2 = a;
		unsigned_integer1 = b;
	}

	FORCEINLINE FInt16_bp(int a)
	{
		unsigned_integer2 = ((uint16)a >> 8);
		unsigned_integer1 = (uint8((uint16)a & 0x00ff));
	}

	/* --	Arithmetic Operators	-- */
	
	FORCEINLINE FInt16_bp operator=(int v)	const
	{
		return (FInt16_bp)v;
	}
	FORCEINLINE uint16 operator=(FInt16_bp v)	const
	{
		return (uint16)v;
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
	FORCEINLINE FInt16_bp operator+=(FInt16_bp& v)	const
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
	FORCEINLINE FInt16_bp operator-=(FInt16_bp& v)	const
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

	/* --	Logical Operators	-- */
	FORCEINLINE bool operator>(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			>
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator<(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			<
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator<=(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			<=
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator>=(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			>=
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	/* These are built in.
	* 
	FORCEINLINE bool operator==(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			!=
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator!=(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			!=
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	*/

	/* --	Bitwise Operators	-- */
	FORCEINLINE bool operator&(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			&
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator^(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			^
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator|(FInt16_bp v)	const
	{
		return
		(
			(int)((unsigned_integer2 << 8) | unsigned_integer1)
			|
			(int)((v.unsigned_integer2 << 8) | v.unsigned_integer1)
		);
	}
	FORCEINLINE bool operator~()	const
	{
		return ~ ( (int)((unsigned_integer2 << 8) | unsigned_integer1) );
	}

	/* --	Conversion Operators	-- */
	FORCEINLINE operator int() 
	{
		return (int)((unsigned_integer2 << 8) | unsigned_integer1);
	}
};

UCLASS()
class UInt16forBPsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	#pragma region Arithmetic Nodes

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Increment Int16", CompactNodeTitle = "++", Keywords = "+ plus"), Category = "Math|Int16")
	static FInt16_bp incrementint16(FInt16_bp A);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Decrement Int16", CompactNodeTitle = "--", Keywords = "- minus"), Category = "Math|Int16")
	static FInt16_bp decrementint16(FInt16_bp A);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int", CompactNodeTitle = "+", Keywords = "+ plus"), Category = "Math|Int16")
	static FInt16_bp int16plusint(FInt16_bp A, int32 B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int16", CompactNodeTitle = "+", Keywords = "+ plus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16plusint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int", CompactNodeTitle = "-", Keywords = "- minus"), Category = "Math|Int16")
	static FInt16_bp int16minusint(FInt16_bp A, int32 B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int16", CompactNodeTitle = "-", Keywords = "- minus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16minusint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int", CompactNodeTitle = "/", Keywords = "/ divide "), Category = "Math|Int16")
	static FInt16_bp int16divideint(FInt16_bp A, int32 B = 1);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int16", CompactNodeTitle = "/", Keywords = "/ divide ", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16divideint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int", CompactNodeTitle = "*", Keywords = "* multiply times"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint(FInt16_bp A, int32 B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int16", CompactNodeTitle = "*", Keywords = "* multiply times", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulus(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16 % int)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulusint(FInt16_bp A, int32 B = 1);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 < int16", CompactNodeTitle = "<", Keywords = "< less"), Category="Math|Int16")
	static bool Less_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 > int16", CompactNodeTitle = ">", Keywords = "> greater"), Category="Math|Int16")
	static bool Greater_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 <= int16", CompactNodeTitle = "<=", Keywords = "<= less"), Category="Math|Int16")
	static bool LessEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 >= int16", CompactNodeTitle = ">=", Keywords = ">= greater"), Category="Math|Int16")
	static bool GreaterEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal (int16)", CompactNodeTitle = "==", Keywords = "== equal"), Category="Math|Int16")
	static bool EqualEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "NotEqual (int16)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category="Math|Int16")
	static bool NotEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "InRange (int16)"), Category = "Math|Int16")
	static bool InRange_Int16Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max, bool InclusiveMin = true, bool InclusiveMax = true);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise AND", CompactNodeTitle = "&", Keywords = "& and", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp And_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise XOR", CompactNodeTitle = "^", Keywords = "^ xor"), Category="Math|Int16")
	static FInt16_bp Xor_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise OR", CompactNodeTitle = "|", Keywords = "| or", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Or_Int16Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Bitwise NOT", CompactNodeTitle = "~", Keywords = "~ not"), Category = "Math|Int16")
	static FInt16_bp Not_Int16(FInt16_bp A);

	UFUNCTION(BlueprintPure, Category="Math|Random", meta=(NotBlueprintThreadSafe))
	static FInt16_bp RandomInt16(FInt16_bp Max);

	UFUNCTION(BlueprintPure, Category="Math|Random", meta = (NotBlueprintThreadSafe))
	static FInt16_bp RandomInt16InRange(FInt16_bp Min, FInt16_bp Max);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Min (int16)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Min_Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Max (int16)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Max_Int16(FInt16_bp A, FInt16_bp B);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Clamp (int16)"), Category="Math|Int16")
	static FInt16_bp Clamp_Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Wrap (int16)"), Category = "Math|Int16")
	static FInt16_bp Wrap_Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Absolute (int16)", CompactNodeTitle = "ABS"), Category="Math|Int16")
	static FInt16_bp Abs_Int16(FInt16_bp A);

	#pragma endregion

public:

	#pragma region Conversion Nodes

	#pragma region From Int16

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static int32 Conv_Int16_bpToInt(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FString Conv_Int16_bpToString(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloat (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static float Conv_Int16_bpToFloat(FInt16_bp integer16);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToIntVector (Int16)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static FIntVector Conv_Int16_bpToIntVector(FInt16_bp InInt);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToBool (Int16)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static bool Conv_Int16_bpToBool(FInt16_bp InInt);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToByte (Int16)", CompactNodeTitle = "->", Keywords="cast convert", BlueprintAutocast), Category="Math|Conversions")
	static uint8 Conv_Int16_bpToByte(FInt16_bp InInt);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Integer16", CompactNodeTitle = ">-"), Category = "Math|Int16")
	static FInt16_bp Make16BitInt(uint8 A, uint8 B);

	#pragma endregion

	#pragma region To Int16

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (integer)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_IntToInt16_bp(int32 int32ToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToRoundInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToInt16_bp(float floatToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToCeilInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToCeilInt16_bp(float floatToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloorInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToFloorInt16_bp(float floatToConvert);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (string)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_StringToInt16_bp(const FString& instring);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (bool)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static FInt16_bp Conv_BoolToInt16_bp(bool inbool);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (byte)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Conversions")
	static FInt16_bp Conv_ByteToInt16_bp(uint8 inint8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Bytes", CompactNodeTitle = "-<"), Category = "Math|Int16")
	static void Make8BitInts(FInt16_bp A, uint8& O1, uint8& O2);

	#pragma endregion

	#pragma endregion
};
