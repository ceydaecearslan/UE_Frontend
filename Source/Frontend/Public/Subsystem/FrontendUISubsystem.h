

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendUISubsystem.generated.h"

class UFrontendCommonButtonBase;
class UCommonActivatableWidgetBase;
struct FGameplayTag;
class UPrimaryLayout;

enum class EAsyncPushWidgetState : uint8
{
	OnCreatedBeforePush,
	AfterPush
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonDescriptionChangedSignature, UFrontendCommonButtonBase*, BroadcastingButton, FText, DescriptionText);

/**
 * 
 */
UCLASS()
class FRONTEND_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	static UFrontendUISubsystem* Get(const UObject* WorldContextObject);

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	UFUNCTION()
	void RegisterCreatedPrimaryLayoutWidget(UPrimaryLayout* PrimaryLayout);

	void PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag, TSoftClassPtr<UCommonActivatableWidgetBase> InSoftWidgetClass,
		TFunction<void (EAsyncPushWidgetState, UCommonActivatableWidgetBase*)> AsyncPushStateCallback);

	FOnButtonDescriptionChangedSignature GetOnButtonDescriptionChanged()
	{
		return OnButtonDescriptionChanged;
	}

private:

	UPROPERTY(Transient)
	TObjectPtr<UPrimaryLayout> CreatedPrimaryLayout;

	UPROPERTY(BlueprintAssignable)
	FOnButtonDescriptionChangedSignature OnButtonDescriptionChanged;
};
