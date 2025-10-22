// 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidgetBase.h"
#include "Interface/PressAnyKeyInterface.h"
#include "PressAnyKeyWidget.generated.h"

class UMVVMPressAnyKey;
/**
 * 
 */
UCLASS()
class FRONTEND_API UPressAnyKeyWidget : public UCommonActivatableWidgetBase, public IPressAnyKeyInterface
{
	GENERATED_BODY()

public:

	virtual void OnPressAnyKeyCreated(TFunction<void ()> FunctionToBind) override;

	TObjectPtr<UMVVMPressAnyKey> GetViewModelPressAnyKey();

protected:

	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	void CreateViewModel();

	UPROPERTY(BlueprintReadOnly, FieldNotify, Category="ViewModel")
	TObjectPtr<UMVVMPressAnyKey> MVVMPressAnyKey;
};
