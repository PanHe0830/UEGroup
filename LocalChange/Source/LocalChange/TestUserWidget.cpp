// Fill out your copyright notice in the Description page of Project Settings.


#include "TestUserWidget.h"
#include "Localization/AssetManagerSubsystem.h"

#include <Components/Image.h>
#include <Kismet/GameplayStatics.h>

void UTestUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    UGameInstance* Instance = UGameplayStatics::GetGameInstance(this);
    if (Instance)
    {
        UAssetManagerSubsystem* AssetManager = Instance->GetSubsystem<UAssetManagerSubsystem>();
        if (AssetManager)
        {
            AssetManager->CultureChange.AddDynamic(this, &UTestUserWidget::OnCultureChangedHandler);
        }
    }
}

void UTestUserWidget::NativeDestruct()
{
    Super::NativeDestruct();

    UGameInstance* Instance = UGameplayStatics::GetGameInstance(this);
    if (Instance)
    {
        UAssetManagerSubsystem* AssetManager = Instance->GetSubsystem<UAssetManagerSubsystem>();
        if (AssetManager)
        {
            AssetManager->CultureChange.RemoveDynamic(this, &UTestUserWidget::OnCultureChangedHandler);
        }
    }
}

void UTestUserWidget::OnCultureChangedHandler(LanguageType NewCulture)
{
    UGameInstance* Instance = UGameplayStatics::GetGameInstance(this);
    if (Instance)
    {
        UAssetManagerSubsystem* AssetManager = Instance->GetSubsystem<UAssetManagerSubsystem>();
        if (AssetManager)
        {
            AssetManager->LoadSyncAssets(
                "UI_Main_BG", 
                [this](UObject* Assets)
                {
                    UTexture2D* Texture2D = Cast<UTexture2D>(Assets);
                    if (Texture2D)
                    {
                        Image->SetBrushFromTexture(Texture2D);
                    }
                }, 
                NewCulture
            );
            AssetManager->LoadSyncAssets(
                "UI_Main_Icon",
                [this](UObject* Assets)
                {
                    UTexture2D* Texture2D = Cast<UTexture2D>(Assets);
                    if (Texture2D)
                    {
                        Image2->SetBrushFromTexture(Texture2D);
                    }
                },
                NewCulture
            );
            AssetManager->LoadSyncAssets(
                "UI_StartBtn",
                [this](UObject* Assets)
                {
                    UTexture2D* Texture2D = Cast<UTexture2D>(Assets);
                    if (Texture2D)
                    {
                        Image3->SetBrushFromTexture(Texture2D);
                    }
                },
                NewCulture
            );
        }
    }
}