// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attribute/VoidBaseAttributeSet.h"

UVoidBaseAttributeSet::UVoidBaseAttributeSet()
{
	InitVoidEnergy(100.f);
	InitMaxVoidEnergy(200.f);
}

void UVoidBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, 
	float& NewValue)
{
	if (Attribute == GetVoidEnergyAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxVoidEnergy());
	}
}

void UVoidBaseAttributeSet::PostGameplayEffectExecute(const 
	FGameplayEffectModCallbackData& Data)
{
}

void UVoidBaseAttributeSet::OnRep_VoidEnergy(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVoidBaseAttributeSet, VoidEnergy, OldValue);
}

void UVoidBaseAttributeSet::OnRep_MaxVoidEnergy(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVoidBaseAttributeSet, MaxVoidEnergy, OldValue);
}

void UVoidBaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& 
	OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UVoidBaseAttributeSet, VoidEnergy, COND_None, 
		REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVoidBaseAttributeSet, MaxVoidEnergy, COND_None, 
		REPNOTIFY_Always);
}
