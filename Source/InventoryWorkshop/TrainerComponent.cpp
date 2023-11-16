// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainerComponent.h"
#include "Pokemon.h"
#include "Command.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
UTrainerComponent::UTrainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CapturedPokemon = TArray<APokemon*>();
	ActionHistory = TArray<Command*>();
}


// Called when the game starts
void UTrainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTrainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<APokemon*>* UTrainerComponent::getCapturedPokemon()
{
	return &CapturedPokemon;
}

void UTrainerComponent::SetCapturedPokemon(const TArray<APokemon*>& NewCapturedPokemon)
{
	CapturedPokemon = NewCapturedPokemon;
}

void UTrainerComponent::PickupItem(AItem * NewItem)
{
	FString ItemName = UKismetSystemLibrary::GetDisplayName(Cast<UObject*>(NewItem));
	if (Inventory.Contains(ItemName))
	{
		++Inventory[ItemName];
	}
	else 
	{
		Inventory.Add(ItemName, 1);
	}
}

