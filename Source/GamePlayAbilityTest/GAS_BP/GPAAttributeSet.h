// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GPAAttributeSet.generated.h"

// AttributeSet.h�ŏЉ��Ă���A�g���r���[�g�ւ�Setter,Getter��`�}�N��
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
	// �����l�ݒ�p�R���X�g���N�^��`
	UGPAAttributeSet();

	// Blueprint�A�N�Z�X�\�Ƃ���MaxHealth��`�AATTRIBUTE_ACCESSORS�ɂ��A�N�Z�T�ǋL
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, MaxHealth);
	FGameplayAttribute MaxHealthAttribute();	// �A�g���r���[�g�^�擾�֐�

	// Blueprint�A�N�Z�X�\�Ƃ���Health��`�AATTRIBUTE_ACCESSORS�ɂ��A�N�Z�T�ǋL
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, Health);
	FGameplayAttribute HealthAttribute();		// �A�g���r���[�g�^�擾�֐�

	// Blueprint�A�N�Z�X�\�Ƃ���MaxSpeed��`�AATTRIBUTE_ACCESSORS�ɂ��A�N�Z�T�ǋL
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, MaxSpeed);
	FGameplayAttribute MaxSpeedAttribute();		// �A�g���r���[�g�^�擾�֐�

	// Blueprint�A�N�Z�X�\�Ƃ����_���[�W��`�AATTRIBUTE_ACCESSORS�ɂ��A�N�Z�T�ǋL
	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UGPAAttributeSet, Damage);
	FGameplayAttribute DamageAttribute();		// �A�g���r���[�g�^�擾�֐�

	/** �G�t�F�N�g�ɂ��A�g���r���[�g���ω������ꍇ��Post�����B���UE4�Œ��ڊǗ����Ă��郁���o�ւ̏����߂����s���@*/
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};