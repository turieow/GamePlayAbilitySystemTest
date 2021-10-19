// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GPAAttributeSet.generated.h"

// AttributeSet.hで紹介されているアトリビュートへのSetter,Getter定義マクロ
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 *
 */
UCLASS()
class UGPAAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// 初期値設定用コンストラクタ定義
	UGPAAttributeSet();

	// Blueprintアクセス可能としたMaxHealth定義、ATTRIBUTE_ACCESSORSによるアクセサ追記
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, MaxHealth);
	FGameplayAttribute MaxHealthAttribute();	// アトリビュート型取得関数

	// Blueprintアクセス可能としたHealth定義、ATTRIBUTE_ACCESSORSによるアクセサ追記
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, Health);
	FGameplayAttribute HealthAttribute();		// アトリビュート型取得関数

	// Blueprintアクセス可能としたMaxSpeed定義、ATTRIBUTE_ACCESSORSによるアクセサ追記
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, MaxSpeed);
	FGameplayAttribute MaxSpeedAttribute();		// アトリビュート型取得関数

	// Blueprintアクセス可能としたダメージ定義、ATTRIBUTE_ACCESSORSによるアクセサ追記
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, Damage);
	FGameplayAttribute DamageAttribute();		// アトリビュート型取得関数

	/** エフェクトによりアトリビュートが変化した場合のPost処理。主にUE4で直接管理しているメンバへの書き戻しを行う　*/
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};