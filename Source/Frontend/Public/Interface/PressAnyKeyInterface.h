// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PressAnyKeyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPressAnyKeyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FRONTEND_API IPressAnyKeyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void OnPressAnyKeyCreated(TFunction<void ()> FunctionToBind) = 0;
	
};
