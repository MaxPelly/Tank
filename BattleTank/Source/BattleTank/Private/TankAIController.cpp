// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* Tank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO Move towards the player
		
		// Aim towards the player
		Tank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready

		Tank->Fire();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai failed to get player"))
	}
}

