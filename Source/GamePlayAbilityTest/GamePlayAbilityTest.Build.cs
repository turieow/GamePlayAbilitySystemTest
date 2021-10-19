// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GamePlayAbilityTest : ModuleRules
{
	public GamePlayAbilityTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayAbilities", "GameplayAbilities"});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
