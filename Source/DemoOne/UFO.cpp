// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoOne.h"
#include "UFO.h"

// Sets default values
AUFO::AUFO()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Game/ThirdPersonBP/Meshes/CubeMesh"));

	this->SetRootComponent(mesh);

	mesh->SetStaticMesh(tempMesh.Object);

	mesh->OnComponentBeginOverlap.AddDynamic(this, &AUFO::Activate);
}

// Called when the game starts or when spawned
void AUFO::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUFO::Tick( float DeltaTime )
{	
	Super::Tick( DeltaTime );

	if (canMove)
	{
		auto currPos = GetActorLocation();

		auto nextPos = currPos + dir * speed * DeltaTime;

		double z = FMath::Sin(x) * 4;

		x += 0.1;

		SetActorLocation(nextPos);

		AddActorLocalOffset(FVector(.0f, .0f, z));
	}
}


void AUFO::Activate(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	canMove = true;
}




