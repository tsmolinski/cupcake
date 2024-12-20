// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "CupcakeAINPCController.generated.h"

class UAISenseConfig_Touch;
class UAIPerceptionComponent;

UCLASS()
class CUPCAKE_API ACupcakeAINPCController : public AAIController
{
	GENERATED_BODY()
	
public:
	ACupcakeAINPCController();

	UAIPerceptionComponent* GetAIPerceptionComponent() const;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY()
	UAISenseConfig_Touch* TouchSenseConfig;

	UPROPERTY()
	UAIPerceptionComponent* AIPerceptionComponent;
};
