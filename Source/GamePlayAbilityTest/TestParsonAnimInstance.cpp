// Fill out your copyright notice in the Description page of Project Settings.


#include "TestParsonAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

UTestParsonAnimInstance::UTestParsonAnimInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UTestParsonAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	UE_LOG(LogTemp, Log, TEXT("UTestParsonAnimInstance::NativeBeginPlay()"));
}

void UTestParsonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// 開始イベントをバインド
	AddNativeStateEntryBinding(FName(TEXT("StateMachineName")), FName(TEXT("StateName")), FOnGraphStateChanged::CreateUObject(this, &UTestParsonAnimInstance::OnEntry));

	// 離脱イベントをバインド
	AddNativeStateExitBinding(FName(TEXT("StateMachineName")), FName(TEXT("StateName")), FOnGraphStateChanged::CreateUObject(this, &UTestParsonAnimInstance::OnExit));
	
	UE_LOG(LogTemp, Log, TEXT("UTestParsonAnimInstance::NativeInitialzeAnimation()"));
}

void UTestParsonAnimInstance::OnEntry(const struct FAnimNode_StateMachine& ENGINE_AnimStateMachineTypes_generated_h, int32 PrevStateIndex, int32 NextStateIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Entry"));
}

void UTestParsonAnimInstance::OnExit(const struct FAnimNode_StateMachine& Machine, int32 PrevStateIndex, int32 NextStateIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Exit"));
}

void UTestParsonAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("UTestParsonAnimInstance::NativeUpdateAnimation()"));
}

void UTestParsonAnimInstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();

	UE_LOG(LogTemp, Log, TEXT("UTestParsonAnimInstance::NativePostEvaluateAnimation()"));
}

void UTestParsonAnimInstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();

	UE_LOG(LogTemp, Log, TEXT("UTestParsonAnimInstance::NativeUninitializeAnimation()"));
}

bool UTestParsonAnimInstance::TestRule()
{
	UE_LOG(LogTemp, Log, TEXT("TestRule!"));

	auto _Pawn = TryGetPawnOwner();
	if (_Pawn == nullptr)
	{
		return (false);
	}

	bool _IsFall = _Pawn->GetMovementComponent()->IsFalling();
	return(_IsFall);
}

