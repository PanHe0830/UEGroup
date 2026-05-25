// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSVTOPO.h"
#include "CSVTOPOStyle.h"
#include "CSVTOPOCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName CSVTOPOTabName("CSVTOPO");

#define LOCTEXT_NAMESPACE "FCSVTOPOModule"

void FCSVTOPOModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FCSVTOPOStyle::Initialize();
	FCSVTOPOStyle::ReloadTextures();

	FCSVTOPOCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FCSVTOPOCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FCSVTOPOModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FCSVTOPOModule::RegisterMenus));
}

void FCSVTOPOModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FCSVTOPOStyle::Shutdown();

	FCSVTOPOCommands::Unregister();
}

void FCSVTOPOModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FCSVTOPOModule::PluginButtonClicked()")),
							FText::FromString(TEXT("CSVTOPO.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FCSVTOPOModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FCSVTOPOCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FCSVTOPOCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCSVTOPOModule, CSVTOPO)