

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MVVMPressAnyKey.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPressAnyKeyDetected);

/**
 * 
 */
UCLASS()
class FRONTEND_API UMVVMPressAnyKey : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	void DetectPressAnyKey()
	{
		if (OnPressAnyKeyDetected.IsBound())
		{
			OnPressAnyKeyDetected.Broadcast();
		}
	}
	
	FOnPressAnyKeyDetected* GetOnPressAnyKeyDetectedDelegate()
	{
		return &OnPressAnyKeyDetected;
	}
	
private:

	FOnPressAnyKeyDetected OnPressAnyKeyDetected;
	
};
