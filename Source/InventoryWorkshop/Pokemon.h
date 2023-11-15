// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pokemon.generated.h"

class UTrainerComponent;
UCLASS()
class INVENTORYWORKSHOP_API APokemon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APokemon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UTrainerComponent* GetTrainer();
	bool IsOwned();
	void SetTrainer(UTrainerComponent* NewTrainer);
	int GetLevel();
	void SetLevel(int NewLevel);

private:
	UTrainerComponent* Trainer;
	int Level;
};
