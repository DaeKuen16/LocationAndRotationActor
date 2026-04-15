#include "Spawner.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	FVector movingPlatformLocation(FMath::RandRange(-500.0f, 500.0f),
		FMath::RandRange(-500.0f, 500.0f),
		100.0f
		);
	FVector randomPlatformLocation(FMath::RandRange(-500.0f, 500.0f),
		FMath::RandRange(-500.0f, 500.0f),
		100.0f
	);
	AA_TimerPlatform* SpawnedPlatform = GetWorld()->SpawnActor<AA_TimerPlatform>(platformClass, movingPlatformLocation, FRotator::ZeroRotator);
	AA_Random* SpawnedRandomPlatform = GetWorld()->SpawnActor<AA_Random>(randomPlatformClass, randomPlatformLocation, FRotator::ZeroRotator);
	if (SpawnedPlatform) {
		UE_LOG(LogTemp, Warning, TEXT("Spawn : %s"), *SpawnedPlatform->GetActorLocation().ToString());
	}
	if (SpawnedRandomPlatform) {
		UE_LOG(LogTemp, Warning, TEXT("Spawn : %s"), *SpawnedRandomPlatform->GetActorLocation().ToString());
	}
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

