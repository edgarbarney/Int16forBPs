// Copyright FranticDreamer. All Rights Reserved.

#include "Int16forBPs.h"

#define LOCTEXT_NAMESPACE "FInt16forBPsModule"

void FInt16forBPsModule::StartupModule()
{
	// This code will execute after the module is loaded into memory.
	// The exact timing is specified in the .uplugin file per-module.
}

void FInt16forBPsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up the module.  
	// For modules that support dynamic reloading;
	// We call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInt16forBPsModule, Int16forBPs)