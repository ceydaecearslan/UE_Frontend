// 


#include "Widget/PressAnyKeyWidget.h"

#include "ViewModel/MVVMPressAnyKey.h"

void UPressAnyKeyWidget::OnPressAnyKeyCreated(TFunction<void ()> FunctionToBind)
{
	MVVMPressAnyKey->GetOnPressAnyKeyDetectedDelegate()->AddLambda(FunctionToBind);
}

TObjectPtr<UMVVMPressAnyKey> UPressAnyKeyWidget::GetViewModelPressAnyKey()
{
	return MVVMPressAnyKey;
}

void UPressAnyKeyWidget::NativeConstruct()
{
	Super::NativeConstruct();
	CreateViewModel();
}

FReply UPressAnyKeyWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	MVVMPressAnyKey->DetectPressAnyKey();
	return FReply::Handled();
} 

FReply UPressAnyKeyWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	MVVMPressAnyKey->DetectPressAnyKey();
	return FReply::Handled();
}

void UPressAnyKeyWidget::CreateViewModel()
{
	MVVMPressAnyKey = NewObject<UMVVMPressAnyKey>(this, FName("ViewModel"));
}
