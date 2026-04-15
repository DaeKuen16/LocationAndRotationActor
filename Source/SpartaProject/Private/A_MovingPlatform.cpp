// Fill out your copyright notice in the Description page of Project Settings.


#include "A_MovingPlatform.h"

// Sets default values
AA_MovingPlatform::AA_MovingPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	moveSpeed = 30.0f;
	maxRange = 1000.0f;
	Direction = FVector(1.0f, 1.0f, 0.0f);
}

// Called when the game starts or when spawned
void AA_MovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Start Location : %s"), *startLocation.ToString());
}

// Called every frame
void AA_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector currentLocation = GetActorLocation();
	float Distance = FVector::Dist(startLocation, currentLocation);

	if (maxRange >= Distance) {
		FVector DeltaMove = Direction * moveSpeed * DeltaTime;
		AddActorWorldOffset(DeltaMove);
	}

	if (Distance >= maxRange) {
		//UE_LOG(LogTemp, Warning, TEXT("Finish Location : %s"), *currentLocation.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Distance : %f"), Distance);
		Direction *= -1;
		startLocation = currentLocation;
	}
}

