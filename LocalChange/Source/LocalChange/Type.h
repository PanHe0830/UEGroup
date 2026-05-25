// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Type.generated.h"

UENUM(BlueprintType)
enum class LanguageType : uint8
{
    ZhCN,
    EN,
    KO,
    Other
};

UENUM(BlueprintType)
enum class ESeasonType : uint8
{
    Spring  UMETA(DisplayName = "春"),
    Summer  UMETA(DisplayName = "夏"),
    Autumn  UMETA(DisplayName = "秋"),
    Winter  UMETA(DisplayName = "冬")
};

USTRUCT(BlueprintType)
struct FLocalizedTextureRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UObject> ZhCN;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UObject> En;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UObject> KoKR;
};