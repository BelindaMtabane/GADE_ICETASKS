// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BallChar.generated.h"

UCLASS()
class ICETASK1_API ABallChar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABallChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)// EditAnywhere allows this property to be edited in the Unreal Editor
		class USphereComponent* SphereComp;// Sphere component for collision detection

	UPROPERTY(EditAnywhere)// EditAnywhere allows this property to be edited in the Unreal Editor
		class UStaticMeshComponent* MeshComp;// Static mesh component for visual representation

	UPROPERTY(EditAnywhere)// Movement component for handling movement logic	
		class UFloatingPawnMovement* MovementComp;// Floating pawn movement component	

	void MoveForward(float Value);// Function to move the pawn forward
	void MoveRight(float Value);// Function to move the pawn right
	void MoveLeft(float Value);// Function to move the pawn left
	void MoveBackward(float Value);// Function to move the pawn backward
	void Jump();// Function to make the pawn jump



};
