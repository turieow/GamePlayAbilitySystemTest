#include "GamePlayAbilityTest\GAS_BP\GAS_Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystemComponent.h"

AGAS_Character::AGAS_Character()
{
    // ability system component
    AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
}

void AGAS_Character::BeginPlay()
{
    Super::BeginPlay();
    if (AbilitySystem)
    {
        int32 inputID(0);
        if (HasAuthority() && AbilityList.Num() > 0)
        {
            for (auto Ability : AbilityList) {
                if (Ability)
                {
                    AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, inputID++));
                }
            }
        }
        AbilitySystem->InitAbilityActorInfo(this, this);
    }
}

void AGAS_Character::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    AbilitySystem->RefreshAbilityActorInfo();
}