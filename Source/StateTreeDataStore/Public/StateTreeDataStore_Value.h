// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StateTreeDataStore_Value.generated.h"

/**
 * 
 */
template <typename T>
struct STATETREEDATASTORE_API TStateTreeDataStore_Value
{
    T Value;
};


USTRUCT(BlueprintInternalUseOnly)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value
{
    GENERATED_BODY()

    // UPROPERTY()
    void* Value;
};


USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Int32 : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Value = 0;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Int32_Array : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<int32> Value;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Byte : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 Value = 0xFF;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Vector : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Value = FVector::ZeroVector;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Bool : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Value = false;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_String : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Value;
};

USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeDataStore_Value_Object : public FStateTreeDataStore_Value
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UObject> Value;
};
