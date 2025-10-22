

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FrontendCommonButtonBase.generated.h"

class UCommonTextBlock;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class FRONTEND_API UFrontendCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetButtonText(const FText& InText);
	
protected:

	virtual void NativePreConstruct() override;
	virtual void NativeOnCurrentTextStyleChanged() override;
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;
	
	UPROPERTY(meta=(BindWidgetOptional))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend|Button")
	FText ButtonDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend|Button")
	bool bUppercaseForButtonText = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend|Button")
	FText ButtonDescriptionText;
	
};
