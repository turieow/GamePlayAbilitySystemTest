// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GamePlayAbilityTest\GAS_BP\GPAAttributeSet.h"
#include "GAS_Character.generated.h"

UCLASS(config = Game)
class AGAS_Character : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AGAS_Character();

    /** ability system */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
        class UAbilitySystemComponent* AbilitySystem;
    UAbilitySystemComponent* GetAbilitySystemComponent() const
    {
        return AbilitySystem;
    };
    /** ability list */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
        TArray<TSubclassOf<class UGameplayAbility>> AbilityList;

    /** BeginPlay, PossessedBy override */
    virtual void BeginPlay() override;
    virtual void PossessedBy(AController* NewController) override;

    /** AttributeSet */
    UPROPERTY()
    UGPAAttributeSet* AttributeSet; // キャラクターが保持するアトリビュートセット

    // アトリビュート変更時のキャラクタへの反映関数
    void HandleMaxSpeedChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);
};
