// Copyright FranticDreamer. All Rights Reserved.

using UnrealBuildTool;

public class Int16forBPs : ModuleRules
{
	public Int16forBPs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", });

		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "Slate", "SlateCore", });
	}
}
