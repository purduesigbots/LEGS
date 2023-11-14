#pragma once

#include "voss/controller/BoomerangController.hpp"

namespace voss::controller {

class BoomerangControllerBuilder {
private:
	controller::BoomerangController ctrl;

public:
	BoomerangControllerBuilder(std::shared_ptr<localizer::AbstractLocalizer> l);

	static BoomerangControllerBuilder
	newBuilder(std::shared_ptr<localizer::AbstractLocalizer> l);

	BoomerangControllerBuilder& withLinearConstants(double kP, double kI,
	                                                double kD);
	BoomerangControllerBuilder& withAngularConstants(double kP, double kI,
	                                                 double kD);
	BoomerangControllerBuilder& withTrackingKP(double kP);
	BoomerangControllerBuilder& withExitError(double error);
	BoomerangControllerBuilder& withAngularExitError(double error);
	BoomerangControllerBuilder& withMinError(double error);
	BoomerangControllerBuilder& withLeadPct(double lead_pct);

	BoomerangController build();
};

} // namespace voss::controller