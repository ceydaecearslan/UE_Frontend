

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Widget/CommonWidgetBase.h"
#include "PrimaryLayout.generated.h"

class UCommonActivatableWidgetContainerBase;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class FRONTEND_API UPrimaryLayout : public UCommonWidgetBase
{
	GENERATED_BODY()

public:

	TObjectPtr<UCommonActivatableWidgetContainerBase> FindWidgetStackByTag(const FGameplayTag& InTag) const;
	
protected:

	UFUNCTION(BlueprintCallable)
	void RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InWidgetStack);
	
private:

	UPROPERTY(Transient)
	TMap<FGameplayTag, UCommonActivatableWidgetContainerBase*> RegisteredWidgetStackMap;
	
};
