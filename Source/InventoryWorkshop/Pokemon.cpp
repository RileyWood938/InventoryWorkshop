// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon.h"
#include "TrainerComponent.h"

// Sets default values
APokemon::APokemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APokemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UTrainerComponent* APokemon::GetTrainer()
{
	return Trainer;
}

bool APokemon::IsOwned()
{
	return false;
}

void APokemon::SetTrainer(UTrainerComponent* NewTrainer)
{
	Trainer = NewTrainer;
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("New Trainer")));

}

int APokemon::GetLevel()
{
	return Level;
}

void APokemon::SetLevel(int NewLevel)
{
	Level = NewLevel;
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("New Level %d"), NewLevel));

}

