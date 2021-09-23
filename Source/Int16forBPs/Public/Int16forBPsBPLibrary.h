// Copyright FranticDreamer. All Rights Reserved.

#pragma once

#include "Net/UnrealNetwork.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/GameEngine.h"
#include "Int16forBPsBPLibrary.generated.h"

#define DEBUG(x) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x); }

/** 
* An implementation of 16 Bit Unsigned Integer - Integer16 for UE4 Blueprints
* 
* Mainly for reducing memory and network size by tradin some CPU time.
*/
USTRUCT(BlueprintType, DisplayName = "Integer16")
struct FInt16_bp
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer1; /**< First byte that creates Int16. */
	UPROPERTY(VisibleAnywhere)
	uint8 unsigned_integer2; /**< Second byte that creates Int16. */

	/* --	Consturctors	-- */

	/** Constructor for constructing Int16 using an Int32  */
	FORCEINLINE FInt16_bp()
	{
		unsigned_integer2 = 0;
		unsigned_integer1 = 0;
	}

	/** Constructor for constructing Int16 using two uint8s  */
	FORCEINLINE FInt16_bp(uint8 a, uint8 b)
	{
		unsigned_integer2 = a;
		unsigned_integer1 = b;
	}

	/** Constructor for constructing Int16 using an Int32  */
	FORCEINLINE FInt16_bp(int a)
	{
		unsigned_integer2 = uint8(a >> 8);
		unsigned_integer1 = uint8(a & 0x00ff);
	}

	/* --	Conversion Operators	-- */

	/** Operator for Converting Int16 to Int32 */
	FORCEINLINE operator int() 
	{
		return (int)((unsigned_integer2 << 8) | unsigned_integer1);
	}

	/** Inline Function for Converting Int32 to Int16 */
	FORCEINLINE void fromInt(int integ)
	{
		unsigned_integer2 = uint8(integ >> 8);
		unsigned_integer1 = uint8(integ & 0x00ff);
	}

};

/**
* Function Library for 16 Bit Unsigned Integer - Integer16
*
* Includes Maths and Conversion Functions.
*/
UCLASS()
class UInt16forBPsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	#pragma region Arithmetic Nodes

	/** Increases given Integer16 by 1. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Increment Int16", CompactNodeTitle = "++", Keywords = "+ plus"), Category = "Math|Int16")
	static FInt16_bp incrementint16(FInt16_bp A);

	/** Decrases given Integer16 by 1. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Decrement Int16", CompactNodeTitle = "--", Keywords = "- minus"), Category = "Math|Int16")
	static FInt16_bp decrementint16(FInt16_bp A);

	/** Addition ( A (Integer16) + B (Integer) ) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int", CompactNodeTitle = "+", Keywords = "+ plus"), Category = "Math|Int16")
	static FInt16_bp int16plusint(FInt16_bp A, int32 B);

	/** Addition (A + B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 + int16", CompactNodeTitle = "+", Keywords = "+ plus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16plusint16(FInt16_bp A, FInt16_bp B);

	/** Subtraction ( A (Integer16) - B (Integer) ) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int", CompactNodeTitle = "-", Keywords = "- minus"), Category = "Math|Int16")
	static FInt16_bp int16minusint(FInt16_bp A, int32 B);

	/** Subtraction (A - B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 - int16", CompactNodeTitle = "-", Keywords = "- minus", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16minusint16(FInt16_bp A, FInt16_bp B);

	/** Division ( A (Integer16) / B (Integer) ) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int", CompactNodeTitle = "/", Keywords = "/ divide "), Category = "Math|Int16")
	static FInt16_bp int16divideint(FInt16_bp A, int32 B = 1);

	/** Division (A / B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 / int16", CompactNodeTitle = "/", Keywords = "/ divide ", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16divideint16(FInt16_bp A, FInt16_bp B);

	/** Multiplication ( A (Integer16) * B (Integer) ) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int", CompactNodeTitle = "*", Keywords = "* multiply times"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint(FInt16_bp A, int32 B);

	/** Multiplication (A * B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "int16 * int16", CompactNodeTitle = "*", Keywords = "* multiply times", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int16")
	static FInt16_bp int16multiplyint16(FInt16_bp A, FInt16_bp B);

	/** Modulo (A % B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulus(FInt16_bp A, FInt16_bp B);

	/** Modulo ( A (Integer16) % B (Integer) ) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "% (int16 % int)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|Int16")
	static FInt16_bp int16modulusint(FInt16_bp A, int32 B = 1);

	/** Returns true if A is less than B (A < B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 < int16", CompactNodeTitle = "<", Keywords = "< less"), Category="Math|Int16")
	static bool Less_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if A is greater than B (A > B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 > int16", CompactNodeTitle = ">", Keywords = "> greater"), Category="Math|Int16")
	static bool Greater_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if A is less than or equal to B (A <= B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 <= int16", CompactNodeTitle = "<=", Keywords = "<= less"), Category="Math|Int16")
	static bool LessEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if A is greater than or equal to B (A >= B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "int16 >= int16", CompactNodeTitle = ">=", Keywords = ">= greater"), Category="Math|Int16")
	static bool GreaterEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if A is equal to B (A == B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal (int16)", CompactNodeTitle = "==", Keywords = "== equal"), Category="Math|Int16")
	static bool EqualEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if A is not equal to B (A != B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "NotEqual (int16)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category="Math|Int16")
	static bool NotEqual_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Returns true if value is between Min and Max (V >= Min && V <= Max)
	 * If InclusiveMin is true, value needs to be equal or larger than Min, else it needs to be larger
	 * If InclusiveMax is true, value needs to be smaller or equal than Max, else it needs to be smaller
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "InRange (int16)"), Category = "Math|Int16")
	static bool InRange_Int16Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max, bool InclusiveMin = true, bool InclusiveMax = true);

	/** Bitwise AND (A & B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise AND", CompactNodeTitle = "&", Keywords = "& and", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp And_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Bitwise XOR (A ^ B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise XOR", CompactNodeTitle = "^", Keywords = "^ xor"), Category="Math|Int16")
	static FInt16_bp Xor_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Bitwise OR (A | B) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Bitwise OR", CompactNodeTitle = "|", Keywords = "| or", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Or_Int16Int16(FInt16_bp A, FInt16_bp B);

	/** Bitwise NOT (~A) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Bitwise NOT", CompactNodeTitle = "~", Keywords = "~ not"), Category = "Math|Int16")
	static FInt16_bp Not_Int16(FInt16_bp A);

	/** Returns a uniformly distributed random number between 0 and Max - 1 */
	UFUNCTION(BlueprintPure, Category="Math|Random", meta=(NotBlueprintThreadSafe))
	static FInt16_bp RandomInt16(FInt16_bp Max);

	/** Return a random integer between Min and Max (>= Min and <= Max) */
	UFUNCTION(BlueprintPure, Category="Math|Random", meta = (NotBlueprintThreadSafe))
	static FInt16_bp RandomInt16InRange(FInt16_bp Min, FInt16_bp Max);

	/** Returns the minimum value of A and B */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Min (int16)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Min_Int16(FInt16_bp A, FInt16_bp B);

	/** Returns the maximum value of A and B */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Max (int16)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"), Category="Math|Int16")
	static FInt16_bp Max_Int16(FInt16_bp A, FInt16_bp B);

	/** Returns Value clamped to be between A and B (inclusive) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Clamp (int16)"), Category="Math|Int16")
	static FInt16_bp Clamp_Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max);

	/** Returns Value between A and B (inclusive) that wraps around */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Wrap (int16)"), Category = "Math|Int16")
	static FInt16_bp Wrap_Int16(FInt16_bp Value, FInt16_bp Min, FInt16_bp Max);

	/** Returns the absolute (positive) value of A */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Absolute (int16)", CompactNodeTitle = "ABS"), Category="Math|Int16")
	static FInt16_bp Abs_Int16(FInt16_bp A);

	#pragma endregion

public:

	#pragma region Conversion Nodes

	#pragma region From Int16

	/** Converts an Integer16 to an Integer */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static int32 Conv_Int16_bpToInt(FInt16_bp integer16);

	/** Converts an Integer16 to a String */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FString Conv_Int16_bpToString(FInt16_bp integer16);

	/** Converts an Integer16 to a Float */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloat (int16)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static float Conv_Int16_bpToFloat(FInt16_bp integer16);

	/** Converts an Integer16 to a IntVector */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToIntVector (Int16)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static FIntVector Conv_Int16_bpToIntVector(FInt16_bp InInt);

	/** Converts an Integer16 to a Boolean */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToBool (Int16)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static bool Conv_Int16_bpToBool(FInt16_bp InInt);
	
	/** Converts an Integer16 to a byte (if the Integer16 is too large, returns the low 8 bits) */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToByte (Int16)", CompactNodeTitle = "->", Keywords="cast convert", BlueprintAutocast), Category="Math|Conversions")
	static uint8 Conv_Int16_bpToByte(FInt16_bp InInt);

	/** Combine two Bytes into an Integer16 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Integer16", CompactNodeTitle = ">-"), Category = "Math|Int16")
	static FInt16_bp Make16BitInt(uint8 A, uint8 B);

	#pragma endregion

	#pragma region To Int16

	/** Converts an Integer to an Integer16 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (integer)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_IntToInt16_bp(int32 int32ToConvert);

	/**  Converts a Float to an Integer16 by rouding up to the nearest integer (e.g., -1.6 becomes -2 and 1.6 becomes 2) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToRoundInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToInt16_bp(float floatToConvert);

	/** Converts a Float to an Integer16 by rouding up to the next integer (e.g., -1.6 becomes -1 and 1.6 becomes 2) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToCeilInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToCeilInt16_bp(float floatToConvert);
	
	/** Converts a Float to an Integer16 by rouding down to the previous integer (e.g., -1.6 becomes -2 and 1.6 becomes 1) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFloorInt16 (float)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "toint16 cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_FloatToFloorInt16_bp(float floatToConvert);

	/** Converts a String to an Integer16 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (string)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "cast convert"), Category = "Math|Int16")
	static FInt16_bp Conv_StringToInt16_bp(const FString& instring);

	/** Converts a Boolean to an Integer16 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (bool)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Int16")
	static FInt16_bp Conv_BoolToInt16_bp(bool inbool);

	/** Converts a Byte to an Integer16 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt16 (byte)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Math|Conversions")
	static FInt16_bp Conv_ByteToInt16_bp(uint8 inint8);

	/** Split an Integer16 into two Bytes */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Bytes", CompactNodeTitle = "-<"), Category = "Math|Int16")
	static void Make8BitInts(FInt16_bp A, uint8& O1, uint8& O2);

	#pragma endregion

	#pragma endregion
};
