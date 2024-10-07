// Fill out your copyright notice in the Description page of Project Settings.


#include "CupcakeNPCCharacter.h"
#include "../Gameplay/AI/CupcakeAIStatics.h"
#include "Components/CapsuleComponent.h"
#include "../Controller/AI/CupcakeAINPCController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AIPerceptionComponent.h"
//
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Touch.h"

// Sets default values
ACupcakeNPCCharacter::ACupcakeNPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACupcakeNPCCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ACupcakeNPCCharacter::OnHit);
	
}

void ACupcakeNPCCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UCupcakeAIStatics::ReportTouchEvent(this, OtherActor, Hit.ImpactPoint);

	FAITouchEvent TouchEvent(this, OtherActor, Hit.ImpactPoint);
	UAISense_Touch* TouchSense = NewObject<UAISense_Touch>(this, TEXT("TouchSense"));

	ACupcakeAINPCController* AIController = Cast<ACupcakeAINPCController>(this->GetController());
	if (AIController)
	{
		FAIStimulus TouchStimulus(*TouchSense, 1.f, Hit.ImpactPoint, this->GetActorLocation());
		UAIPerceptionComponent* AIPerceptionComponent = AIController->GetAIPerceptionComponent();
		AIPerceptionComponent->OnTargetPerceptionUpdated.Broadcast(OtherActor, TouchStimulus);
	}
}

// Called every frame
void ACupcakeNPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACupcakeNPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

