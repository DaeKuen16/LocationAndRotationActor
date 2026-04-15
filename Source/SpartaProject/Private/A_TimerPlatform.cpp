// Fill out your copyright notice in the Description page of Project Settings.


#include "A_TimerPlatform.h"

// Sets default values
AA_TimerPlatform::AA_TimerPlatform()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(RootScene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootScene);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile"));
	if (MaterialAsset.Succeeded()) {
		StaticMesh->SetMaterial(0, MaterialAsset.Object);
	}
	Direction = FVector(1.0f, 0.0f, 0.0f);
	moveSpeed = 300.0f;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AA_TimerPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	GetWorld()->GetTimerManager().SetTimer(
		TimeHandler,
		this,
		&AA_TimerPlatform::MoveActor,
		0.01f,
		true
	);
}

// Called every frame
void AA_TimerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA_TimerPlatform::MoveActor() {
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	AddActorWorldOffset(Direction * moveSpeed * DeltaTime);

	float Distance = FVector::Dist(StartLocation, GetActorLocation());

	if (Distance >= 300.0f) {//변수로 바꾸면 됨
		GetWorld()->GetTimerManager().ClearTimer(TimeHandler);
		GetWorld()->GetTimerManager().SetTimer(
			TimeHandler,
			this,
			&AA_TimerPlatform::RemoveActor,
			5.0f,
			false
		);
	}
}

void AA_TimerPlatform::RemoveActor() {
	Destroy();
}