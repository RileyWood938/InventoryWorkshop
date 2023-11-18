// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainerComponent.h"
#include "Pokemon.h"
#include "Command.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PokeballCommand.h"

// Sets default values for this component's properties
UTrainerComponent::UTrainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CapturedPokemon = new TArray<APokemon*>();
	ActionHistory = new TArray<Command*>();
	Inventory = new TMap<FString, int>();

}


// Called when the game starts
void UTrainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CapturedPokemon = new TArray<APokemon*>();
	ActionHistory = new TArray<Command*>();
	Inventory = new TMap<FString, int>();
}


// Called every frame
void UTrainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<APokemon*>* UTrainerComponent::getCapturedPokemon()
{
	return CapturedPokemon;
}

void UTrainerComponent::SetCapturedPokemon(TArray<APokemon*>* NewCapturedPokemon)
{
	CapturedPokemon = NewCapturedPokemon;
}

void UTrainerComponent::PickupItem(AItem * NewItem, FString ItemType)
{

	if (Inventory->Contains(ItemType))
	{
		int32* ValuePtr = Inventory->Find(ItemType);
		(*ValuePtr)++;

	}
	else 
	{
		Inventory->Add(ItemType, 1);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, ItemType);
	FString IntString = "count: ";
	IntString.AppendInt(*(Inventory->Find(ItemType)));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, IntString);
	
}

void UTrainerComponent::UseItem(FString NameOfItemToUse, APokemon* Target) {
	if (Inventory->Contains(NameOfItemToUse)) {

		int32* ValuePtr = Inventory->Find(NameOfItemToUse);
		(*ValuePtr)--;

		Command* ActiveCommand;
		if (NameOfItemToUse == "Pokeball") {
			ActiveCommand = new PokeballCommand();
			ActiveCommand->ExecuteCommand(Target, this);
			ActionHistory->Push(ActiveCommand);
		}
	}
}
