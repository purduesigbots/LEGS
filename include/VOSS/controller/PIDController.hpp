#pragma once

#include "VOSS/controller/AbstractController.hpp"
#include <memory>

namespace voss::controller {

class PIDController : public AbstractController {
  protected:
    std::shared_ptr<PIDController> p;

    double linear_kP, linear_kI, linear_kD;
    double angular_kP, angular_kI, angular_kD;
    double tracking_kP;
    double exit_error;
    double angular_exit_error;
    double min_error;
    double can_reverse;
    double settle_time;

    double close;
    double close_2;
    int counter;
    double prev_angle;

    double prev_lin_err, total_lin_err, prev_ang_err, total_ang_err;

  public:
    PIDController(std::shared_ptr<localizer::AbstractLocalizer> l);

    double linear_pid(double error);
    double angular_pid(double error);

    chassis::ChassisCommand get_command(bool reverse, bool thru) override;
    chassis::ChassisCommand get_angular_command(bool reverse,
                                                bool thru) override;

    void reset() override;

    std::shared_ptr<PIDController> modify_linear_constants(double kP, double kI,
                                                           double kD);
    std::shared_ptr<PIDController>
    modify_angular_constants(double kP, double kI, double kD);
    std::shared_ptr<PIDController> modify_tracking_kp(double kP);
    std::shared_ptr<PIDController> modify_exit_error(double exit_error);
    std::shared_ptr<PIDController> modify_angular_exit_error(double exit_error);
    std::shared_ptr<PIDController> modify_min_error(double min_error);
    std::shared_ptr<PIDController> modify_settle_time(double settle_time);

    friend class PIDControllerBuilder;
    friend class BoomerangControllerBuilder;
};

} // namespace voss::controller