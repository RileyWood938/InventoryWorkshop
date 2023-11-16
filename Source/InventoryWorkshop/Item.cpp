// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

    //// Set the radius of the sphere (adjust as needed)
    //SphereComponent->InitSphereRadius(50.0f);

    //// Attach the sphere component to the root component (or another component if desired)
    //SphereComponent->SetupAttachment(RootComponent);

    //// Register the sphere component so it is updated and rendered
    //SphereComponent->RegisterComponent();

	USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(40.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionComponent->SetGenerateOverlapEvents(true); // Enable overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) {
		AMyCharacter* character = Cast<AMyCharacter>(OtherActor);
		if (character)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Started"));
			//this->targetMovementComponent = character->GetCharacterMovement();
			//Activate();
			// This code will be executed when the actor overlaps with another actor
			// You can implement your logic here.
		}
	}
}

