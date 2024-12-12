// Fill out your copyright notice in the Description page of Project Settings.


#include "WoodenDoor.h"

#include "Lever.h"

// Sets default values
AWoodenDoor::AWoodenDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;
	Door1AttachPoint = CreateDefaultSubobject<USceneComponent>("Door1Attach");
	Door1AttachPoint->SetupAttachment(SceneRoot);
	Door2AttachPoint = CreateDefaultSubobject<USceneComponent>("Door2Attach");
	Door2AttachPoint->SetupAttachment(SceneRoot);
	Door1 = CreateDefaultSubobject<UStaticMeshComponent>("Door1");
	Door1->SetupAttachment(Door1AttachPoint);
	Door2 = CreateDefaultSubobject<UStaticMeshComponent>("Door2");
	Door2->SetupAttachment(Door2AttachPoint);
	

}

// Called when the game starts or when spawned
void AWoodenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWoodenDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AWoodenDoor::RedisterLever(int Id)
{
	ActivationOrder.Add(Id);
	if (ActivationOrder.Num() == CorrectOrder.Num())
	{
		if (ActivationOrder[0] == CorrectOrder[0] && ActivationOrder[1] == CorrectOrder[1] &&ActivationOrder[2] == CorrectOrder[2] &&ActivationOrder[3] == CorrectOrder[3] )
		{
			this->Destroy();
		}
		else
		{
			ActivationOrder.Empty();
			for (const auto x : AllLevers)
			{
				x->ResetLever();
			}
		}
			
	}
}



