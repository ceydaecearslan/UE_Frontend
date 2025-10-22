


#include "Widget/Components/FrontendCommonButtonBase.h"
#include "CommonTextBlock.h"
#include "Subsystem/FrontendUISubsystem.h"

void UFrontendCommonButtonBase::SetButtonText(const FText& InText)
{
	if (CommonTextBlock_ButtonText && !InText.IsEmpty())
	{
		CommonTextBlock_ButtonText->SetText(bUppercaseForButtonText ? InText.ToUpper() : InText);
	}
}

void UFrontendCommonButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetButtonText(ButtonDisplayText);
}

void UFrontendCommonButtonBase::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	if (CommonTextBlock_ButtonText && GetCurrentTextStyleClass())
	{
		CommonTextBlock_ButtonText->SetStyle(GetCurrentTextStyleClass());
	}
}

void UFrontendCommonButtonBase::NativeOnHovered()
{
	Super::NativeOnHovered();
	if (!ButtonDescriptionText.IsEmpty())
	{
		UFrontendUISubsystem::Get(this)->GetOnButtonDescriptionChanged().Broadcast(this, ButtonDescriptionText);
	}
}

void UFrontendCommonButtonBase::NativeOnUnhovered()
{
	Super::NativeOnUnhovered();
	UFrontendUISubsystem::Get(this)->GetOnButtonDescriptionChanged().Broadcast(this, FText::GetEmpty());
}
