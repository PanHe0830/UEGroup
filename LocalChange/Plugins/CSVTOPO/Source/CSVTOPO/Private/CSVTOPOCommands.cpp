// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSVTOPOCommands.h"

#define LOCTEXT_NAMESPACE "FCSVTOPOModule"

void FCSVTOPOCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "CSVTOPO", "Execute CSVTOPO action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
