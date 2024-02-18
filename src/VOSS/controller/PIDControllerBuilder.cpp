#include "VOSS/controller/PIDControllerBuilder.hpp"

#include <utility>
#include "VOSS/controller/PIDController.hpp"
#include "VOSS/localizer/AbstractLocalizer.hpp"
#include "VOSS/utils/angle.hpp"

namespace voss::controller {

PIDControllerBuilder::PIDControllerBuilder(
    std::shared_ptr<localizer::AbstractLocalizer> l)
    : ctrl(std::move(l)) {
}

PIDControllerBuilder PIDControllerBuilder::new_builder(
    std::shared_ptr<localizer::AbstractLocalizer> l) {
    PIDControllerBuilder builder(std::move(l));
    return builder;
}

PIDControllerBuilder&
PIDControllerBuilder::with_linear_constants(double kP, double kI, double kD) {
    this->ctrl.linear_kP = kP;
    this->ctrl.linear_kI = kI;
    this->ctrl.linear_kD = kD;
    return *this;
}

PIDControllerBuilder&
PIDControllerBuilder::with_angular_constants(double kP, double kI, double kD) {
    this->ctrl.angular_kP = kP;
    this->ctrl.angular_kI = kI;
    this->ctrl.angular_kD = kD;
    return *this;
}

PIDControllerBuilder& PIDControllerBuilder::with_tracking_kp(double kP) {
    this->ctrl.tracking_kP = kP;
    return *this;
}

PIDControllerBuilder& PIDControllerBuilder::with_exit_error(double error) {
    this->ctrl.exit_error = error;
    return *this;
}

PIDControllerBuilder&
PIDControllerBuilder::with_angular_exit_error(double error) {
    this->ctrl.angular_exit_error = voss::to_radians(error);
    return *this;
}

PIDControllerBuilder& PIDControllerBuilder::with_min_error(double error) {
    this->ctrl.min_error = error;
    return *this;
}

PIDControllerBuilder& PIDControllerBuilder::with_settle_time(double time) {
    this->ctrl.settle_time = (time > 0) ? time : 250;
    return *this;
}

std::shared_ptr<PIDController> PIDControllerBuilder::build() {
    return std::make_shared<PIDController>(this->ctrl);
}

} // namespace voss::controller