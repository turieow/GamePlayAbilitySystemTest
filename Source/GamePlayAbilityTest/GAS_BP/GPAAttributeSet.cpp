// Fill out your copyright notice in the Description page of Project Settings.

#include "GPAAttributeSet.h"
#include "GameplayEffectExtension.h"	// PostGameplayEffectExecute��Context�f�[�^�Ȃǂ������̂ɕK�v
#include "GamePlayAbilityTest\GAS_BP\GAS_Character.h"				// GPACharacter�̊֐��Ăяo���ɕK�v

/** �R���X�g���N�^�ɂ�菉���l�ݒ� */
UGPAAttributeSet::UGPAAttributeSet()
	: MaxHealth(100.f)
	, Health(100.f)
	, MaxSpeed(600.f)
	, Damage(0.f)
{
}

// �A�g���r���[�g�^�擾�֐�
FGameplayAttribute UGPAAttributeSet::MaxHealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, MaxHealth));
	return FGameplayAttribute(Property);
}

// �A�g���r���[�g�^�擾�֐�
FGameplayAttribute UGPAAttributeSet::HealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, Health));
	return FGameplayAttribute(Property);
}

// �A�g���r���[�g�^�擾�֐�
FGameplayAttribute UGPAAttributeSet::MaxSpeedAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

// �A�g���r���[�g�^�擾�֐�
FGameplayAttribute UGPAAttributeSet::DamageAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UGPAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGPAAttributeSet, Damage));
	return FGameplayAttribute(Property);
}

void UGPAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// �󂯎�����f�[�^����e������擾
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// GameplayEffect�ɂ��w�肳�ꂽ�A�g���r���[�g�ω��l���v�Z
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// �󂯎�����f�[�^����^�[�Q�b�g�A�N�^�[�A�R���g���[���A�L�����N�^�̎擾
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	AGAS_Character* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AGAS_Character>(TargetActor);
	}

	// �󂯎�����f�[�^��MaxSpeed�������ꍇ��Character���̍ő�ړ��X�s�[�h�ɔ��f������
	if (Data.EvaluatedData.Attribute == GetMaxSpeedAttribute())
	{
		if (TargetCharacter)
		{
			TargetCharacter->HandleMaxSpeedChanged(DeltaValue, SourceTags);
		}
	}
}