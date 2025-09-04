// Fill out your copyright notice in the Description page of Project Settings.


#include "BallChar.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values
ABallChar::ABallChar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a set root component
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));// Create a sphere component for collision detection
	RootComponent = SphereComp;// Set the sphere component as the root component
	SphereComp->SetSimulatePhysics(true);// Enable physics simulation for the sphere component
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);// Enable collision for the sphere component

	//Mesh Component
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));// Create a static mesh component for visual representation
	MeshComp->SetupAttachment(RootComponent);// Attach the mesh component to the root component
	MeshComp->SetSimulatePhysics(false);// Enable physics simulation for the mesh component

	//Movement Component
	MovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComp"));// Create a floating pawn movement component for handling movement logic
	MovementComp->UpdatedComponent = RootComponent;// Set the root component as the updated component for movement
}

// Called when the game starts or when spawned
void ABallChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent ->BindAxis("MoveForward", this, &ABallChar::MoveForward);// Bind the MoveForward function to the "MoveForward" input axis
	PlayerInputComponent->BindAxis("MoveRight", this, &ABallChar::MoveRight);// Bind the MoveRight function to the "MoveRight" input axis
	PlayerInputComponent->BindAxis("MoveLeft", this, &ABallChar::MoveLeft);// Bind the MoveLeft function to the "MoveLeft" input axis
	PlayerInputComponent->BindAxis("MoveBackward", this, &ABallChar::MoveBackward);// Bind the MoveBackward function to the "MoveBackward" input axis
}

void ABallChar::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Forward = GetActorForwardVector() * Value * 10000.0f;// Calculate the forward movement vector based on the input value
		SphereComp->AddForce(Forward);// Apply the forward force to the sphere component
	}
}
void ABallChar::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Right = GetActorRightVector() * Value * 10000.0f;// Calculate the right movement vector based on the input value
		SphereComp->AddForce(Right);// Apply the right force to the sphere component
	}
}
void ABallChar::MoveLeft(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Left = -GetActorRightVector() * Value * 10000.0f;// Calculate the left movement vector based on the input value
		SphereComp->AddForce(Left);// Apply the left force to the sphere component
	}
}
void ABallChar::MoveBackward(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Backward = -GetActorForwardVector() * Value * 10000.0f;// Calculate the backward movement vector based on the input value
		SphereComp->AddForce(Backward);// Apply the backward force to the sphere component
	}
}