// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Type.h"
#include "TestUserWidget.generated.h"

class UDataTable;
class UImage;

/**
 * 
 */
UCLASS()
class LOCALCHANGE_API UTestUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	UFUNCTION()
	void OnCultureChangedHandler(LanguageType NewCulture);

public:
	UPROPERTY(meta = (BindWidget))
	UImage* Image;

	UPROPERTY(meta = (BindWidget))
	UImage* Image2;

	UPROPERTY(meta = (BindWidget))
	UImage* Image3;
};
