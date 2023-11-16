// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrainerComponent.generated.h"

class APokemon;
class Command;
class AItem;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYWORKSHOP_API UTrainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrainerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TArray<APokemon*>* getCapturedPokemon();
	void SetCapturedPokemon(const TArray<APokemon*>& NewCapturedPokemon);
	void PickupItem(AItem* NewItem);

private:
	TMap<FString, int> Inventory;
	TArray<APokemon*> CapturedPokemon;
	TArray<Command*> ActionHistory;
		
};
