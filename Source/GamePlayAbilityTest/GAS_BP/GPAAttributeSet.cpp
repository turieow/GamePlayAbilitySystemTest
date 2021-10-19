// Fill out your copyright notice in the Description page of Project Settings.

#include "GPAAttributeSet.h"
#include "GameplayEffectExtension.h"	// PostGameplayEffectExecuteのContextデータなどを扱うのに必要
#include "GamePlayAbilityTest\GAS_BP\GAS_Character.h"				// GPACharacterの関数呼び出しに必要

/** コンストラクタにより初期値設定 */
UGPAAttributeSet::UGPAAttributeSet()
	: MaxHealth(100.f)
	, Health(100.f)
	, MaxSpeed(600.f)
	, Damage(0.f)
{
}

// アトリビュート型取得関数
FGameplayAttribute UGPAAttributeSet::MaxHealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, MaxHealth));
	return FGameplayAttribute(Property);
}

// アトリビュート型取得関数
FGameplayAttribute UGPAAttributeSet::HealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, Health));
	return FGameplayAttribute(Property);
}

// アトリビュート型取得関数
FGameplayAttribute UGPAAttributeSet::MaxSpeedAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

// アトリビュート型取得関数
FGameplayAttribute UGPAAttributeSet::DamageAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, Damage));
	return FGameplayAttribute(Property);
}

void UGPAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// 受け取ったデータから各種情報を取得
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// GameplayEffectにより指定されたアトリビュート変化値を計算
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// 受け取ったデータからターゲットアクター、コントローラ、キャラクタの取得
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	AGAS_Character* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AGAS_Character>(TargetActor);
	}

	// 受け取ったデータがMaxSpeedだった場合にCharacter側の最大移動スピードに反映させる
	if (Data.EvaluatedData.Attribute == GetMaxSpeedAttribute())
	{
		if (TargetCharacter)
		{
			TargetCharacter->HandleMaxSpeedChanged(DeltaValue, SourceTags);
		}
	}
}