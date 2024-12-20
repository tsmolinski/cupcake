// Fill out your copyright notice in the Description page of Project Settings.


#include "CupcakeAIStatics.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Touch.h"
#include "Kismet/GameplayStatics.h"

//For some reason it doesn't work, it's probably bugged in this version of UE4
void UCupcakeAIStatics::ReportTouchEvent(AActor* TouchReceiver, AActor* OtherActor, const FVector& EventLocation)
{
	if (TouchReceiver)
	{
		UAIPerceptionSystem* AIPerceptionSystem = UAIPerceptionSystem::GetCurrent(TouchReceiver);
		if (AIPerceptionSystem)
		{
			FAITouchEvent TouchEvent(TouchReceiver, OtherActor, EventLocation);
			AIPerceptionSystem->OnEvent(TouchEvent);
		}
	}
}
