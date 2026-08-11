// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AbilityCooldown.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"


bool UAbilityCooldown::GetCooldownTimeRemaining(UAbilitySystemComponent* ASC, 
	FGameplayTag CooldownTag, float& TimeRemaining, float& Duration)
{
	if (!ASC) return false;

	FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(
		FGameplayTagContainer(CooldownTag));

	TArray<float> Remaining = ASC->GetActiveEffectsTimeRemaining(Query);
	TArray<float> Durations = ASC->GetActiveEffectsDuration(Query);

	if (Remaining.Num() > 0)
	{
		TimeRemaining = Remaining[0];
		Duration = Durations.Num() > 0 ? Durations[0] : 0.f;
		return true;
	}

	return false;
}
