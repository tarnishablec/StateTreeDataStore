// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeDataStore_Base.h"
#include "StateTreePropertyRef.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"

#include "StateTreeTask_DataStoreSet.generated.h"

UCLASS()
class UStateTreeTask_DataStoreSet_InstanceData : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
    TObjectPtr<UStateTreeDataStore_Base> DataStore;

    UPROPERTY(EditAnywhere, BlueprintReadWrite
        , meta=(GetOptions="GetPropertyNames")
    )
    FName Property;


    // Wait For UE5.5 Update , Support Multiple type Specification
    // https://github.com/EpicGames/UnrealEngine/blob/dev-5.5/Engine/Plugins/Runtime/StateTree/Source/StateTreeModule/Public/StateTreePropertyRef.h
    UPROPERTY(EditAnywhere
        // , meta=(RefType = "???")
    )
    FStateTreePropertyRef Value;

    UPROPERTY()
    TSubclassOf<UStateTreeDataStore_Base> DsClass;

    UFUNCTION()
    TArray<FString> GetPropertyNames() const
    {
        TArray<FString> Result{};
        if (DsClass)
        {
            for (TFieldIterator<FProperty> It(DsClass); It; ++It)
            {
                Result.Add(*It->GetFName().ToString());
            }
        }

        return Result;
    };

    void Reset()
    {
        Property = FName();
        DsClass = nullptr;
    }
};

// STATETREE_POD_INSTANCEDATA(UStateTreeTask_DSSet_InstanceData)

/**
 * 
 */
USTRUCT(BlueprintType)
struct STATETREEDATASTORE_API FStateTreeTask_DataStoreSet : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    virtual const UStruct* GetInstanceDataType() const override
    {
        return UStateTreeTask_DataStoreSet_InstanceData::StaticClass();
    }

#if WITH_EDITOR
    virtual void PostEditNodeChangeChainProperty(const FPropertyChangedChainEvent& PropertyChangedEvent,
                                                 FStateTreeDataView InstanceDataView) override;
    virtual void PostEditInstanceDataChangeChainProperty(const FPropertyChangedChainEvent& PropertyChangedEvent,
                                                         FStateTreeDataView InstanceDataView) override;
    virtual void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
                                  const FStateTreePropertyPath& SourcePath, const FStateTreePropertyPath& TargetPath,
                                  const IStateTreeBindingLookup& BindingLookup) override;
#endif
};
