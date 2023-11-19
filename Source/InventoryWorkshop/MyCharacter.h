// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UTrainerComponent;
UCLASS()
class INVENTORYWORKSHOP_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* SpringArmComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* CameraMovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* CharacterMovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* PokeballAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* RareCandyAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* UndoAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext* Context;


	UTrainerComponent* TrainerComponent;
private:
	void CharacterJump(const FInputActionValue& Value);
	void CharacterMovement(const FInputActionValue& Value);
	void CameraMovement(const FInputActionValue& Value);
};
