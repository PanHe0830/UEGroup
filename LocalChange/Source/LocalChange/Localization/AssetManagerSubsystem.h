// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Type.h"
#include "AssetManagerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCultureChanged, LanguageType, NewCulture);

/**
 * 
 */
UCLASS(Config = Game)
class LOCALCHANGE_API UAssetManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	void HandleCultureChanged();

public:
	void LoadSyncAssets(FName Key, TFunction<void(UObject*)> callBack, LanguageType Type);

private:
	LanguageType ConvertStringToCultureType(FString NewCulture);

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCultureChanged CultureChange;

	UPROPERTY()
	UDataTable* LocalizationTable;
};
