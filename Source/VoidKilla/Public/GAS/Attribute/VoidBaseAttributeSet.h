// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "VoidBaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */

UCLASS()
class VOIDKILLA_API UVoidBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UVoidBaseAttributeSet();


	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) 
		override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) 
		override;

	UPROPERTY(BlueprintReadOnly, Category = "Void|Attributes", 
		ReplicatedUsing = OnRep_VoidEnergy)
	FGameplayAttributeData VoidEnergy;
	ATTRIBUTE_ACCESSORS(UVoidBaseAttributeSet, VoidEnergy)

	UPROPERTY(BlueprintReadOnly, Category = "Void|Attributes", 
		ReplicatedUsing = OnRep_MaxVoidEnergy)
	FGameplayAttributeData MaxVoidEnergy;
	ATTRIBUTE_ACCESSORS(UVoidBaseAttributeSet, MaxVoidEnergy)

	UFUNCTION()
	void OnRep_VoidEnergy(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxVoidEnergy(const FGameplayAttributeData& OldValue);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
		override;
};
