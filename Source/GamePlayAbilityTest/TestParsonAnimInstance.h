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
    // コンストラクタ
    UTestParsonAnimInstance(const FObjectInitializer& ObjectInitializer);

    // アニメーションの初期化時
    virtual void NativeInitializeAnimation() override;
    // アニメーションの更新時
    virtual void NativeUpdateAnimation(float DeltaTime) override;
    // アニメーション評価後
    virtual void NativePostEvaluateAnimation() override;
    // アニメーションの終了化時
    virtual void NativeUninitializeAnimation() override;

    // イベント開始時
    virtual void NativeBeginPlay() override;

    UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
        bool TestRule();

    void OnEntry(const struct FAnimNode_StateMachine& ENGINE_AnimStateMachineTypes_generated_h, int32 PrevStateIndex, int32 NextStateIndex);
    void OnExit(const struct FAnimNode_StateMachine& Machine, int32 PrevStateIndex, int32 NextStateIndex);
};
