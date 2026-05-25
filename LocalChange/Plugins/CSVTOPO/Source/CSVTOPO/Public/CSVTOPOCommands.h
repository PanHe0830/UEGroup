// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "CSVTOPOStyle.h"

class FCSVTOPOCommands : public TCommands<FCSVTOPOCommands>
{
public:

	FCSVTOPOCommands()
		: TCommands<FCSVTOPOCommands>(TEXT("CSVTOPO"), NSLOCTEXT("Contexts", "CSVTOPO", "CSVTOPO Plugin"), NAME_None, FCSVTOPOStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
