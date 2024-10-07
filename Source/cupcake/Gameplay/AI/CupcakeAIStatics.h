// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CupcakeAIStatics.generated.h"

class ACupcakeAINPCController;

UCLASS()
class CUPCAKE_API UCupcakeAIStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//For some reason it doesn't work, it's probably bugged in this version of UE4
	UFUNCTION(BlueprintCallable, Category = "Game", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static void ReportTouchEvent(AActor* TouchReceiver, AActor* OtherActor, const FVector& EventLocation);
};
