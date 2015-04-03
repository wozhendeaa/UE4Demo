// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoOne.h"
#include "UFO.h"
#include <cmath>

// Sets default values
AUFO::AUFO()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

	auto currPos = GetActorLocation();

	auto nextPos = currPos + dir * speed * DeltaTime;

	double z = std::sin(x) * 10;

	x += 0.1;

	SetActorLocation(nextPos);

	AddActorLocalOffset(FVector(.0f, .0f, z));
}

