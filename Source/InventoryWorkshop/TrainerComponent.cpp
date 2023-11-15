// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainerComponent.h"
#include "Pokemon.h"
#include "Command.h"

// Sets default values for this component's properties
UTrainerComponent::UTrainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PokeballCount = 0;
	RareCandyCount = 0;
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

int UTrainerComponent::GetPokeballCount()
{
	return PokeballCount;
}

void UTrainerComponent::SetPokeballCount(int NewPokeballCount)
{
	PokeballCount = NewPokeballCount;
}

int UTrainerComponent::GetRareCandyCount()
{
	return RareCandyCount;
}

void UTrainerComponent::SetRareCandyCount(int NewRareCandyCount)
{
	RareCandyCount = NewRareCandyCount;
}

TArray<APokemon*>* UTrainerComponent::getCapturedPokemon()
{
	return &CapturedPokemon;
}

void UTrainerComponent::SetCapturedPokemon(const TArray<APokemon*>& NewCapturedPokemon)
{
	CapturedPokemon = NewCapturedPokemon;
}

