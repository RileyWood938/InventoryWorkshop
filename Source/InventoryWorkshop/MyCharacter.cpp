// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TrainerComponent.h"



// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);  // Attach the spring arm to the root component
	SpringArmComponent->TargetArmLength = 1000;

	// Create and attach the camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);  // Attach the camera to the spring arm

	TrainerComponent = CreateDefaultSubobject<UTrainerComponent>(TEXT("TrainerComponent"));

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) 
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Context, 0);
		}
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) { //Cast PlayerInputComponent to Enhanced Version
		enhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::CharacterJump); //binds ARunner::Move to the MoveAction UInputAction
		enhancedInputComponent->BindAction(CharacterMovementAction, ETriggerEvent::Triggered, this, &AMyCharacter::CharacterMovement); //binds ARunner::Move to the MoveAction UInputAction
		enhancedInputComponent->BindAction(CameraMovementAction, ETriggerEvent::Triggered, this, &AMyCharacter::CameraMovement); //binds ARunner::Move to the MoveAction UInputAction

	}

}

void AMyCharacter::CharacterJump(const FInputActionValue& Value)
{
	const bool currentValue = Value.Get<bool>();
	if (currentValue) {
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("hit")));
		Jump();

	}
}

void AMyCharacter::CharacterMovement(const FInputActionValue& Value)
{
	const FVector2D movementVector = Value.Get<FInputActionValue::Axis2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, movementVector.Y);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, movementVector.X);
}

void AMyCharacter::CameraMovement(const FInputActionValue& Value)
{
	const FVector2D lookAxisValue = Value.Get<FVector2D>();
	if (GetController()) {
		AddControllerYawInput(lookAxisValue.X);
		AddControllerPitchInput(lookAxisValue.Y);
	}
}

