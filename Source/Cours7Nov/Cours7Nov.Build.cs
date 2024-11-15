// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cours7Nov : ModuleRules
{
	public Cours7Nov(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
