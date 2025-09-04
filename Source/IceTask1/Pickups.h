// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" //pickups should inherit from AActor
#include "Pickups.generated.h" // This should be the last include in the header file

class UBoxComponent; // Forward declaration of UBoxComponent
UCLASS()
class ICETASK1_API APickups : public AActor
{
	GENERATED_BODY()// This macro is required for all classes that will be used in Unreal Engine
	
public:	
	// Constructors
	APickups();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Components
	UPROPERTY(EditAnywhere)
	USphereComponent* CollisionComponent; // Sphere component for collision detection

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent; // Static mesh component for the pickup item

	//UPROPERTY(EditAnywhere, Category = "Pickup")// Amount of health this pickup gives
	//float healthValue = 25.0f; // Name of the pickup item

	UPROPERTY(EditAnywhere)
	USceneComponent* SceneRoot; // Scene component to serve as the root

	UFUNCTION()// Function called when something overlaps the collision sphere
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
					UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
					bool bFromSweep, const FHitResult& SweepResult);

};
