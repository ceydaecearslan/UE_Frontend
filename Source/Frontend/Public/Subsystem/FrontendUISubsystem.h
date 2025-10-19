

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendUISubsystem.generated.h"

class UCommonActivatableWidgetBase;
struct FGameplayTag;
class UPrimaryLayout;

enum class EAsyncPushWidgetState : uint8
{
	OnCreatedBeforePush,
	AfterPush
};

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

private:

	UPROPERTY(Transient)
	TObjectPtr<UPrimaryLayout> CreatedPrimaryLayout;
};
