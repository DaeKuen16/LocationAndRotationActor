// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void AItem::BeginPlay() {
	Super::BeginPlay();

	OnItemPickedUp();
}

void AItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime,0.0f, 0.0f));
	}
}

void AItem::ResetActorPosition() {
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const {
	return RotationSpeed;
}