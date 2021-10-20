// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestParsonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYABILITYTEST_API UTestParsonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
    // �R���X�g���N�^
    UTestParsonAnimInstance(const FObjectInitializer& ObjectInitializer);

    // �A�j���[�V�����̏�������
    virtual void NativeInitializeAnimation() override;
    // �A�j���[�V�����̍X�V��
    virtual void NativeUpdateAnimation(float DeltaTime) override;
    // �A�j���[�V�����]����
    virtual void NativePostEvaluateAnimation() override;
    // �A�j���[�V�����̏I������
    virtual void NativeUninitializeAnimation() override;

    // �C�x���g�J�n��
    virtual void NativeBeginPlay() override;

    UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
        bool TestRule();

    void OnEntry(const struct FAnimNode_StateMachine& ENGINE_AnimStateMachineTypes_generated_h, int32 PrevStateIndex, int32 NextStateIndex);
    void OnExit(const struct FAnimNode_StateMachine& Machine, int32 PrevStateIndex, int32 NextStateIndex);
};
