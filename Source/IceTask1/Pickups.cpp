// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"         // Needed for UBoxComponent
#include "Components/StaticMeshComponent.h"   // Needed for the mesh
#include "Kismet/GameplayStatics.h"           // Needed for ApplyDamage or utility functions
//#include "bpi_Healthreciever.h"
// Sets default values
APickups::APickups()
{
	PrimaryActorTick.bCanEverTick = true; // Disable ticking for this actor
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneRoot; // Set the scene component as the root	

	//Createe and initialize the collision component
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Set the radius of the sphere
	CollisionComponent->bGenerateOverlapEvents = true; // Enable overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &APickups::OnOverlapBegin); // Bind the overlap event
	CollisionComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Create and attach the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}
	// Called when the game starts
	void APickups::BeginPlay()
	{
		Super::BeginPlay();
	}
	// Called when another actor overlaps the collision sphere
	void APickups::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
	{
		Destroy();
	}



