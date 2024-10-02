// Fill out your copyright notice in the Description page of Project Settings.


#include "CupcakeNPCCharacter.h"

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

	USkeletalMeshComponent* NPCMesh = GetMesh();
	if (NPCMesh)
	{
		NPCMesh->OnComponentHit.AddDynamic(this, &ACupcakeNPCCharacter::OnHit);
	}
	
}

void ACupcakeNPCCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnHitCalled!"));

	
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

