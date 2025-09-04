// Fill out your copyright notice in the Description page of Project Settings.


#include "BouncyPaddie.h"

// Sets default values
ABouncyPaddie::ABouncyPaddie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABouncyPaddie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABouncyPaddie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

