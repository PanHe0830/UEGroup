// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitiesLabCharacter.h"
#include "GASProject/GASP/LabAbilitySystemComponent.h"
#include "GASProject/GASP/LabHealthAttributeSet.h"

// Sets default values
AAbilitiesLabCharacter::AAbilitiesLabCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AbilityComponent = CreateDefaultSubobject<ULabAbilitySystemComponent>(TEXT("AbilityComponent"));
	HealthSet = CreateDefaultSubobject<ULabHealthAttributeSet>(TEXT("HealthSet"));
}

// Called when the game starts or when spawned
void AAbilitiesLabCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AbilityComponent->InitAbilityActorInfo(this, this);
}

UAbilitySystemComponent* AAbilitiesLabCharacter::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

// Called every frame
void AAbilitiesLabCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbilitiesLabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

