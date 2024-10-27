// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTreeTask_DataStoreSet.h"
#include "StateTreePropertyBindings.h"

#if WITH_EDITOR
void FStateTreeTask_DataStoreSet::PostEditNodeChangeChainProperty(
    const FPropertyChangedChainEvent& PropertyChangedEvent, FStateTreeDataView InstanceDataView)
{
    FStateTreeTaskCommonBase::PostEditNodeChangeChainProperty(PropertyChangedEvent, InstanceDataView);
}

void FStateTreeTask_DataStoreSet::PostEditInstanceDataChangeChainProperty(
    const FPropertyChangedChainEvent& PropertyChangedEvent, FStateTreeDataView InstanceDataView)
{
    FStateTreeTaskCommonBase::PostEditInstanceDataChangeChainProperty(PropertyChangedEvent, InstanceDataView);

    const auto CurrentProperty = PropertyChangedEvent.Property;

    if (CurrentProperty->GetName() == GET_MEMBER_NAME_CHECKED(UStateTreeTask_DataStoreSet_InstanceData, Property))
    {
        
    }
}

void FStateTreeTask_DataStoreSet::OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
                                                   const FStateTreePropertyPath& SourcePath,
                                                   const FStateTreePropertyPath& TargetPath,
                                                   const IStateTreeBindingLookup& BindingLookup)
{
    FStateTreeTaskCommonBase::OnBindingChanged(ID, InstanceData, SourcePath, TargetPath, BindingLookup);

    if (!TargetPath.GetStructID().IsValid())
    {
        return;
    }

    const auto Instance = InstanceData.GetMutablePtr<UStateTreeTask_DataStoreSet_InstanceData>();
    if (!TargetPath.IsPathEmpty() && TargetPath.GetSegments().Last().GetName() == GET_MEMBER_NAME_CHECKED(
        UStateTreeTask_DataStoreSet_InstanceData, DataStore))
    {
        Instance->Reset();

        const auto BoundProperty = BindingLookup.GetPropertyPathLeafProperty(SourcePath);

        if (const auto DSProperty = CastField<FObjectPropertyBase>(BoundProperty))
        {
            const auto DsInstanceClass = DSProperty->PropertyClass;
            if (DsInstanceClass && DsInstanceClass->IsChildOf(UStateTreeDataStore_Base::StaticClass()))
            {
                Instance->DsClass = DsInstanceClass;
            }
        }
    }
}
#endif
