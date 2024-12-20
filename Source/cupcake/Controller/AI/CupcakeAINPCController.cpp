// Fill out your copyright notice in the Description page of Project Settings.


#include "CupcakeAINPCController.h"
#include "Perception/AISenseConfig_Touch.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense_Touch.h"

// Sets default values
ACupcakeAINPCController::ACupcakeAINPCController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
}

UAIPerceptionComponent* ACupcakeAINPCController::GetAIPerceptionComponent() const
{
	return FindComponentByClass<UAIPerceptionComponent>();
}

// Called when the game starts or when spawned
void ACupcakeAINPCController::BeginPlay()
{
	Super::BeginPlay();

	AIPerceptionComponent = FindComponentByClass<UAIPerceptionComponent>();

	if(AIPerceptionComponent)
	{
		TouchSenseConfig = NewObject<UAISenseConfig_Touch>(this, TEXT("TouchSenseConfig"));

		if (TouchSenseConfig)
		{
			AIPerceptionComponent->ConfigureSense(*TouchSenseConfig);
		}

		AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ACupcakeAINPCController::PerceptionUpdated);
	}
}

void ACupcakeAINPCController::PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		if (Stimulus.Type == UAISense::GetSenseID<UAISense_Touch>())
		{
			UE_LOG(LogTemp, Warning, TEXT("PerceptionUpdated Call!"));
		}
	}
}