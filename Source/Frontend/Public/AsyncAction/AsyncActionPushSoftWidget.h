

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncActionPushSoftWidget.generated.h"

struct FGameplayTag;
class UCommonActivatableWidgetBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPushSoftWidgetDelegate, UCommonActivatableWidgetBase*, PushedWidget);
/**
 * 
 */
UCLASS()
class FRONTEND_API UAsyncActionPushSoftWidget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", HidePin = "WorldContextObject", BlueprintInternalUseOnly = true, DisplayName ="Push Soft Widget To Widget Stack"))
	static UAsyncActionPushSoftWidget* PushSoftWidget(UObject* WorldContextObject, APlayerController* OwningPlayerController,
		TSoftClassPtr<UCommonActivatableWidgetBase> InSoftWidgetClass, UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InWidgetStackTag,
		bool bFocusOnNewlyPushedWidget = true);

	UPROPERTY(BlueprintAssignable)
	FOnPushSoftWidgetDelegate OnWidgetCreatedBeforePush;
	
	UPROPERTY(BlueprintAssignable)
	FOnPushSoftWidgetDelegate OnAfterPush;

private:

	TWeakObjectPtr<UWorld> CachedOwningWorld;
	TWeakObjectPtr<APlayerController> CachedOwningPlayerController;
	TSoftClassPtr<UCommonActivatableWidgetBase> CachedSoftWidgetClass;
	FGameplayTag CachedWidgetStackTag;
	bool bCachedFocusOnNewlyPushedWidget = false;
};
