

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FrontendBlueprintFunctionLibrary.generated.h"

class UCommonActivatableWidgetBase;
/**
 * 
 */
UCLASS()
class FRONTEND_API UFrontendBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Frontend Function Library")
	static TSoftClassPtr<UCommonActivatableWidgetBase> GetFrontendSoftWidgetClassByTag(UPARAM(meta = (Categories = "Frontend.Widget")) FGameplayTag InWidgetTag);
	
};
