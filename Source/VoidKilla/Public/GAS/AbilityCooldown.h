// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilityCooldown.generated.h"

class UAbilitySystemComponent;
struct FGameplayTag;

/**
 * 
 */
UCLASS()
class VOIDKILLA_API UAbilityCooldown : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "GAS")
	static bool GetCooldownTimeRemaining(UAbilitySystemComponent* ASC, 
		FGameplayTag CooldownTag, float& TimeRemaining, float& Duration);
};
