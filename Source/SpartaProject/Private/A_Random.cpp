#include "A_Random.h"

// Sets default values
AA_Random::AA_Random()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(RootScene);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(RootScene);

	vectorLocation = FVector(FMath::RandRange(-1.0f, 1.0f),
		FMath::RandRange(-1.0f, 1.0f),
		FMath::RandRange(-1.0f, 1.0f)
	);
	RotationSpeed = FMath::RandRange(90.0f, 180.0f);
	moveSpeed = 100.0f;
	randomMoveLocation = true;
	randomMoveRotation = true;
	//randomLocation = (FMath::RandRange())
	PrimaryActorTick.bCanEverTick = false;
}

void AA_Random::BeginPlay()
{
	Super::BeginPlay();
	if (randomMoveLocation) {
		GetWorld()->GetTimerManager().SetTimer(
			moveLocationTimeHandler,
			this,
			&AA_Random::randomMove,
			0.01f,
			true
		);
	}
	if (randomMoveRotation) {
		GetWorld()->GetTimerManager().SetTimer(
			moveRotationTimeHandler,
			this,
			&AA_Random::randomRotation,
			0.01f,
			true
		);
	}
}

void AA_Random::randomMove() {
	float moveLocationDeltaTime = GetWorld()->GetDeltaSeconds();
	AddActorWorldOffset(moveLocationDeltaTime * moveSpeed * vectorLocation);
}

void AA_Random::randomRotation() {
	float moveRotationDeltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(RotationSpeed * moveRotationDeltaTime, 0.0f, 0.0f));
}
