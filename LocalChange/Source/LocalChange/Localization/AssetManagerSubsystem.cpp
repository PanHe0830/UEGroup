// Fill out your copyright notice in the Description page of Project Settings.


#include "Localization/AssetManagerSubsystem.h"
#include "Internationalization/Internationalization.h"
#include "Internationalization/Culture.h"

void UAssetManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FInternationalization::Get().OnCultureChanged().AddUObject(this, &UAssetManagerSubsystem::HandleCultureChanged);
    LocalizationTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Asset/NewDataTable"));
}

void UAssetManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	FInternationalization::Get().OnCultureChanged().RemoveAll(this); // 或 RemoveUObject
}

void UAssetManagerSubsystem::HandleCultureChanged()
{
    FString CurrentCulture = FInternationalization::Get().GetCurrentCulture()->GetName();

    LanguageType NewCultureType = ConvertStringToCultureType(CurrentCulture);

    if (CultureChange.IsBound())
    {
        CultureChange.Broadcast(NewCultureType);
    }
}

void UAssetManagerSubsystem::LoadSyncAssets(FName Key, TFunction<void(UObject*)> callBack, LanguageType Type)
{
    if (!LocalizationTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("datatable is nullptr"));
    }

    FLocalizedTextureRow* RowData = LocalizationTable->FindRow<FLocalizedTextureRow>(Key,"FLocalizedTextureRow");
    UObject* retAsset = nullptr;
    if (RowData)
    {
        switch (Type)   
        {
        case LanguageType::ZhCN:
            retAsset = RowData->ZhCN.LoadSynchronous();
            break;
        case LanguageType::EN:
            retAsset = RowData->En.LoadSynchronous();
            break;
        case LanguageType::KO:
            retAsset = RowData->KoKR.LoadSynchronous();
            break;
        case LanguageType::Other:
        default:
            UE_LOG(LogTemp, Warning, TEXT("no this language"));
            break;
        }
    }

    callBack(retAsset);
}

LanguageType UAssetManagerSubsystem::ConvertStringToCultureType(FString NewCulture)
{
    if (NewCulture.StartsWith(TEXT("zh")))
    {
        return LanguageType::ZhCN;
    }
    else if (NewCulture.StartsWith(TEXT("en")))
    {
        return LanguageType::EN;
    }
    else if (NewCulture.StartsWith(TEXT("ko")))
    {
        return LanguageType::KO;
    }
    return LanguageType::Other;
}